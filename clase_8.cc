#include <iostream>

int main(){
    int numero = 99;
    int lista_numeros[5]= {1,2,46,7,8};
    int *ptr = &numero;
    // se reserva un esapcio de memoria a un tipo de dato
    int *ptr_2 = new int;
    //se asigna un valor a este esapcio de memoria reservado
    *ptr_2 = 100;
    //validacion
    if(ptr_2 == nullptr){
        std::cout<<"Error de asignacion de memoria"<<std::endl;
    }
    else{
        std::cout<<"Direccion de memoria: "<<ptr_2<<std::endl;
    }
    // se elimina este valor al espacio de memoria reservador
    delete ptr_2;
    //se elimina el espacio de memoria reservador
    ptr_2 = nullptr;

    if(ptr_2 == nullptr){
        std::cout<<"Error de asignacion de memoria"<<std::endl;
    }
    else{
        std::cout<<"Direccion de memoria: "<<ptr_2<<std::endl;
    }

    return 0;
}