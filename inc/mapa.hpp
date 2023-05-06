#ifndef PLANSZA_HHP
#define PLANSZA_HHP

#include <iostream>
#include <vector>
#include "jednostka.hpp"

#define ROZMIAR_X 32
#define ROZMIAR_Y 5

using namespace std;

/**
 * \brief Klasa reprezentująca planszę gry.
 * gdzie:
 * 0 - droga po której mogą przemieszczać się jednostki
 * 9 - przeszkoda, jednostki nie mogą zatrzymać się na tym polu, 
 *     w przypadku wystarczającej ilości punktów ruchu przeszkody można przeskakiwać
 * 1 - baza pierwszego programu gracza
 * 2 - baza drugiego programu gracza
 * 6 - kopalnia
 */

class plansza
{
    private:
        char board[ROZMIAR_Y][ROZMIAR_X];   /**< Mapa */
        char board1[ROZMIAR_Y][ROZMIAR_X];   /**< Mapa poczatkowa */

    public:
        /**
        * \brief Konstruktor planszy rozgrywki przy pomocy podanego pliku
         * \param plik nazwa pliku z planszą do odczytu
        */
        plansza(const string& plik);     

        /**
        * \brief Funkcja wypisująca elementy planszy.
        */
        void wypisz_plansze();

        /**
        * \brief Getter dla rozmiaru planszy.
        * \return rozmiar planszy
        */
        int  getrozmiar() const {return ROZMIAR_Y;} 

        /**
        * \brief Getter dla liczby wymaganych znaków w rzędzie.
        * \return liczba wymaganych znaków w rzędzie
        */
        int  getiloscrzedow() const {return ROZMIAR_X;} 

        /**
        * \brief Getter który zwróci wskaźnik na początek tablicy board w klasie plansza
        */
        char* get_board();


        void UPDATE(vector<Jednostka> jednostki);

        bool czy_puste(int x,int y);

        void czytaj(const string& plik);


};




#endif