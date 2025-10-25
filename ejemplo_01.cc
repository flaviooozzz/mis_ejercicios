#include <iostream>
#include <list>
#include <algorithm>
#include <string>

struct Cancion
{
    std::string titulo;
    std::string artista;
    float duracion;
    std::string genero;
    int reproducciones;
};

// Declaracion de funciones
void AgregarCancion(std::list<Cancion> &biblioteca);
void OrdenarCanciones(std::list<Cancion> &biblioteca);
void BuscarPorArtista(std::list<Cancion> &biblioteca, const std::string &artista_buscado);
void MostrarPlaylist(const std::list<Cancion> &biblioteca);

int main()
{
    std::list<Cancion> biblioteca;
    int opcion;
    std::string artista;

    do
    {
        std::cout << "\n--- Menu Biblioteca Musical ---\n";
        std::cout << "1. Agregar cancion\n";
        std::cout << "2. Ordenar por reproducciones\n";
        std::cout << "3. Buscar por artista\n";
        std::cout << "4. Mostrar playlist\n";
        std::cout << "0. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion)
        {
        case 1:
            AgregarCancion(biblioteca);
            break;
        case 2:
            OrdenarCanciones(biblioteca);
            break;
        case 3:
            std::cout << "Ingrese el nombre del artista: ";
            std::getline(std::cin, artista);
            BuscarPorArtista(biblioteca, artista);
            break;
        case 4:
            MostrarPlaylist(biblioteca);
            break;
        case 0:
            std::cout << "Hasta pronto!\n";
            break;
        default:
            std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}

// Implementacion de funciones

void AgregarCancion(std::list<Cancion> &biblioteca)
{
    Cancion nueva;
    std::cout << "Titulo: ";
    std::getline(std::cin, nueva.titulo);
    std::cout << "Artista: ";
    std::getline(std::cin, nueva.artista);
    std::cout << "Duracion (minutos): ";
    std::cin >> nueva.duracion;
    std::cin.ignore();
    std::cout << "Genero: ";
    std::getline(std::cin, nueva.genero);
    std::cout << "Numero de reproducciones: ";
    std::cin >> nueva.reproducciones;
    std::cin.ignore();

    biblioteca.push_back(nueva);
    std::cout << "Cancion agregada correctamente.\n";
}

void OrdenarCanciones(std::list<Cancion> &biblioteca)
{
    biblioteca.sort([](const Cancion &a, const Cancion &b)
                    { return a.reproducciones > b.reproducciones; });
    std::cout << "Canciones ordenadas por reproducciones (mayor a menor).\n";
}

void BuscarPorArtista(std::list<Cancion> &biblioteca, const std::string &artista_buscado)
{
    auto cmp = [](const Cancion &a, const Cancion &b)
    {
        return a.artista < b.artista;
    };

    biblioteca.sort(cmp);

    Cancion clave{};
    clave.artista = artista_buscado;

    auto it = std::lower_bound(biblioteca.begin(), biblioteca.end(), clave, cmp);

    if (it != biblioteca.end() && it->artista == artista_buscado)
    {
        std::cout << "Canciones encontradas de \"" << artista_buscado << "\":\n";
        for (auto jt = it; jt != biblioteca.end() && jt->artista == artista_buscado; ++jt)
        {
            std::cout << " - " << jt->titulo << " | Reproducciones: " << jt->reproducciones << "\n";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No se encontraron canciones del artista \"" << artista_buscado << "\".\n\n";
    }
}

void MostrarPlaylist(const std::list<Cancion> &biblioteca)
{
    if (biblioteca.empty())
    {
        std::cout << "No hay canciones registradas.\n";
        return;
    }

    int max_reproducciones = 0;
    for (const auto &c : biblioteca)
    {
        if (c.reproducciones > max_reproducciones)
        {
            max_reproducciones = c.reproducciones;
        }
    }

    std::cout << "\n--- Playlist ---\n";
    for (const auto &c : biblioteca)
    {
        std::cout << "Titulo: " << c.titulo << "\n";
        std::cout << "Artista: " << c.artista << "\n";
        std::cout << "Duracion: " << c.duracion << " min\n";
        std::cout << "Genero: " << c.genero << "\n";
        std::cout << "Reproducciones: " << c.reproducciones;
        if (c.reproducciones == max_reproducciones)
        {
            std::cout << " <-- Mas reproducida";
        }
        std::cout << "\n----------------------\n";
    }
}