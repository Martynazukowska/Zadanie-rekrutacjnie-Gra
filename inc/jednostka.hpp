#ifndef JEDNOSTKA_HPP
#define JEDNOSTKA_HPP

#include <iostream>
#include <string>

using namespace std;

/**
 * \brief Struktura reprezentująca typ jednostki w grze.
 * Typ składa się z kilku pól opisujących cechy jednostki, takie jak wytrzymałość,
 * prędkość, koszt, zasięg i czas budowania. Pole "czy_baza" informuje, czy dana
 * jednostka jest bazą.
 */
struct Typ {
    int wytrzymalosc;           //< Wytrzymałość jednostki. */
    int predkosc;               //< Prędkość jednostki. */
    int koszt;                  //< Koszt zakupu jednostki. */
    int zasieg;                 //< Zasięg jednostki. */
    int czas_budowania;         //< Czas budowania jednostki. */
    bool czy_baza;              //< Czy jednostka jest bazą. */


    /**
    * \brief Przeciążenie operatora << do wypisania wartości pól typu jednostki.
    * Przeciążenie umożliwia wypisanie wartości pól typu jednostki przy pomocy operatora
    * strumieniowego <<.
    * \param os Strumień wyjściowy, do którego mają być wypisane wartości pól.
    * \param typ Obiekt typu jednostki, którego wartości pól mają być wypisane.
    * \return Strumień wyjściowy z wypisanymi wartościami pól typu jednostki.
    */
    friend std::ostream& operator<<(std::ostream& os, const Typ& typ)
    {
        os << "Wytrzymałość: " << typ.wytrzymalosc << std::endl;
        os << "Prędkość: " << typ.predkosc << std::endl;
        os << "Koszt: " << typ.koszt << std::endl;
        os << "Zasięg: " << typ.zasieg << std::endl;
        os << "Czas budowania: " << typ.czas_budowania << std::endl;
        os << "Czy baza: " << (typ.czy_baza ? "tak" : "nie") << std::endl;

        return os;
    }
};

/**
 * \brief Klasa reprezentująca Jednostke
 */

class Jednostka
{
    private:
        string przynaleznosc;       /**< info czy gracza, czy przeciwnika */
        Typ typ;                    /**< typ jednostki */
        bool czy_baza;             /**< info czy jednostka jest baza */

        

    public:
        public:
        /**
        * \brief Konstruktor Statusu rozgrywki przy pomocy podanego pliku
         * \param kto przynależność (czy należy do nas czy do przeciwnika)
         *               P – należy do nas
         *               E – należy do przeciwnika
         * \param typ dzięki, któremu ustawiane są odpowiednio parametry wytrzymałości, 
         *            prędkości, kosztu, zasięgu i czasu budowy
        */
        Jednostka(string kto, string jaka );    

        void wypisz(); 

};






#endif