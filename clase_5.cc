#include <iostream>

int acumulador(int n);

int acumulador2(int &n);

int acumulador3(int *n);

int main(){
    int x = 10;
    std::cout<<"Nuevo valor: "<<acumulador(x)<<"\n";
    std::cout<<"Valor de x: "<<x<<"\n";
    std::cout<<"Nuevo valor: "<<acumulador2(x)<<"\n";
    std::cout<<"Valor de x: "<<x<<"\n";
    std::cout<<"Nuevo valor: "<<acumulador3(&x)<<"\n";
    std::cout<<"Valor de x: "<<x<<"\n";
    return 0;
}

int acumulador(int n){
    n = n + 1;
    return n;
}
int acumulador2(int &n){
    n = n + 1;
    return n;
}
int acumulador3(int *n){
    *n = *n + 1;
    return *n;
}