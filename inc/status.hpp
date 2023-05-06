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

#define ROZMIAR_X 32
#define ROZMIAR_Y 5

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

        void  zapisz(const string& plik);  


        vector<Jednostka>  get_jednostki() const {return jednostki;} 

        int  get_zloto() const {return zloto;} 
        
           

        void wypisz(int index);

        int Czy_ID_występuje(int id);

        void Jakie_rozkazy();

        void UWAGA(plansza Mapa, Move move);

        void UWAGA(plansza Mapa, Atak atak);

        void UWAGA(plansza Mapa, Budowanie budowanie);

};




#endif