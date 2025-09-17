#include <iostream>

void PasoPorValor(int a, int b);
void PasoPorReferencia(int &, int &);

int main(){
    int v1 = 5;
    int v2 = 10;
    std::cout<<"Valor inicial: \nvalor 1: "<<v1<<"\nvalor 2: "<<v2<<std::endl;
    PasoPorValor(v1,v2);
    std::cout<<"Valor luego de funcion paso por valor: \nvalor 1: "<<v1<<"\nvalor 2: "<<v2<<std::endl;
    PasoPorReferencia(v1,v2);
    std::cout<<"Valor luego de funcion paso por referencia: \nvalor 1: "<<v1<<"\nvalor 2: "<<v2<<std::endl;
}

void PasoPorValor(int a, int b){
    int aux = a;
    a = b;
    b = aux;
    std::cout<<"Valor funcion: \nvalor 1: "<<a<<"\nvalor 2: "<<b<<std::endl;
}
void PasoPorReferencia(int &a, int &b){
    int aux = a;
    a = b;
    b = aux;
    std::cout<<"Valor funcion: \nvalor 1: "<<a<<"\nvalor 2: "<<b<<std::endl;


}