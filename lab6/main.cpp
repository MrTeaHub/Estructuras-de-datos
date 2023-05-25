#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>
#include "ArbolBinario.cpp"
#include "Pila.cpp"

using namespace std;

vector<string> descomponerString(vector<string> &expresion, int posicion) {
    string simbolo = expresion[posicion], caracter;
    vector<string> simbolos;
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < simbolo.length(); j++) {
            caracter = simbolo[j];
            //verifico si es un digito
            if(isdigit(simbolo[j])){
                //Y si el que sigue tambien lo es lo guarde como un mismo numero
                while (isdigit(simbolo[j+1])){
                    caracter += simbolo[j+1];
                    j++;
                }
            }
            simbolos.push_back(caracter);
        }
    }
    return simbolos;
}

void almacenarArchivo(string Archivo, vector<vector<string>> *expresiones) {
    ifstream archivo(Archivo);
    vector<string> exp;
    string linea, expresion;
    int posicion = 0;
    //archivo es el objeto a leer y linea es la variable donde se va a guardar lo leido
    //getline puede recibir 3 parametros, el primero recibe lo que se va a leer, el segundo donde se
    // a almacenar lo leido y el tercero lo que le dice hasta donde leer en la linea
    while (getline(archivo, linea)) {
        //stream recibe la primera linea del .txt
        stringstream stream(linea);
        getline(stream, expresion);
        exp.push_back(expresion);
        expresiones->push_back(descomponerString(exp,posicion));
        posicion++;
    }
    archivo.close();
}

template<typename T>
void guardarArchivo(vector<T> resultado, string nombre){
    ofstream file;
    //creo el .txt
    file.open(nombre);
    for (int i = 0; i < resultado.size(); i++) { // guardo lo que hay dentro del vector
        file << resultado[i] << endl;
    }
    file.close();
}

float evaluar(NodeArbol<string>* node){
    NodeArbol<string>* left = node->left;
    NodeArbol<string>* right = node->right;

    if (left && right){
        string operador = node->data;
        if(operador == "+") return (evaluar(left) + evaluar(right));
        if(operador == "-") return (evaluar(left) - evaluar(right));
        if(operador == "*") return (evaluar(left) * evaluar(right));
        if(operador == "/") return (evaluar(left) / evaluar(right));
    }
    else {
        return stof(node->data);
    }
}

void expresionMatematica(vector<string> listaSimbolos, vector<float> &resultados){
    ArbolBinario<string> arbolExpresion("");
    Pila<NodeArbol<string>*> pilaPadres;
    NodeArbol<string>* nodoActual = arbolExpresion.getRootValue();
    pilaPadres.push(nodoActual);

    for (string i : listaSimbolos) {
        if(i == "("){
            nodoActual->insertLeft("");
            pilaPadres.push(nodoActual);
            nodoActual = nodoActual->left;
        }
        else if(i != "-" && i != "+" && i != "*" && i != "/" && i != ")"){
            nodoActual->data = i;
            NodeArbol<string>* padre = pilaPadres.top();
            pilaPadres.pop();
            nodoActual = padre;
        }
        else if(i == "+" || i == "-" || i == "*" || i == "/"){
            nodoActual->data = i;
            nodoActual->insertRight("");
            pilaPadres.push(nodoActual);
            nodoActual = nodoActual->right;
        }
        else if(i == ")"){
            nodoActual = pilaPadres.top();
            pilaPadres.pop();
        }
        else {
            cout << "Error!" << endl;
        }
    }
    resultados.push_back(round(evaluar(arbolExpresion.getRootValue())*10)/10);
    cout << "Resultado: " << round(evaluar(arbolExpresion.getRootValue())*10)/10 << endl;
}

bool evaluarBoolean(NodeArbol<string>* node){
    NodeArbol<string>* left = node->left;
    NodeArbol<string>* right = node->right;
    string operador = node->data;
    // ^ es and, v es or y ~ es not
    if (left && right){
        if(operador == "^") return (evaluarBoolean(left) && evaluarBoolean(right));
        if(operador == "v") return (evaluarBoolean(left) || evaluarBoolean(right));
    }
    else if(left){
        return (!evaluarBoolean(left));
    }
    else {
        return !(node->data == "0");
    }
}

void expresionBooleana(vector<string> listaSimbolos, vector<bool> &resultados){
    ArbolBinario<string> arbolExpresion("");
    Pila<NodeArbol<string>*> pilaPadres;
    NodeArbol<string>* nodoActual = arbolExpresion.getRootValue();
    pilaPadres.push(nodoActual);

    for (string i : listaSimbolos) {
        if(i == "("){
            nodoActual->insertLeft("");
            pilaPadres.push(nodoActual);
            nodoActual = nodoActual->left;
        }
        else if(i == "~"){
            nodoActual->data = i;
            nodoActual->insertLeft("");
            pilaPadres.push(nodoActual);
            nodoActual = nodoActual->left;
        }
        else if((nodoActual->data == "~") && (i == "v" || i == "^")){
            nodoActual = pilaPadres.top();
            pilaPadres.pop();
            nodoActual->data = i;
            nodoActual->insertRight("");
            pilaPadres.push(nodoActual);
            nodoActual = nodoActual->right;
        }
        else if(i != "v" && i != "^" && i != ")"){
            nodoActual->data = i;
            NodeArbol<string>* padre = pilaPadres.top();
            pilaPadres.pop();
            nodoActual = padre;
        }
        else if(i == "v" || i == "^"){
            nodoActual->data = i;
            nodoActual->insertRight("");
            pilaPadres.push(nodoActual);
            nodoActual = nodoActual->right;
        }
        else if(i == ")"){
            nodoActual = pilaPadres.top();
            pilaPadres.pop();
        }
        else {
            cout << "Error!" << endl;
        }
    }
    resultados.push_back(evaluarBoolean(arbolExpresion.getRootValue()));
    //cout << "Resultado: " << evaluarBoolean(arbolExpresion.getRootValue()) << endl;
}

template<typename T>
void imprimirTabla(const vector<vector<string>>& listaSimbolos, const vector<T>& resultados) {
    cout << setw(50) << left << "Expresion" << "Resultado" << endl;
    cout << setfill('_') << setw(60) << "_" << endl;
    cout << setfill(' ');
    string expresion;
    for (int i = 0; i <resultados.size() ; ++i) {
        for (int j = 0; j <listaSimbolos[i].size() ; ++j) {
            expresion=expresion+listaSimbolos[i][j];
        }
        cout << setw(50) << left << expresion;
        cout << resultados[i] << endl;
        expresion="";
    }

}


int main() {
    vector<vector<string>> listaSimbolos, listaBoolean;
    vector<float> resultados;
    vector<bool> resultadosBool;
    almacenarArchivo("expresiones.txt", &listaSimbolos);
    almacenarArchivo("expresionesBoolen.txt", &listaBoolean);

    cout << "Resultados expresiones matematicas: " << endl;
    for (int i = 0; i < listaSimbolos.size(); i++) {
        expresionMatematica(listaSimbolos[i], resultados);
    }
    guardarArchivo(resultados, "resultados.txt");

    cout << endl << "Resultados expresiones booleanas: " << endl;
    for (int i = 0; i < listaBoolean.size(); i++) {
        expresionBooleana(listaBoolean[i], resultadosBool);
    }
    imprimirTabla(listaBoolean,resultadosBool);
    guardarArchivo(resultadosBool, "resultadosBool.txt");

    return 0;
}
