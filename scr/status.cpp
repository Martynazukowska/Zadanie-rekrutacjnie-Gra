#include "../inc/status.hpp"
#include <fstream>
#include <sstream>
#include <string.h>

Status::Status(const string& plik)
{                          
    ifstream file(plik); 


    if (file.is_open()) // sprawdzenie, czy plik został otwarty
    { 
        string line;
        getline(file, line);
        zloto=stoi(line);

        while (getline(file, line)) {
            // przetwarzanie linii
            istringstream iss(line);
            string w1,w2,w7;
            int w3,w4,w5,w6;

            iss >> w1 >> w2 >> w3 >> w4 >> w5 >> w6;

            //jesli jednostka jest baza
            if(w2=="B")
            {
                iss >>w7;
            }
            Jednostka pom(w1,w2,w3,w4,w5,w6);           // stwórz jednostkę
            pom.dodaj_produkt(w7);                      // dodaj produkty do baz 
            jednostki.push_back(pom);                   // dodaj jednostke do wektora
            
        }

        file.close(); // zamknięcie pliku
    } 
    else 
    {
        cerr << "Nie udało się otworzyć pliku statusu." << endl;
        exit(1);
        
    }
}

void Status::zapisz(const string& plik)
{                          
    // Otwórz plik do zapisu
    ofstream outfile(plik);

    // Sprawdź, czy pliki zostały poprawnie otwarte
    if (!outfile.is_open()) {
        cerr << "Nie udało się otworzyć pliku wyjściowego" << std::endl;
        exit(1);
    }

    // Zapisz dane do pliku
    outfile<<zloto<<"\n";
    for (const auto& liczba : jednostki) {
        outfile << liczba.get_przynaleznosc()<< " "<<liczba.get_typ()<<" "<<liczba.get_ID()<<" "<<liczba.get_X()<<" "<<liczba.get_Y()<<" "<<liczba.get_zycie();
        if(liczba.get_typ()=='B')
        {
            outfile<<" "<<liczba.get_caly_produkt().TYP<<"\n";
        }
        else
        {
            outfile<<"\n";
        }
    }

    // Zamknij plik
    outfile.close();
}



void Status::wypisz(int index)
{
    cout<<zloto<<"\n";
    jednostki[index].wypisz();
    cout<<"\n";
    
}

int Status::Czy_ID_występuje(int id)
{
    for (int i = 0; i < jednostki.size(); i++)
    {
        if(jednostki[i].get_ID()==id)
        {
            return i+1;
        }
    }

    return 0;
    
}



void Status::UWAGA(plansza Mapa,Move move)
{
    Mapa.UPDATE(get_jednostki());                          //Zaaktualizuj mapę
    int pom_id;
    pom_id=Czy_ID_występuje(move.get_ID());                 //Sprawdź czy taka jednosta istanieje
    if(pom_id==0)
    {
        cerr<<"Nie ma takiej jednostki\n";
        exit(1);
    }
    int ruch=jednostki[pom_id-1].get_caly_typ().predkosc;

    if(abs(jednostki[pom_id-1].get_X()-move.get_X())>ruch-1 || abs(jednostki[pom_id-1].get_Y()-move.get_Y())>ruch-1 )
    {
        cerr<<"Nie możesz zrobić takiego ruchu tą jednostka";
        exit(1);
    }
    
    Mapa.UPDATE(get_jednostki());                          //Zaaktualizuj mapę
    if(Mapa.czy_puste(move.get_X(),move.get_Y()))
    {
        jednostki[pom_id-1].Nowe_polozenie(move.get_X(),move.get_Y());      //Zmień położenie wybranej jednostki
        Mapa.UPDATE(get_jednostki());                      //Zaaktualizuj mapę
        Mapa.wypisz_plansze();
    }

    //Jeśli na mapie cos już coś jest w tym miejscu
    else
    {
        cerr<<"Błąd coś już tam stoi\n";
        exit(0);
    }


}

void Status::UWAGA(plansza Mapa,Atak atak)
{
    int pom_id,pom_id_przeciwnika;
    pom_id=Czy_ID_występuje(atak.get_ID());                 //Sprawdź czy twoja jednosta istanieje
    if(pom_id==0)
    {
        cerr<<"Atakujący nie istanieje \n";
        exit(1);
    }

    pom_id_przeciwnika=Czy_ID_występuje(atak.get_ID_ataku());                 //Sprawdź czy jednosta do ataku istanieje
    if(pom_id_przeciwnika==0)
    {
        cerr<<"Atakowany nie istanieje \n";
        exit(1);
    }

    int zasieg=jednostki[pom_id-1].get_caly_typ().zasieg;

    if(abs(jednostki[pom_id-1].get_X()-jednostki[pom_id_przeciwnika-1].get_X())>zasieg || abs(jednostki[pom_id-1].get_Y()-jednostki[pom_id_przeciwnika-1].get_Y())>zasieg )
    {
        cerr<<"Nie możesz zrobić takiego ruchu tą jednostka\n";
        cerr<<"Twoj zasięg jest za mały\n";
        exit(1);
    }

    int tabela_ataków[7][8]={{35,35,35,35,35,50,35,35},
                            {30,30,30,20,20,30,30,30},
                            {15,15,15,15,10,10,15,15},
                            {35,15,15,15,15,10,15,10},
                            {40,40,40,40,40,40,40,50},
                            {10,10,10,10,10,10,10,50},
                            {5,5,5,5,5,5,5,1}};

    char atakujacy = jednostki[pom_id-1].get_caly_typ().TYP;
    char atakowany = jednostki[pom_id_przeciwnika-1].get_caly_typ().TYP;

    map<char, int> rodzaje = {
        {'K', {0}},       /**< Typ Knight*/
        {'S', {1}},       /**< Typ Swordsman*/
        {'A', {2}},       /**< Typ Archer*/
        {'P', {3}},       /**< Typ Pikeman*/
        {'R', {5}},       /**< Typ Ram*/
        {'C', {4}},       /**< Typ Catapult*/
        {'W', {6}},       /**< Typ Worker*/
        {'B', {7}}        /**< Typ Baza*/
    };

     int index_x = rodzaje[atakowany];            // Przypisanie Typu jednostki
     int index_y = rodzaje[atakujacy];            // Przypisanie Typu jednostki

     int obrazenia = tabela_ataków[index_y][index_x];   // Jakie atakujący daje obrazenia wybranej jednostce 

    cout<<"Życie:       "<<jednostki[pom_id_przeciwnika-1].get_zycie()<<"\n";

    cout<<"Obrazenia:    "<<obrazenia<<"\n";

    jednostki[pom_id_przeciwnika-1].Update_zycia(obrazenia);

    cout<<"Nowe życie:       "<<jednostki[pom_id_przeciwnika-1].get_zycie()<<"\n";
     
     if(jednostki[pom_id_przeciwnika-1].get_zycie()<=0)
     {
        if(jednostki[pom_id_przeciwnika].get_caly_typ().TYP=='B')
        {
            cout<<"\n";
            cout<<"WYGRANA !!!!!!";
            cout<<"\n";
            exit(1);
        }
        jednostki.erase(jednostki.begin()+pom_id_przeciwnika-1);

     }
    Mapa.UPDATE(get_jednostki());                          //Zaaktualizuj mapę
    Mapa.wypisz_plansze();

}

void Status::UWAGA(plansza Mapa,Budowanie budowa)
{
    Mapa.UPDATE(get_jednostki());                          //Zaaktualizuj mapę
    int pom_id;
    pom_id=Czy_ID_występuje(budowa.get_ID());                 //Sprawdź czy taka jednosta istanieje
    if(pom_id==0)
    {
        cerr<<"Nie ma takiej jednostki\n";
        exit(1);
    }
    if(jednostki[pom_id-1].get_caly_typ().TYP!='B')          //Sprawdz czy jednostka jest Bazą
    {
        cerr<<"Jednosta wybrana do budowania nie jest Baza.      Koniec działań.\n";
        exit(0);
    }
    string pom=budowa.get_nazwa_jednostki();
    jednostki[pom_id-1].dodaj_produkt(pom);
}


void Status::Dodaj_Jednostke(string kto, string jaka, int identyfikator, int x, int y)
{
    map<string, int> rodzaje = {
        {"K", {70}},       /**< Typ Knight*/
        {"S", {60}},       /**< Typ Swordsman*/
        {"A", {40}},       /**< Typ Archer*/
        {"P", {50}},       /**< Typ Pikeman*/
        {"R", {90}},       /**< Typ Ram*/
        {"C", {50}},       /**< Typ Catapult*/
        {"W", {20}},       /**< Typ Worker*/
        {"B", {200}}        /**< Typ Baza*/
    };

    int wytrzyma = rodzaje[jaka];            // Przypisanie Wytrzymałości
    Jednostka nowa(kto,jaka,identyfikator,x,y,wytrzyma);
    jednostki.push_back(nowa);
}