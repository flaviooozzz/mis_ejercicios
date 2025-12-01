#include <iostream>
#include <unordered_map>
#include <vector>

using Grafo = std::unordered_map<char, std::vector<char>>;

void AgregarArista(Grafo &lista_adj, char origen, char destino);
void Imprimir(const Grafo &lista_adj);

int main(){
    Grafo lista_adj;
    AgregarArista(lista_adj, 'a','c');
    AgregarArista(lista_adj, 'a','d');

    Imprimir(lista_adj);

    return 0;
}
//grafo dirigido
void AgregarArista(Grafo &lista_adj, char origen, char destino){
    lista_adj[origen].push_back(destino);
}
void Imprimir(const Grafo &lista_adj){
    for(auto a:lista_adj){
        std::cout<<"Nodo: "<<a.first<<std::endl;
        std::cout<<"Conexiones: ";
        for(auto b: a.second){
            std::cout<<b;
        }

    }
}
//grafo no dirigido