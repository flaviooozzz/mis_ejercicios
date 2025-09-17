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