#include "Lista.cpp"

int main() {
    cout << "Polinomio 1" << endl;
    Lista<Termino> polinomio1;
    polinomio1.almacenarArchivo("polinomio1.txt", &polinomio1);
    polinomio1.print();

    cout << endl << "Polinomio 2" << endl;
    Lista<Termino> polinomio2;
    polinomio2.almacenarArchivo("polinomio2.txt", &polinomio2);
    polinomio2.print();

    Lista<Termino> resultadoSuma, resultadoResta;
    cout << endl << "Suma" << endl;
    resultadoSuma.sumaPolinomios(&polinomio1,&polinomio2);
    resultadoSuma.print();

    cout << endl << "Resta" << endl;
    resultadoResta.restaPolinomios(&polinomio1,&polinomio2);
    resultadoResta.print();
    return 0;
}


