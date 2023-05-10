#ifndef PLANSZA_HHP
#define PLANSZA_HHP

#include <iostream>
#include <vector>
#include "jednostka.hpp"

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
        vector<vector<char>> board;          /**< Mapa */
        vector<vector<char>> board1;          /**< Mapa poczatkowa */
        int rozmiar_x;                        /**< Połozenie X */
        int rozmiar_y;                        /**< Połozenie Y */

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
        int  get_Y() const {return rozmiar_y;} 

        /**
        * \brief Getter dla liczby wymaganych znaków w rzędzie.
        * \return liczba wymaganych znaków w rzędzie
        */
        int  get_X() const {return rozmiar_x;} 

        /**
        * \brief Getter który zwróci wskaźnik na początek tablicy board w klasie plansza
        */
        const vector<char>* get_board() const { return board.data(); }

        /**
         * \brief Aktualizuje planszę gry zgodnie z położeniem jednostek.
         * Funnkcja ta aktualizuje planszę gry na podstawie położenia jednostek przekazanych 
         * jako argument.Najpierw kopiowane są zawartości planszy pomocniczej do planszy 
         * głównej, a następnie dla każdej jednostki prawdzane jest, czy jej pozycja na planszy 
         * jest pusta. Jeśli tak, jej typ jest umieszczany na planszy. W przeciwnym przypadku, f
         * unkcja wyświetla komunikat o błędzie.
         * \param jednostki Wektor zawierający jednostki, których położenie ma zostać uwzględnione na planszy.
        */
        void UPDATE(vector<Jednostka> jednostki);

        /**
         * \brief Sprawdza, czy pole o podanych współrzędnych jest puste.
         * Funkcja ta sprawdza, czy pole o podanych współrzędnych jest puste. 
         * Jeśli na tym polu nie ma żadnej jednostki ani bazy,
         * funkcja zwraca wartość true. W przeciwnym przypadku, funkcja zwraca wartość false.
         * \param x Współrzędna X pola, które ma zostać sprawdzone.
         * \param y Współrzędna Y pola, które ma zostać sprawdzone.
         * \return true, jeśli pole jest puste; false, jeśli pole jest zajęte przez jednostkę lub bazę.
         * */
        bool czy_puste(int x,int y);

        /**
         * \brief Sprawdza, czy są jakyś pracownicy kopalnni.
         * \return ilość, pracowników w kopalni
         * */
        int czy_kopie();

        /**
         * \brief Wczytuje planszę z pliku.
         * Funkcja ta wczytuje planszę z pliku o nazwie podanej jako parametr. Wczytane dane zostają
         *  zapisane w macierzy board w obiekcie klasy plansza.
         * \param plik Nazwa pliku, z którego mają zostać wczytane dane planszy.
        */
        void czytaj(const string& plik);

        /**
         * \brief Funkcja przypisuje tablicę znaków do planszy gry.
         * Funkcja ta przepisuje zawartość tablicy `pom` do wektora `board`, 
         * który reprezentuje planszę gry. Tablica ta zawiera znaki, z których 
         * każdy oznacza pole planszy. Po przypisaniu plansza jest gotowa do użycia w grze.
         * \param pom Tablica znaków zawierająca zawartość planszy do przypisania.
        */
        void przypisz(char pom[]);


};




#endif