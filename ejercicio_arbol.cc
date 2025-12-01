#include <iostream>

struct Tiobe{
    std::string lenguaje_programacion;
    float puntaje;
};

struct Nodo{
    struct Tiobe indice_tiobe;
    struct Nodo *izquierdo;
    struct Nodo *derecho;
};

struct Nodo *crear_nodo(const Tiobe &informacion);
void insertar_nodo(Nodo *&abb, const Tiobe &informacion);

int main(){

    return 0;
}

Nodo *crear_nodo(const Tiobe &indice)
{
    Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->indice_tiobe = indice;
    nuevo_nodo->izquierdo = nullptr;
    nuevo_nodo->derecho = nullptr;
    return nuevo_nodo;
}
void insertar_nodo(Nodo *&abb, const InformacionAcademica &indice)
{
    if (abb == nullptr)
    {
        abb = crear_nodo(indice);
        return;
    }

    if (informacion.cum < abb->indice_tiobe.puntaje)
        insertar_nodo(abb->izquierdo, indice);
    else
        insertar_nodo(abb->derecho, indice);
}