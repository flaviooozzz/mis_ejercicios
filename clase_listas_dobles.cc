#include <iostream>

struct Datos{
    int numero;

};
struct Nodo{
    struct Datos datos;
    struct Nodo *siguiente;
    struct Nodo *anterior;

};

void InsertarInicio(struct Nodo **lista,int n);
void InsertarFinal(struct Nodo **lista,int n);
void InsertarIntermedio(struct Nodo **lista,int n, int pos);
void Imprimir(struct Nodo **lista);
void EliminarInicio(struct Nodo **lista);
void EliminarFinal(struct Nodo **lista);
void ElliminarNodoValor(struct Nodo **lista, int n);
void ElliminarPos(struct Nodo **lista, int n);

int main(int argc, char *argv[]){
    struct Nodo *lista = nullptr;
    InsertarInicio(&lista,100);
    InsertarInicio(&lista,7);
    InsertarInicio(&lista,17);
    std::cout<<"Dir memoria: "<<lista<<" - Valor: "<<lista->datos.numero;
    std::cout<<"\nDir memoria: "<<lista->siguiente->siguiente<<" - Valor: "<<lista->siguiente->siguiente->datos.numero;

    return 0;
}

void InsertarInicio(struct Nodo **lista,int n){
    struct Nodo *nuevoNodo = new Nodo;
    nuevoNodo->datos.numero = n;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    if(*lista ==nullptr){
        *lista = nuevoNodo;
    }
    else{
        nuevoNodo->siguiente = *lista;
        (*lista)->anterior = nuevoNodo;
        *lista = nuevoNodo;
    }

}
void InsertarFinal(struct Nodo **lista,int n){

}
void InsertarIntermedio(struct Nodo **lista,int n, int pos){

}
void Imprimir(struct Nodo **lista){

}
void EliminarInicio(struct Nodo **lista){

}
void EliminarFinal(struct Nodo **lista){

}
void ElliminarNodoValor(struct Nodo **lista, int n){

}
void ElliminarPos(struct Nodo **lista, int n){

}