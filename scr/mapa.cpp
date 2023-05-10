#include "../inc/mapa.hpp"
#include <fstream>
#include <cstring>
#include <cstring> // do uzycia funkcji strlen


void plansza::przypisz(char pom[])
{
    vector<char> wektor;   
    for (int i = 0; i < strlen(pom); i++)
    {
        wektor.push_back(pom[i]);
    }
    board.push_back(wektor);            //stan mapy
    board1.push_back(wektor);           //mapa poczatkowa
    
}

void plansza::czytaj(const string& plik)
{
    ifstream file(plik);   

    if (!file.is_open()) 
    {
        cerr << "Nie udało się otworzyć pliku mapy." << endl;
        exit(1);
        
    }
    
    //Zcztanie wartości plik w formie string
    vector<string> mapa_data;
    string linia;
    while (getline(file,linia))
    {
        mapa_data.push_back(linia);
    }

    // Obliczenie rozmiaru planszy
    int rzad=mapa_data.size();
    int kolumna=(rzad>0)?mapa_data[0].size():0;
    rozmiar_x=kolumna;
    rozmiar_y=rzad;

    // Przypisanie znaków planszy do wektora `board`
    int len,index=0;
    for(const auto& rzad:mapa_data)
    {
        //przejście ze stringa na char
        len = rzad.length();
        char char_array[len+1];
        strcpy(char_array, rzad.c_str());
        przypisz(char_array);
        index++;
    }
    
}


plansza::plansza(const string& plik)
{                          
    ifstream file(plik);   

    if (file.is_open()) 
    {
    
        vector<string> mapa_data;
        string linia;
        while (getline(file,linia))
        {
            mapa_data.push_back(linia);
        }
    
        // Obliczenie rozmiaru planszy
        int rzad=mapa_data.size();
        int kolumna=(rzad>0)?mapa_data[0].size():0;
        rozmiar_x=kolumna;
        rozmiar_y=rzad;
    

        // Przypisanie znaków planszy do wektora `board`
        int len,index=0;

        for(const auto& rzad:mapa_data)
        {
            //przejście ze stringa na char
            len = rzad.length();
            char char_array[len+1];
            strcpy(char_array, rzad.c_str());
            przypisz(char_array);
            index++;
        }
        file.close();            // zamknięcie pliku

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
    for (int i = 0; i < rozmiar_y; i++) 
    {
        for (int j = 0; j < rozmiar_x; j++) 
        {
            cout << board[i][j] << " "; 
        }
        cout << endl;
    }
}

void plansza:: UPDATE(vector<Jednostka> jednostki)
{   
     for (int i = 0; i < rozmiar_y; i++) 
    {
        for (int j = 0; j < rozmiar_x; j++) 
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