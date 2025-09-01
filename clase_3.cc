#include <iostream>
#include <vector>
//struct para almacenar datos del cantante
struct datosCantante{
    std::string nombreCantante;
    std::string nacionalidadCantante;
}cantante;
//strcut para almacenar datos del album y canciones
struct albumMusical{
    std::string nombreAlbum;
    int anoAlbum;
    std::vector<std::pair<std::string,int>>cancionesAlbum;
    int edadAlbum;
    //anidamos? incluimos la struct del cantante en esta para almacenar todo
    struct datosCantante info_cantante;
}album;
//estos vectores para poder almacenar mas de un struct de tipo album musical
std::vector<struct albumMusical> vector_album;
std::vector<struct datosCantante> vector_cantante;

//se declaran todas las funciones antes del main y abajo las definimos
struct albumMusical solicitarDatos();
void Imprimir(std::vector<struct albumMusical> vector_cupon);
int calcularEdadAlbum(struct albumMusical);

int main(){
    //definimos una variable de tipo struct albumMusical
    struct albumMusical album;
    //lo igualamos al afuncion para solicitar los datos del struct
    album = solicitarDatos();
    // con la otra funcion calculamos la edad del album
    album.edadAlbum= calcularEdadAlbum(album);
    //almacenamos los datos en el vector
    vector_album.push_back(album);
    Imprimir(vector_album);


    return 0;
}

struct albumMusical solicitarDatos(){
    struct albumMusical album;
    int antiguedadAlbum;
    std::string cancion;
    int numerocancion;
    std::cout<<"\nIngrese el nombre del album: ";
    std::cin>>album.nombreAlbum;
    std::cout<<"Ingrese el ano del album: ";
    std::cin>>album.anoAlbum;
    std::cout<<"Ingrese el nombre de la cancion: ";
    std::cin>>cancion;
    std::cout<<"Ingrese el numero de la cancion: ";
    std::cin>>numerocancion;
    album.cancionesAlbum.push_back({cancion,numerocancion});
    std::cout<<"Ingrese el nombre del cantante: ";
    std::cin>>album.info_cantante.nombreCantante;
    std::cout<<"Ingrese el nacionalidad del cantante: ";
    std::cin>>album.info_cantante.nacionalidadCantante;
   return album;


}

void Imprimir(std::vector<struct albumMusical> vector_album){

    for(auto c: vector_album){
        std::cout<<"Nombre del album: "<<c.nombreAlbum<<std::endl;
        std::cout<<"Ano album: "<<c.anoAlbum<<std::endl;
        std::cout<<"Edad album: "<<c.edadAlbum<<std::endl;
        for(auto c_p: c.cancionesAlbum){
            std::cout<<"Cancion: "<< c_p.first << " Posicion: " <<c_p.second<<std::endl;
        }
        std::cout<<"Nombre del cantante: "<<c.info_cantante.nombreCantante<<std::endl;
        std::cout<<"Nacionalidad del cantante: "<<c.info_cantante.nacionalidadCantante<<std::endl;
    }


}

int calcularEdadAlbum(struct albumMusical album){
    int antiguedadAlbum, edadAlbum;
    antiguedadAlbum = album.anoAlbum;
    edadAlbum = 2025 - antiguedadAlbum;
    return edadAlbum;

}