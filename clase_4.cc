#include <iostream>

void PasoPorValor(int n);
void PasoPorReferencia(int &n);

int main(){

    int num = 100;

    std::cout<<"Valor de num: "<<num<<"\n";
    PasoPorValor(num);
    std::cout<<"Valor de num: "<<num<<"\n";
    PasoPorReferencia(num);
    std::cout<<"Valor de num: "<<num<<"\n";
   


    return 0;
}

void PasoPorValor(int n){
    std::cout<<"Valor de n: "<<n+10<<"\n";
}

void PasoPorReferencia(int &n){
    std::cout<<"Valor de n: "<<n +10<<"\n";
}
//paso por valor es pasar literalmente una variable
//paso por referencia es pasar directamente la direccion de memoria de una variable
//paso por puntero es literalmente pasar el puntero
//en otros archivos esta esto puesto en practicda, aqui solo es un recordatorio