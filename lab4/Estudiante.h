#ifndef LAB4_ESTUDIANTE_H
#define LAB4_ESTUDIANTE_H


class Estudiante {
private:
    int marcaTiempo;
public:
    Estudiante();
    Estudiante(int tiempo);
    int obtenerMarca();
    int tiempoEspera(int tiempoActual);
};


#endif //LAB4_ESTUDIANTE_H
