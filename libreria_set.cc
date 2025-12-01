#include <iostream>
#include <set>

struct Tiobe{
        std::string lenguaje_programacion;
        float puntaje;
};

struct ComPuntaje {
    bool operator()(const Tiobe& a, const Tiobe& b) const {
        return a.puntaje < b.puntaje;
    }
};

void imprimir(std::set<Tiobe, ComPuntaje> abb);

int main(){
    std::set<Tiobe, ComPuntaje> abb;
    struct Tiobe info;
    int aux;

    do{
        std::cout << "Ingresa el puntaje del Lenguaje: ";
        std::cin >> info.puntaje;
        std::cin.ignore();
        std::cout << "Ingresa el nombre del lenguaje de programacion: ";
        std::getline(std::cin, info.lenguaje_programacion);
        abb.insert(info);
        std::cout<<"Desea agregar otro lenguaje? (1. si 2. no): ";
        std::cin>>aux;
    }while(aux==1);

    imprimir(abb);

    return 0;
}

void imprimir(std::set<Tiobe, ComPuntaje> abb){
    for (auto t : abb) {
        std::cout << "- " << t.lenguaje_programacion << ": " << t.puntaje << std::endl;
    }
}