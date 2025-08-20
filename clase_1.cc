#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string GenerarCupon(std::string parametro);
void AsignarPremio(std::string identificador_cupon);
std::string SolicitarDatos();

int main(){
    srand(time(0));  
    std::cout<<"Cuantos cupones desea generar: ";
    int cantidad_de_cupones;
    std::cin>>cantidad_de_cupones;
    std::string cupones[cantidad_de_cupones];
    for (int i=0;i<cantidad_de_cupones;i++){
    
        std::string prefijo = SolicitarDatos();
        cupones[i] = GenerarCupon(prefijo);
        std::cout << "Su cupon es: " << cupones[i]<< std::endl;

        AsignarPremio(cupones[i]);
    }
    std::cout<<"Todos sus cupones son: "<<std::endl;
    for (int i=0;i<cantidad_de_cupones;i++){
        std::cout << "Cupon "<<i+1<<": " << cupones[i]<< std::endl;
    }
    return 0;
}

std::string GenerarCupon(std::string parametro){
    int numero_aleatorio = rand() % 900 + 100; 
    std::string conversion = std::to_string(numero_aleatorio);
    return parametro + conversion;
}

void AsignarPremio(std::string identificador_cupon){
    std::string valor_cupon = identificador_cupon.substr(3,3);
    int cupon_numeros = std::stoi(valor_cupon);

    if(cupon_numeros % 2 == 0){
        std::cout << "Tiene premio";
    }
    else{
        std::cout << "NO tiene premio";
    }
}

std::string SolicitarDatos(){
    std::string prefijo;
    do {
        std::cout << "\nIngrese las 3 letras de su cupon: ";
        std::cin >> prefijo;
        if (prefijo.length() != 3){
            std::cout << "Entrada invalida. Debe ingresar exactamente 3 letras.\n";
        }
    } while (prefijo.length() != 3);
    return prefijo;
}
