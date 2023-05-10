#ifndef STATUS_HPP
#define STATUS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

#include "jednostka.hpp"
#include "mapa.hpp"
#include "akcja.hpp"


using namespace std;

/**
 * \brief Klasa reprezentująca status gry
 */

class Status
{
    private:
        int zloto;                              /**< Ilość złota */   
        vector<Jednostka> jednostki;            /**< Vekor jednostek w rozgrywce */   

        

    public:
        public:
        /**
        * \brief Konstruktor Statusu rozgrywki przy pomocy podanego pliku
         * \param plik nazwa pliku ze statusem do odczytu
         * \param mapa tablica z danymi mapy
        */
        Status(const string& plik);  

        /**
         * \brief Funkcja zapisuje dane o stanie gry do pliku.
         * Funkcja zapisuje informacje o stanie gry, takie jak ilość złota i informacje o każdej jednostce, 
         * do pliku o podanej nazwie. W przypadku niepowodzenia otwarcia pliku, funkcja wypisuje odpowiedni 
         * komunikat i kończy działanie programu.
         * \param plik Nazwa pliku, do którego mają zostać wpisane dane.
        */
        void  zapisz(const string& plik);  

        /**
        * \brief Getter dla jednotek.
        * \return vektor wszytskich jednostek w grze
        */
        vector<Jednostka>  get_jednostki() const {return jednostki;} 

        /**
        * \brief Getter dla złota.
        * \return ilość dostępnego złota
        */
        int  get_zloto() const {return zloto;} 

        /**
        * \brief Funkcja które, powiększa złoto.
        * \param ile wartość o którą należy zwiększyć złoto
        */
        void  dodaj_zloto(int ile); 
        
           
        /**
        * \brief Wyświetla informacje o stanie gry dla jednostki o podanym indeksie w wektorze jednostek.
        * \param index Indeks jednostki w wektorze jednostek.
        */
        void wypisz(int index);

        /**
         * \brief Sprawdza, czy jednostka o podanym ID istnieje w wektorze jednostek w obiekcie 
         * klasy Status.
         * \param id ID szukanej jednostki
         * \return int Zwraca indeks jednostki o podanym ID z wektora jednostek powiększony o jeden,
         *  lub 0, gdy taka jednostka nie istnieje w wektorze.
        */
        int Czy_ID_występuje(int id);

        /**
         * \brief Sprawdza, czy ruch jednostką o danym ID jest możliwy i wykonywalny, a następnie dokonuje
         *  zmiany położenia na mapie. 
         * \param Mapa Obiekt klasy plansza, reprezentujący planszę gry.
         * \param move Obiekt klasy Move, reprezentujący ruch, który chcemy wykonać.
         **/
        void UWAGA(plansza Mapa, Move move);

        /**
         * \brief Funkcja UWAGA odpowiada za przeprowadzenie ataku jednostki na inną jednostkę 
         * na planszy gry. Funkcja UWAGA sprawdza, czy jednostka atakująca oraz jednostka atakowana
         *  istnieją na planszy, a także czy zasięg ataku jest wystarczający.
         * Następnie określa obrażenia, jakie dana jednostka zadaje jednostce przeciwnika, ko
         * rzystając z tabeli ataków. Obrażenia są odejmowane od punktów życia jednostki przeciwnika.
         * Jeśli punkty życia jednostki przeciwnika spadną do zera lub poniżej, jednostka przeciwnika
         *  zostaje usunięta z planszy. W przypadku, gdy usunięta jednostka była bazą, 
         * funkcja wyświetla komunikat o zwycięstwie. Na koniec funkcja zaaktualizuje planszę gry 
         * i wyświetli ją na ekranie.
         * \param Mapa Obiekt typu plansza, reprezentujący planszę gry.
         * \param atak Obiekt typu Atak, reprezentujący atak jednostki na inną jednostkę
         * \param kto Flaga gracza
         **/
        void UWAGA(plansza Mapa, Atak atak,string kto);


        /**
         * \brief Funkcja sprawdzająca możliwość budowy przez bazę wybranej jednostki 
         * oraz dodająca produkt do bazy. Funkcja sprawdza, czy wybrana jednostka budująca istnieje 
         * i czy jest bazą. Jeśli tak, to dodaje produkt do bazy. Jeśli nie, to wypisuje odpowiedni 
         * komunikat i kończy działanie programu.
         * \param Mapa Obiekt klasy plansza, na której odbywa się gra
         * \param budowa Obiekt klasy Budowanie, reprezentujący budowe
        */
        void UWAGA(plansza Mapa, Budowanie budowanie);

        /**
         * \brief Funkcja służąca do dodania odpowiedniej jednostki po jej wybudowaniu. Elinująca 
         * odpowiednio koszt. 
         * \param
         * 
         * \note Nie użyta z powodu problemów przy zapisywaniu czasu tworzenia jednostki
        */
        void Dodaj_Jednostke(string kto, string jaka, int identyfikator, int x, int y);

};




#endif