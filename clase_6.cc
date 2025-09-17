#include <iostream>

std::string pasoPorValor(std::string n);
std::string pasoPorReferencia(std::string &n);
std::string pasoPorPuntero(std::string *n);

int main(){
    std::string saludo = "Hola";
    std::cout<<"Valor de la variable: "<<saludo<<"\n";
    std::cout<<"Valor luego de paso por valor: "<<pasoPorValor(saludo)<<"\n";
    std::cout<<"Valor de la variable: "<<saludo<<"\n";
    std::cout<<"Valor luego de paso por referencia: "<<pasoPorReferencia(saludo)<<"\n";
    std::cout<<"Valor de la variable: "<<saludo<<"\n";
    std::cout<<"Valor luego de paso por puntero: "<<pasoPorPuntero(&saludo)<<"\n";
    std::cout<<"Valor de la variable: "<<saludo<<"\n";

    return 0;
}

std::string pasoPorValor(std::string n){
    n = "Hello world";
    return n;

}
std::string pasoPorReferencia(std::string &n){
    n = "Hola mundo";
    return n;

}
std::string pasoPorPuntero(std::string *n){
    *n = "Hola cesar";
    return *n;

}