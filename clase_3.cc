#include <iostream>
#include <vector>

struct albumMusical{
    std::string nombreAlbum;
    int anoAlbum;
    std::vector<std::pair<std::string,int>>cancionesAlbum;
    int edadAlbum;
}

struct datosCantante{
    std::string nombreCantante;
    std::string nacionalidadCantante;
}