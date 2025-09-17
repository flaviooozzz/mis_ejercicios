#include <iostream>
#include <vector>

struct albumMusical {
    std::string nombreAlbum;
    int anoAlbum;
    std::vector<std::pair<std::string,int>> cancionesAlbum;
    int edadAlbum;
};

struct datosCantante {
    std::string nombreCantante;
    std::string nacionalidadCantante;
    std::vector<albumMusical> album; // Un cantante puede tener varios álbumes
};

std::vector<datosCantante> vector_cantante;

// Declaración de funciones
datosCantante solicitarDatos();
albumMusical solicitarDatosAlbum();
void Imprimir(std::vector<datosCantante> vector_cantante, int bucle);
int calcularEdadAlbum(albumMusical album);
int ciclos();

int main() {
    int bucle = 1, aux = bucle;
    while (true) {
        datosCantante cantante = solicitarDatos();

        // Calcular edad de cada álbum
        for (auto &alb : cantante.album) {
            alb.edadAlbum = calcularEdadAlbum(alb);
        }

        vector_cantante.push_back(cantante);
        Imprimir(vector_cantante, bucle);

        bucle = bucle + ciclos();
        if (aux == bucle) {
            break;
        } else {
            aux = bucle;
        }
    }
    return 0;
}

albumMusical solicitarDatosAlbum() {
    albumMusical album;
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

    return album;
}

datosCantante solicitarDatos() {
    datosCantante cantante;
    int opcion;

    std::cout<<"Ingrese el nombre del cantante: ";
    std::cin>>cantante.nombreCantante;
    std::cout<<"Ingrese la nacionalidad del cantante: ";
    std::cin>>cantante.nacionalidadCantante;

    std::cout<<"Cuantos albumes desea agregar: ";
    std::cin>>opcion;

    for(int i = 0; i < opcion; i++) {
        cantante.album.push_back(solicitarDatosAlbum());
    }
    return cantante;
}

void Imprimir(std::vector<datosCantante> vector_cantante, int bucle) {
    for(int i=0; i<bucle; i++) {
        std::cout<<"\nDatos cantante "<<i+1<<": "<<std::endl;
        datosCantante c = vector_cantante[i];

        std::cout<<"Nombre del cantante: "<<c.nombreCantante<<std::endl;
        std::cout<<"Nacionalidad: "<<c.nacionalidadCantante<<std::endl;

        for (auto alb : c.album) {
            std::cout<<"  Nombre del album: "<<alb.nombreAlbum<<std::endl;
            std::cout<<"  Ano album: "<<alb.anoAlbum<<std::endl;
            std::cout<<"  Edad album: "<<alb.edadAlbum<<std::endl;
            for(auto cancion : alb.cancionesAlbum){
                std::cout<<"    Cancion: "<< cancion.first << " Posicion: " << cancion.second << std::endl;
            }
        }
    }
}

int calcularEdadAlbum(albumMusical album) {
    return 2025 - album.anoAlbum;
}

int ciclos() {
    std::string opcion;
    std::cout<<"\nDesea continuar? si/no: ";
    std::cin>>opcion;
    return (opcion == "si") ? 1 : 0;
}
