#include <iostream>
#include <cmath>
/*
declaracion de varaibles constantes
afuera de toda funcion, 
const double kpi = 3.14
osea primero
const - tipo de dato - k al inicio y luego el nombre de la varaible en snakecase - valor de la variable
*/
float CalcularAreaCirculo(int RadioCirculo);

int main(){
    float RadioCirculo;
    std::cout<<"Ingrese el radio de su circulo: "<<std::endl;
    std::cin>>RadioCirculo;
    std::cout<<"El area es: "<<round(CalcularAreaCirculo(RadioCirculo));

    return 0;
}

float CalcularAreaCirculo(int RadioCirculo){
    float AreaCalculadaCirculo=RadioCirculo*RadioCirculo*M_PI;
    return AreaCalculadaCirculo;
}