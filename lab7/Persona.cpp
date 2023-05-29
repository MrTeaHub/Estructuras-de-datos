#include <iostream>

using  namespace std;

class Persona {
private:
    string nombre, telefono;
public:
    Persona():nombre(""), telefono(""){}
    Persona(string nombre, string telefono): nombre(nombre), telefono(telefono){}

    string getNombre() {
        return nombre;
    }

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    string getTelefono() {
        return telefono;
    }

    void setTelefono(string telefono) {
        this->telefono = telefono;
    }
};