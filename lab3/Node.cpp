#include "Node.h"

int Termino::getCoeficiente() {
    return coeficiente;
}

void Termino::setCoeficiente(int coeficiente) {
    Termino::coeficiente = coeficiente;
}

int Termino::getExponente() {
    return exponente;
}

void Termino::setExponente(int exponente) {
    Termino::exponente = exponente;
}

Termino::Termino(int coeficiente, int exponente) : coeficiente(coeficiente), exponente(exponente) {}

Termino::Termino():coeficiente(0),exponente(0){}
