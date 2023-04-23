#ifndef LISTAS_NODE_H
#define LISTAS_NODE_H

class Termino {
private:
    int coeficiente, exponente;
public:
    Termino();
    Termino(int coeficiente, int exponente);

    int getCoeficiente();

    void setCoeficiente(int coeficiente);

    int getExponente() ;

    void setExponente(int exponente);
};

struct Node {
    Termino data; // data es el objeto termino, este contiene dos atributos
    Node* next;
};


#endif //LISTAS_NODE_H
