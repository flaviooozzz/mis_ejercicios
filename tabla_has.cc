#include <iostream>

const int kdimension = 7;

struct Registro {
    int dato;
};

struct Nodo {
    Registro registro;
    Nodo *anterior;
    Nodo *siguiente;
};

Nodo *tabla[kdimension] = {nullptr};

void Agregar(char);
int FHash(int);
int ConversionASCII(char);
Nodo *Buscar(int, int);
void Buscar(int);
void Eliminar(int);
void Imprimir();

int main() {
  
    Agregar('A');
    Agregar('B');
    Imprimir();
    
    return 0;
}

int ConversionASCII(char c) {
    
    return static_cast<int>(c);
}

void Agregar(char dato) {
    
    Nodo *nuevoNodo = new Nodo;
    Registro r;
    r.dato = ConversionASCII(dato);
    int clave = FHash(r.dato);

    nuevoNodo->registro = r;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = tabla[clave];

    if (tabla[clave])
        tabla[clave]->anterior = nuevoNodo;

    tabla[clave] = nuevoNodo;
}

int FHash(int dato) {
    return dato % kdimension;
}

Nodo *Buscar(int dato, int clave) {
    
    Nodo *actual = tabla[clave];
    while (actual) {
        if (actual->registro.dato == dato)
            return actual;
        actual = actual->siguiente;
    }
    return nullptr;
}

void Buscar(int dato) {
    
    int clave = FHash(dato);
    Nodo *nodo = Buscar(dato, clave);
    if (nodo) {
        std::cout << "Registro encontrado → Posicion: " << clave
                  << " | Valor ASCII: " << nodo->registro.dato
                  << std::endl;
    } else {
        std::cout << "Registro no encontrado" << std::endl;
    }
}

void Eliminar(int dato) {
    
    int clave = FHash(dato);
    Nodo *nodo = Buscar(dato, clave);
    if (nodo) {
        std::cout << "Eliminando registro → Valor ASCII: "
                  << nodo->registro.dato
                  << std::endl;

        if (nodo->siguiente)
            nodo->siguiente->anterior = nodo->anterior;

        if (nodo->anterior)
            nodo->anterior->siguiente = nodo->siguiente;
        else
            tabla[clave] = nodo->siguiente;

        delete nodo;
    } else {
        std::cout << "Registro no encontrado" << std::endl;
    }
}

void Imprimir() {
    
    for (int i = 0; i < kdimension; i++) {
        Nodo *temp = tabla[i];
        if (temp)
            std::cout << "\n[Índice " << i << "]\n";

        while (temp) {
            std::cout << "  Nodo: " << temp
                      << " | Anterior: " << temp->anterior
                      << " | Dato ASCII: " << temp->registro.dato
                      << std::endl;
            temp = temp->siguiente;
        }
    }
}