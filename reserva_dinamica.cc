#include <iostream>

void SolicitarDatos(float *ptr,int cantidad_ventas);
void MostrarDatos(float *ptr,int cantidad_ventas);
int CalcularPromedio(float *ptr,int cantidad_ventas);
void Menu();

int main(){
    int cantidad_ventas;
    std::cout<<"Ingrese el numero de ventas que desea ingresar: ";
    std::cin>>cantidad_ventas;
    float *ptr = new float[cantidad_ventas];
    
    SolicitarDatos(ptr, cantidad_ventas);
    MostrarDatos(ptr, cantidad_ventas);
    std::cout<<CalcularPromedio(ptr, cantidad_ventas);

    return 0;
}

void SolicitarDatos(float *ptr,int cantidad_ventas){
    for(int i = 0; i<cantidad_ventas;i++){
        std::cout<<"Ingrese el valor de la venta "<<i+1<<": ";
        std::cin>>*(ptr+i);
    }

}
void MostrarDatos(float *ptr, int cantidad_ventas){
    for(int i = 0; i<cantidad_ventas;i++){
        std::cout<<"Direccion de memoria elemento "<<i<<": "<<ptr+i
        <<"--valor del elemento "<<i<<": "<<*(ptr+i)<<std::endl;
    }

}
int CalcularPromedio(float *ptr, int cantidad_ventas){
    float promedio =0, suma=0;
    for(int i = 0; i<cantidad_ventas;i++){
        suma += *(ptr+i);
    }
    promedio = suma/cantidad_ventas;
    return promedio;

}
void Menu(){
    std::cout<<"Ingrese la operacion que desea realizar: "<<std::endl;
    std::cout<<"1.Ingresar datos\n2.Mostrar datos\n3.Calcular promedio ";
}

