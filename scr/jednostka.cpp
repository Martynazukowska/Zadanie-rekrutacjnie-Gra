#include "../inc/jednostka.hpp"
#include <map>
#include <string>




Jednostka::Jednostka(string kto, string jaka)
{                          
   przynaleznosc=kto;
   czy_baza=false;

   map<string, Typ> rodzaje = {
        {"K", {70, 5, 400, 1, 5, false}},       /**< Typ Knight*/
        {"S", {60, 2, 250, 1, 3, false}},       /**< Typ Swordsman*/
        {"A", {40, 2, 250, 5, 3, false}},       /**< Typ Archer*/
        {"P", {50, 2, 200, 2, 3, false}},       /**< Typ Pikeman*/
        {"R", {90, 2, 500, 1, 4, false}},       /**< Typ Ram*/
        {"C", {50, 2, 800, 7, 6, false}},       /**< Typ Catapult*/
        {"W", {20, 2, 100, 1, 2, false}},       /**< Typ Worker*/
        {"B", {200, 0, 0, 0, 0, true}}          /**< Typ Baza*/
    };

    typ = rodzaje[jaka];
}

void Jednostka::wypisz()
{
    cout<<przynaleznosc<<"\n";
    cout<<typ;
}