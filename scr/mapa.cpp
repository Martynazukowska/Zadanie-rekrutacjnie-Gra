#include "../inc/mapa.hpp"
#include <fstream>

/**
 * \brief Konstruktor planszy rozgrywki, wczytuje stan planszy z pliku
 * \param plik ścieżka do pliku z danymi planszy
 * \throws std::runtime_error jeśli nie uda się otworzyć pliku
 */
plansza::plansza(const string& plik)
{                          
    ifstream file(plik);   

    if (file.is_open()) // sprawdzenie, czy plik został otwarty
    { 
        for (int i = 0; i < ROZMIAR_Y; i++) 
        {
            for (int j = 0; j < ROZMIAR_X; j++) {
                file >> board[i][j]; // odczyt wartości z pliku i zapisanie do macierzy
            }
        }

        file.close(); // zamknięcie pliku
    } 
    else 
    {
        cerr << "Nie udało się otworzyć pliku." << endl;
        exit(1);
        
    }
}

/**
 * \brief Funkcja wypisująca elementy planszy.
 */
void plansza::wypisz_plansze() 
{
    cout << "Plansza gry:" << std::endl;
    for (int i = 0; i < ROZMIAR_Y; i++) 
    {
        for (int j = 0; j < ROZMIAR_X; j++) 
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
