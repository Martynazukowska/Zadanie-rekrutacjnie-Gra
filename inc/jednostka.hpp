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

        /**
        * \brief Getter dla nazy typu jednostki
        * \return typ
        */
        char  get_typ() const {return TYP;} 
        
        /**
        * \brief Getter dla nazy produktu jednostki
        * \return nazwan produktu
        */
        char  get_produkt() {return czy_produkt;} 

        /**
        * \brief Getter dla typu jednostki
        * \return typ
        */
        Typ  get_caly_typ() const {return typ;} 

        /**
        * \brief Getter dla przynależności jednostki
        * \return przynależność
        */
        string get_przynaleznosc() const { return przynaleznosc;}

        /**
        * \brief Getter dla ID jednostki
        * \return ID
        */
        int  get_ID() const {return ID;} 

        /**
        * \brief Getter dla położenia
        * \return położenie X jednostki
        */
        int  get_X() const {return X;} 

        /**
        * \brief Getter dla położenia
        * \return położenie Y jednostki
        */
        int  get_Y() const {return Y;}

        /**
        * \brief Getter dla pozostałej wytrzymałości jednostki
        * \return wytrzymałość
        */
        int  get_zycie() const {return wytrzymałość;} 

        /**
        * \brief Getter dla typu produkowanej jednostki
        * \return typ
        */
        Typ  get_caly_produkt() const {return produkt;} 

        /**
         * \brief Aktualizuje poziom wytrzymałości jednostki 
         * poprzez zmniejszenie jej wartości o wartość obrażenia.
         * \param wartość Wartość, o którą zostanie zmniejszona wartość wytrzymałości jednostki.
        */
        void  Update_zycia(int wartosc);

        /**
         * \brief Wypisuje informacje na temat jednostki lub bazy.
         * Funkcja ta wypisuje na standardowe wyjście informacje na temat 
         * jednostki lub bazy, takie jak przynależność, typ, identyfikator, 
         * położenie oraz wytrzymałość. W przypadku, gdy jednostka jest bazą, 
         * wypisuje również informacje o produkcie przechowywanym w bazie. 
         * Funkcja jest pomocna podczas debugowania i testowania programu.
        */
        void wypisz();


        /**
         * \brief Ustawia nowe położenie jednostki.
         * Funkcja ta ustawia nowe położenie jednostki, przyjmując jako argumenty dwie wartości 
         * liczbowe reprezentujące koordynaty x i y. Położenie jednostki jest reprezentowane p
         * rzez zmienne X i Y obiektu klasy Jednostka.
         * \param x Wartość liczbowa reprezentująca koordynatę x nowego położenia jednostki.
         * \param y Wartość liczbowa reprezentująca koordynatę y nowego położenia jednostki.
        */
        void Nowe_polozenie(int x, int y);

};






#endif