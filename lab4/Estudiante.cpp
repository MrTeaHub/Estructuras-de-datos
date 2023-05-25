#include "Estudiante.h"

Estudiante::Estudiante():marcaTiempo(0) {}

Estudiante::Estudiante(int tiempo):marcaTiempo(tiempo){}

int Estudiante::obtenerMarca() {
    return marcaTiempo;
}

int Estudiante::tiempoEspera(int tiempoActual) {
    return tiempoActual - marcaTiempo;
}




