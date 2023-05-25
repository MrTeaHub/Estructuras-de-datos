#ifndef LAB5_ESTUDIANTE_H
#define LAB5_ESTUDIANTE_H

#include "Lista.h"

class Estudiante {
private:
    string nombre;
public:
    Lista<float> notas;

    string getNombre();

    void setNombre(string nombre);
};


#endif //LAB5_ESTUDIANTE_H
