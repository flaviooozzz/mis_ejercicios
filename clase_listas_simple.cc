#include <iostream>

struct Datos{
    int numero;

};
struct Nodo{
    struct Datos datos;
    struct Nodo *siguiente;

};

struct Nodo *inicio_lista = nullptr;
void InsertarInicio(int n);
void Imprimir();
void InsertarFinal(int n);
void EliminarInicio();
void EliminarFinal();

int main(){
    InsertarInicio(40);
    InsertarInicio(80);
    InsertarInicio(100);
    InsertarFinal(89);
    Imprimir();
    EliminarInicio();
    EliminarFinal();
    Imprimir();
    
    return 0;
}
void InsertarInicio(int n){
    struct Nodo *nuevo_nodo = new Nodo;
    nuevo_nodo->datos.numero = n;
    nuevo_nodo->siguiente = nullptr;
    if(inicio_lista == nullptr){
        inicio_lista = nuevo_nodo;   
    }
    else{
        nuevo_nodo->siguiente = inicio_lista;
        inicio_lista = nuevo_nodo;
    }
}
void Imprimir(){
    struct Nodo *temporal = inicio_lista;
    if(inicio_lista!=nullptr){
        while(temporal !=nullptr){
            std::cout<<"Valores de la lista:  "<<temporal->datos.numero<<
            "\nDireccion: "<<temporal<<
            "\nDireccion de dato siguiente: "<< temporal->siguiente<<std::endl;
            temporal = temporal->siguiente;
        }

    }
    else{
        std::cout<<"Esta lista esta vacia";
    }
}
void InsertarFinal(int n){
    struct Nodo *nuevo_nodo = new Nodo;
    struct Nodo *temporal = inicio_lista;
    nuevo_nodo->datos.numero = n;
    nuevo_nodo->siguiente = nullptr;
    if(inicio_lista==nullptr){
        inicio_lista = nuevo_nodo;
    }
    else{
        while(temporal->siguiente!=nullptr){
            temporal = temporal->siguiente;
        }
        temporal->siguiente = nuevo_nodo;
    }

}
void EliminarInicio(){
    struct Nodo *temporal = inicio_lista;

    if(inicio_lista!=nullptr){
        inicio_lista = temporal->siguiente;
        delete temporal;
        temporal = nullptr;
    }
}
void EliminarFinal(){
    struct Nodo *temporal_1 = inicio_lista;
    struct Nodo *temporal_2;
    if(inicio_lista!=nullptr){
        if(temporal_1->siguiente!=nullptr){
            while(temporal_1->siguiente!=nullptr){
                temporal_2 = temporal_1;
                temporal_1 = temporal_1->siguiente;
            }
            temporal_2->siguiente = nullptr;
            delete temporal_1;
            temporal_1 = nullptr;

        }
    }
}