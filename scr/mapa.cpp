#include "../inc/mapa.hpp"
#include <fstream>


void plansza::czytaj(const string& plik)
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
        cerr << "Nie udało się otworzyć pliku mapy." << endl;
        exit(1);
        
    }
}

plansza::plansza(const string& plik)
{                          
    ifstream file(plik);   

    if (file.is_open()) // sprawdzenie, czy plik został otwarty
    { 
        for (int i = 0; i < ROZMIAR_Y; i++) 
        {
            for (int j = 0; j < ROZMIAR_X; j++) {
                file >> board1[i][j]; // odczyt wartości z pliku i zapisanie do macierzy
                board[i][j]=board1[i][j];
            }
        }

        file.close(); // zamknięcie pliku
    }
    else 
    {
        cerr << "Nie udało się otworzyć pliku mapy." << endl;
        exit(1);
        
    }
}


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

void plansza:: UPDATE(vector<Jednostka> jednostki)
{
    for (int i = 0; i < ROZMIAR_Y; i++) 
    {
        for (int j = 0; j < ROZMIAR_X; j++) 
        {
            board[i][j]=board1[i][j]; 
        }
    }   
    for (int i = 0; i < jednostki.size(); i++)
    {
        if(jednostki[i].get_typ()!='B')
        {
            if(board[jednostki[i].get_Y()][jednostki[i].get_X()]=='0')                          //gdy pole jest puste
            {
                board[jednostki[i].get_Y()][jednostki[i].get_X()]=jednostki[i].get_typ();
            }
            else
            {
                cerr <<"Błąd przy stawianiu jednostki, miejsce jest już zajęte\n";
            }
        }

    }
}

bool plansza::czy_puste(int x,int y) 
{
    if(board[y][x]=='0')
    {
        return true;
    }
    return false;
}