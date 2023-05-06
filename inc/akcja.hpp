#ifndef AKCJA_HPP
#define AKCJA_HPP

#include <iostream>
#include <string>
#include <vector>
#include "jednostka.hpp"

using namespace std;

class Akcja {
private:
    int ID;
    char nazwa;
public:
    Akcja(int id, char n) : ID(id), nazwa(n) {}
    int  get_nazwa() const {return nazwa;} 
    int  get_ID() const {return ID;} 
    //virtual void wprowadz() = 0;
    //virtual vector<string> przekaz() = 0;
};

class Move : public Akcja {
private:
    int X;
    int Y;

public:
    Move(int id, char n,int x,int y) : Akcja(id, n) , X(x), Y(y) {}
    int  get_X() const {return X;} 
    int  get_Y() const {return Y;} 
};  

class Atak : public Akcja {
private:
    int ID_ataku;

public:
    Atak(int id, char n, int id_A) : Akcja(id, n), ID_ataku(id_A) {}

    int  get_ID_ataku() const {return ID_ataku;} 
};

class Budowanie : public Akcja {
private:
    Typ typ;
    string nazwa_J;

public:
    Budowanie(int id, char n,string J) : Akcja(id, n), nazwa_J(J){}

    Typ  get_caly_typ() const {return typ;} 

    string  get_nazwa_jednostki() const {return nazwa_J;} 

};




#endif