#include <iostream>
#include <vector>
#include <algorithm>

struct luchador {
    std::string nombre;
    float peso;
};

std::vector<luchador> datos;
struct luchador solicitarDatos();
void ordenar(std::vector<luchador>& datos);
void imprimirDatos(std::vector<luchador> datos);
bool compararLuchador(const luchador& a, const luchador& b);
bool buscarLuchador(const std::vector<luchador>& datos, float peso_buscado);

int main() {
    for (int i = 0; i < 5; i++) {
        std::cout << "datos de luchador: " << i + 1 << "\n";
        datos.push_back(solicitarDatos());
    }

    
    std::sort(datos.begin(), datos.end(), compararLuchador);

    
    imprimirDatos(datos);

    float peso_buscado;
    std::cout << "\nIngrese el peso a buscar: ";
    std::cin >> peso_buscado;

    bool encontrado = std::binary_search(datos.begin(), datos.end(), luchador{"", peso_buscado}, compararLuchador);

    if (encontrado)
        std::cout << " Se encontró un luchador con ese peso.\n";
    else
        std::cout << " No se encontró ningún luchador con ese peso.\n";


    return 0;
}

struct luchador solicitarDatos() {
    struct luchador luchador;
    std::cout << "ingrese el nombre del luchador: ";
    std::cin >> luchador.nombre;
    std::cout << "ingrese el peso del luchador: ";
    std::cin >> luchador.peso;

    return luchador;
}


bool compararLuchador(const luchador& a, const luchador& b) {
    return a.peso > b.peso;
}

void ordenar(std::vector<luchador>& datos) {
    std::sort(datos.begin(), datos.end(), compararLuchador);
}

void imprimirDatos(std::vector<luchador> datos) {
    struct luchador luchador;
    luchador.nombre = " ";
    luchador.peso = 0;
    for (auto nuevo : datos) {
        if (nuevo.peso > luchador.peso) {
            luchador.nombre = nuevo.nombre;
            luchador.peso = nuevo.peso;
        }
    }

    std::cout << "el luchador mas pesado es: " << luchador.nombre << "\n";
    std::cout << "el peso de el mas pesado es: " << luchador.peso << "\n";
}

bool buscarLuchador(const std::vector<luchador>& datos, float peso_buscado) {
    return std::binary_search( datos.begin(), datos.end(),luchador{"", peso_buscado}, compararLuchador);
}