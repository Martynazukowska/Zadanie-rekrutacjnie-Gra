#ifndef JEDNOSTKA_HPP
#define JEDNOSTKA_HPP

#include <iostream>

using namespace std;

/**
 * \brief Klasa reprezentująca Jednostke
 */

class Jednostka
{
    private:
        string przynaleznosc;

        

    public:
        public:
        /**
        * \brief Konstruktor Statusu rozgrywki przy pomocy podanego pliku
         * \param kto przynależność (czy należy do nas czy do przeciwnika)
         *               P – należy do nas
         *               E – należy do przeciwnika
        */
        Jednostka(string kto);    

        void wypisz(); 

};




#endif