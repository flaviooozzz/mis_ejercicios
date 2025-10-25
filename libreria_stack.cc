#include <iostream>
#include <stack>

std::stack<char> solicitarDatos();
void imprimirDatos(std::stack<char> nombre);

int main(){
    std::stack<char> nombre;
    nombre = solicitarDatos();
    imprimirDatos(nombre);
   
}

std::stack<char> solicitarDatos(){
    char temp;
    std::stack<char> nombre;
    int n;
    std::cout<<"Ingrese la longitud de su nombre: ";
    std::cin>>n;
    for(int i =0;i<n;i++){
        std::cout<<"Ingrese la letra "<<i+1<<" de su nombre: ";
        std::cin>>temp;
        nombre.push(temp);
    }
    return nombre;
}
void imprimirDatos(std::stack<char> nombre){
    int n = nombre.size();
    for(int i=0;i<n;i++){
        std::cout<<nombre.top();
        nombre.pop();

    }
}
