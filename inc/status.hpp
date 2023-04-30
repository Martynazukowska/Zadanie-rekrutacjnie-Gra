#ifndef STATUS_HPP
#define STATUS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "jednostka.hpp"

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
        */
        Status(const string& plik);  
        
           

        void wypisz();

};




#endif