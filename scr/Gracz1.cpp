#include <iostream>
#include <string>
#include "../inc/mapa.hpp"


using namespace std;

int main(int argc, char *argv[]) 
{
    //Wypisz wszytskie argumenty programu
    cout << "Liczba argumentów: " << argc << std::endl;
    cout << "Argumenty: ";
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << " ";
    }
    cout << std::endl;

    //Inicjalizacja Mapy
    plansza Mapa("../pliki/"+ string(argv[1]));
    Mapa.wypisz_plansze();
    return 0;
}