#include <iostream>

int main(){
    int arreglo[5] = {3,6,9,12,15};
    int *ptr = arreglo;
    int suma = 0;

    //por posicion
    for(int i = 0; i<5;i++){
        std::cout<<"Valor posicion "<<i+1<<": "<<arreglo[i]<<std::endl;
        std::cout<<"Valor memoria "<<i+1<<": "<<arreglo + i<<std::endl;
        suma = suma + arreglo[i];
    }
    std::cout<<"La suma es: "<<suma<<std::endl;
    suma = 0;
    //por puntero
    int i = 0;
    while(i <5){
        std::cout<<"Valor posicion "<<i+1<<": "<<*(ptr + i)<<std::endl;
        std::cout<<"Valor memoria "<<i+1<<": "<<ptr + i<<std::endl;
        suma = suma + *(ptr + i);
        i++;
    }
    std::cout<<"La suma es: "<<suma<<std::endl;


    return 0;
}