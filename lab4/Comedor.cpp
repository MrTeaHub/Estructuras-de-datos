#include "Comedor.h"

Comedor::Comedor(int servicio): tasaServicio(servicio), estudianteActual(nullptr), tiempoRestante(0){}

void Comedor::ticTac() {
    if(estudianteActual != nullptr){
        tiempoRestante--;
        if(tiempoRestante == 0) estudianteActual = nullptr;
    }
}

bool Comedor::ocupada() {
    if(estudianteActual != nullptr) return true;
    return false;
}

void Comedor::iniciarNueva(Estudiante *nuevoEstudiante) {
    estudianteActual = nuevoEstudiante;
    tiempoRestante = tasaServicio;
}
