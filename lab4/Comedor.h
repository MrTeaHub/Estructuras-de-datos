#ifndef LAB4_COMEDOR_H
#define LAB4_COMEDOR_H

#include "Estudiante.h"

class Comedor {
    private:
        int tasaServicio,tiempoRestante;
        Estudiante *estudianteActual;
    public:
        Comedor(int servicio);
        void ticTac();
        bool ocupada();
        void iniciarNueva(Estudiante *nuevoEstudiante);
};


#endif //LAB4_COMEDOR_H
