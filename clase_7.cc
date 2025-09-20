#include <iostream>

int main(){
    int arreglo[3] = {1,3,100};

    int *ptr = arreglo;

    std::cout<<"Direccion memoria: "<< arreglo <<std::endl;
    std::cout<<"Valor pos[0]: "<< arreglo[0] <<std::endl;

    std::cout<<"Direccion memoria: "<<(arreglo+1)<<std::endl;
    std::cout<<"Valor pos[1]: "<<*(arreglo+1)<<std::endl;

    std::cout<<"Direccion memoria: "<<ptr + 2<<std::endl;
    std::cout<<"Valor pos[2]: "<<*(ptr + 2)<<std::endl;


    return 0; 
}