#include "../inc/jednostka.hpp"
#include <map>
#include <string>




Jednostka::Jednostka(string kto, string jaka, int identyfikator, int x, int y,int durability)
{                          
   przynaleznosc=kto;

   map<string, Typ> rodzaje = {
        {"K", {70, 5, 400, 1, 5, false,'K'}},       /**< Typ Knight*/
        {"S", {60, 2, 250, 1, 3, false,'S'}},       /**< Typ Swordsman*/
        {"A", {40, 2, 250, 5, 3, false,'A'}},       /**< Typ Archer*/
        {"P", {50, 2, 200, 2, 3, false,'P'}},       /**< Typ Pikeman*/
        {"R", {90, 2, 500, 1, 4, false,'R'}},       /**< Typ Ram*/
        {"C", {50, 2, 800, 7, 6, false,'C'}},       /**< Typ Catapult*/
        {"W", {20, 2, 100, 1, 2, false,'W'}},       /**< Typ Worker*/
        {"B", {200, 0, 0, 0, 0, true,'B'}}          /**< Typ Baza*/
    };


    typ = rodzaje[jaka];            // Przypisanie Typu jednostki
    TYP=typ.TYP;
    ID=identyfikator;               // Przypisanie ID jednostki
    X=x;                            // Przypisanie  polozenia x i y
    Y=y;
    wytrzymałość=durability;        // Przypisywanie wytrzymałości
    

}

void Jednostka::dodaj_produkt(string Product)
{
    //Czy dana jednostka jest bazą
    if(typ.czy_baza)
    {
        map<string, Typ> rodzaje = {
        {"K", {70, 5, 400, 1, 5, false,'K'}},       /**< Typ Knight*/
        {"S", {60, 2, 250, 1, 3, false,'S'}},       /**< Typ Swordsman*/
        {"A", {40, 2, 250, 5, 3, false,'A'}},       /**< Typ Archer*/
        {"P", {50, 2, 200, 2, 3, false,'P'}},       /**< Typ Pikeman*/
        {"R", {90, 2, 500, 1, 4, false,'R'}},       /**< Typ Ram*/
        {"C", {50, 2, 800, 7, 6, false,'C'}},       /**< Typ Catapult*/
        {"W", {20, 2, 100, 1, 2, false,'W'}},       /**< Typ Worker*/
        {"0", {0, 0, 0, 0, 0, false,'0'}}          /**< Typ 0*/
        };
        produkt=rodzaje[Product];
        czas=produkt.czas_budowania;

    }
}

void Jednostka::wypisz()
{
    cout<<"Kogo:         "<<przynaleznosc<<"\n";
    cout<<"Typ: \n"<<typ<<"\n";
    cout<<"ID:           "<<ID<<"\n";
    cout<<"Polozenie:    "<<X<<" "<<Y<<"\n";
    cout<<"Wytrzymalosc: "<<wytrzymałość<<"\n";
    cout<<"\n";
    if(typ.czy_baza)
    {
        cout<<produkt<<"\n";
    }
}

void Jednostka::Nowe_polozenie(int x, int y)
{
    X=x;
    Y=y;
}

void Jednostka::Update_zycia(int wartość)
{
    wytrzymałość=wytrzymałość-wartość;
}




