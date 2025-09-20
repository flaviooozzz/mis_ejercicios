#include <iostream>
//valor
int acumulador(int n);
//referencia
int acumulador2(int &n);
//puntero
int acumulador3(int *n);

int main(){
    int x = 10;
    //por valor solo se pone el nombre de la varaible
    std::cout<<"Nuevo valor: "<<acumulador(x)<<"\n";
    std::cout<<"Valor de x: "<<x<<"\n";
    //por referencia tamabien solo se pone el nombre de la varaible, ya que arriba decalramos que el prametro seria "&n"
    //es decir la direccion de memoria de la variable  
    std::cout<<"Nuevo valor: "<<acumulador2(x)<<"\n";
    std::cout<<"Valor de x: "<<x<<"\n";
    //esta es paso por puntero, lo que pasamos aqui es la direccion de memoria de la variable, porque?
    //porque justamente eso es un puntero (*ptr = &n)
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