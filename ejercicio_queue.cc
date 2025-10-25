#include <iostream>
#include <queue>
#include <windows.h>

// La informacion que el usuario ingresara
struct Persona
{
    std::string nombre;
    int f_nac;
};


// Declaracion de funciones / creacion de prototipo

struct Persona Insertar();
void Imprimir(std::queue<Persona> cola);

int main(int argc, char *argv[])
{
    std::queue<Persona> cola;
    struct Persona persona;
    int aux;
    do{
        persona = Insertar();
        cola.push(persona);
        std::cout<<"\nDesea agregar otro elemento? (1.si 2. no) ";
        std::cin>>aux;

    }while(aux==1);
    std::cout << " --------------- " << std::endl;
    Imprimir(cola);

    return 0;
}

struct Persona Insertar()
{
    struct Persona persona;
    std::cout << "Ingresa un nombre: ";
    std::cin >> persona.nombre;
    std::cout << "Ingresa su ano de nacimiento: ";
    std::cin >> persona.f_nac;
    return persona;
}


void Imprimir(std::queue<Persona> cola)
{
    int iterador = 1;
    if(cola.empty()==true){
        std::cout<<"La cola esta vacia"<<std::endl;
    }
    else{
        std::cout<<"El tamano de la cola es: "<<cola.size();
        do{
        std::cout<<"\nElemento "<<iterador<<" \nNombre: "<<cola.front().nombre<<
            "\nAno nacimiento: "<<cola.front().f_nac<<std::endl;
        iterador+=1;
        cola.pop();
        Sleep(3000);
        }while(cola.empty()!=true);
    }
}

