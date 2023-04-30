#include "../inc/jednostka.hpp"


Jednostka::Jednostka(string kto)
{                          
   przynaleznosc=kto;
}

void Jednostka::wypisz()
{
    cout<<przynaleznosc;
}