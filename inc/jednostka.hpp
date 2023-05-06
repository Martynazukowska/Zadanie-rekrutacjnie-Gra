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
    char TYP;                   //< Typ w nazwie*/

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
        os << typ.TYP<<endl;
        os << "Wytrzymałość: " << typ.wytrzymalosc << endl;
        os << "Prędkość: " << typ.predkosc << endl;
        os << "Koszt: " << typ.koszt << endl;
        os << "Zasięg: " << typ.zasieg << endl;
        os << "Czas budowania: " << typ.czas_budowania << endl;
        os << "Czy baza: " << (typ.czy_baza ? "tak" : "nie") << endl;

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
        char TYP;                   /**< typ jednostki */
        int ID;                     /**< ID jednostki */
        int X;                      /**< Polożenie X jednostki */
        int Y;                      /**< Polożenie Y jednostki */
        int wytrzymałość;           /**< Wytrzymałość jednostki */
        Typ produkt;                /**< Produkt jednostki */
        char czy_produkt;           /**< Zmienna informująca czy produkt jest tworzony*/
        int czas;                   /**<Czas pozostały do wyprodukowania jednostki*/

        

    public:
        public:
        /**
        * \brief Konstruktor Statusu rozgrywki przy pomocy podanego pliku
         * \param kto przynależność (czy należy do nas czy do przeciwnika)
         *               P – należy do nas
         *               E – należy do przeciwnika
         * \param typ dzięki, któremu ustawiane są odpowiednio parametry wytrzymałości, 
         *            prędkości, kosztu, zasięgu i czasu budowy
         * \param identyfikator definiuje ID danej jednostki
         * \param x polozenie jednostki na mapie wzgledem osi X
         * \param y polozenie jednostki na mapie wzgledem osi Y
         * \param durability wytrzymałość jednostki 
        */
        Jednostka(string kto, string jaka, int identyfikator, int x, int y, int durability); 


        /**
        * \brief Funkcja dodająca produkt do bazy 
        * \param product jednostka produkowana przez bazę (K/S/A/P/C/R/W) Lub 0 gdy nic nie produkuje.
        */
        void dodaj_produkt(string Product); 

        char  get_typ() const {return TYP;} 

        char  get_produkt() {return czy_produkt;} 

        Typ  get_caly_typ() const {return typ;} 

        string get_przynaleznosc() const { return przynaleznosc;}

        int  get_ID() const {return ID;} 

        int  get_X() const {return X;} 

        int  get_Y() const {return Y;}
        
        int  get_zycie() const {return wytrzymałość;} 

        Typ  get_caly_produkt() const {return produkt;} 


        void  Update_zycia(int wartosc);



        void wypisz();

        void Nowe_polozenie(int x, int y);

};






#endif