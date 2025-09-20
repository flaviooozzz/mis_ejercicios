#include <iostream>
#include <string>

struct Persona{
    //variables y archivos con snake case
    std::string nombre;
    float altura;
    float peso;
    float imc;
};
//funciones y structs con camel case
struct Persona solicitarDatos();
void calcularIMC(struct Persona *ptr);

int main(){

    struct Persona persona;
    persona = solicitarDatos();
    calcularIMC(&persona);
    std::cout<<"\n(main) Imc: "<<ptr->imc;

    return 0;
}

struct Persona solicitarDatos(){
    struct Persona cesar;
    std::cout<<"Ingrese su nombre: ";
    std::cin>>cesar.nombre;
    std::cout<<"Ingrese su altura: ";
    std::cin>>cesar.altura;
    std::cout<<"Ingrese su peso: ";
    std::cin>>cesar.peso;

    return cesar;
}
//los punteros tambien pueden apuntar a un strcut, aqui pasamos un puntero para afectar directamente en la estructura
void calcularIMC(struct Persona *ptr){
    ptr->imc = (ptr->peso)/(ptr->altura*ptr->altura);
    std::cout<<"(funcion) Imc: "<<ptr->imc;
}
//recordar formatear el documento antes de entregar