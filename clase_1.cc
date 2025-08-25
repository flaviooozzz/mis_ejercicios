#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>

struct InformacionCupon{
    int cant_cupones;
    std::string nombre_persona;
    //std::string cupones_generados[3][3];
    std::vector<std::pair<std::string,std::string>>cupones_generadors;
    

}cupon;

std::string GenerarCupon(std::string parametro);
std::string AsignarPremio(std::string identificador_cupon);
std::string SolicitarDatos();

int main(){
    srand(time(0));
    std::string nombre_persona;
    std::cout<<"Ingrese su nombre: ";
    std::cin>>cupon.nombre_persona;
    std::cout<<"Cuantos cupones desea generar: ";
    std::cin>>cupon.cant_cupones;
    std::string cupon_generado;
    std::string premio;
    //std::string cupones[cantidad_de_cupones];
    for (int i=0;i<cupon.cant_cupones;i++){
    
        std::string prefijo = SolicitarDatos();
        cupon_generado=GenerarCupon(prefijo);
        premio = AsignarPremio(cupon_generado);
        //cupones[i] = GenerarCupon(prefijo);
        cupon.cupones_generadors.push_back({cupon_generado,premio});
        std::cout << "Su cupon es: " << cupon_generado<< std::endl;
    }
    /*std::cout<<"\nTodos sus cupones son: "<<std::endl;
    for (int i=0;i<cantidad_de_cupones;i++){
        std::cout << "Cupon "<<i+1<<": " << cupones_vector[i]<< std::endl;
    }*/
   //se declara la varaible i en auto ya que se "desconoce" el tipo de dato, y recorre posicion por posicion el arreglo,
   //vector, etc
    std::cout<<"---Resumen---"<<std::endl;
    std::cout<< "Nombre: " << cupon.nombre_persona << std::endl;
    std::cout<< "Cantidad de cupones: " << cupon.cant_cupones << std::endl;   
    std::cout<<"Todos los cupones: "<<std::endl;
    for(int i=0;i<cupon.cant_cupones;i++){
        std::cout<<"Cupon: ";
        std::cout<<cupon.cupones_generadors[i].first<<" ";
        std::cout<<cupon.cupones_generadors[i].second<<std::endl;
    }
    return 0;
}

std::string GenerarCupon(std::string parametro){
    int numero_aleatorio = rand() % 900 + 100; 
    std::string conversion = std::to_string(numero_aleatorio);
    return parametro + conversion;
}

std::string AsignarPremio(std::string identificador_cupon){
    std::string valor_cupon = identificador_cupon.substr(3,3);
    int cupon_numeros = std::stoi(valor_cupon);

    if(cupon_numeros % 2 == 0){
        return "Tiene premio";
    }
    else{
        return "NO tiene premio";
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
