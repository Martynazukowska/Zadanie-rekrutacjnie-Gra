#ifndef AKCJA_HPP
#define AKCJA_HPP

#include <iostream>
#include <string>
#include <vector>
#include "jednostka.hpp"

using namespace std;

/**
 * \class Akcja
 * \brief Klasa reprezentująca akcję w grze.
 * Klasa Akcja służy do przechowywania i przetwarzania rozkazóœ wykonanych w grze.
 * Obiekt tej klasy składa się z identyfikatora jednostki, na której ma zostać wykonana akcja,\
 * oraz nazwy akcji. Klasa Akcja posiada także metody dostępu do tych pól.
 * */
class Akcja {
private:
    int ID;                  //< identyfikator jednostki, na której ma zostać wykonana akcja
    char nazwa;              //< nazwa akcji
public:
    /**
    * \brief Konstruktor klasy Akcja.
    * Konstruktor tworzy obiekt klasy Akcja z zadanym ID i nazwą.
    * \param id ID jednostki, której dotyczy rozkaz.
    * \param n Nazwa rozkazu.
    */
    Akcja(int id, char n) : ID(id), nazwa(n) {}
    /**
    * \brief Getter dla nazwy.
    * \return nazwa bywranego rozkazu
    */
    char  get_nazwa() const {return nazwa;} 

    /**
    * \brief Getter dla ID.
    * \return ID jednoski której dotyczy rozkaz
    */
    int  get_ID() const {return ID;} 
    //virtual void wprowadz() = 0;
    //virtual vector<string> przekaz() = 0;
};


/**
 * \class Move
 * \brief Klasa reprezentująca akcję przesunięcia jednostki.
 * Klasa ta dziedziczy publicznie po klasie Akcja i dodaje pola X i Y 
 * oraz metody get_X() i get_Y() służące do pobierania położenia jednostki po przesunięciu.
*/

class Move : public Akcja {
private:
    int X;      //< Nowe położenie X jednostki po przesunięciu.
    int Y;      //< Nowe położenie Y jednostki po przesunięciu.

public:
    /**
     * \brief Konstruktor klasy Move.
     * Konstruktor tworzy obiekt klasy Move z zadanymi ID, nazwą, X i Y.
     * \param id ID jednostki, której dotyczy rozkaz.
     * \param n Nazwa rozkazu.
     * \param x Nowe położenie X jednostki po przesunięciu.
     * \param y Nowe położenie Y jednostki po przesunięciu.
     */
    Move(int id, char n,int x,int y) : Akcja(id, n) , X(x), Y(y) {}

    /**
     * \brief Getter położenia jednostki po przesunięciu.
     * \return Nowe położenie X
     */
    int  get_X() const {return X;}

    /**
     * \brief Getter położenia jednostki po przesunięciu.
     * \return Nowe położenie Y
     */
    int  get_Y() const {return Y;} 
};  


/**
 * \class Atak
 * \brief Klasa reprezentująca akcję ataku na jednostkę przeciwnika.
 *  Klasa dziedziczy po klasie Akcja i dodatkowo przechowuje ID jednostki,
 * która jest celem ataku.
    */
class Atak : public Akcja {
private:
    int ID_ataku;       /**< ID jednostki będącej pod atakiem */

public:
    /**
     * \brief Konstruktor klasy Atak
     * \param id ID jednostki, która wykonuje atak
     * \param n Nazwa rozkazu
     * \param id_A ID jednostki będącej pod atakiem
     * */
    Atak(int id, char n, int id_A) : Akcja(id, n), ID_ataku(id_A) {}

    /**
     * \brief Getter ID jednostki będącej pod atakiem 
     * \return ID
     */
    int  get_ID_ataku() const {return ID_ataku;} 
};


/**
 * \class Budowanie
 * \brief Klasa reprezentująca akcję budowania nowej jednostki.
 * Klasa dziedziczy po klasie Akcja i dodatkowo przechowuje nazwę oraz typ
 * jednostki, która ma zostać wyprodukowana.
*/
class Budowanie : public Akcja {
private:
    Typ typ;            /**< Typ jednostki, która ma zostać wyprodukowana */
    string nazwa_J;     /**< Nazwa jednostki, która ma zostać wyprodukowana */

public:
    /**
     * \brief Konstruktor klasy Budowanie
     * \param id ID jednostki, która wykonuje akcję budowania
     * \param n Nazwa rozkazu
     * \param J Nazwa jednostki, która ma zostać wyprodukowana
     * */
    Budowanie(int id, char n,string J) : Akcja(id, n), nazwa_J(J){}

    /**
     * \brief Getter typu produkowanej jednostki
     * \return Typ jednostki
     */
    Typ  get_caly_typ() const {return typ;} 

    /**
        * \brief Getter typu w formie string
        * \return Typ jednostki
        */
    string  get_nazwa_jednostki() const {return nazwa_J;} 

};




#endif