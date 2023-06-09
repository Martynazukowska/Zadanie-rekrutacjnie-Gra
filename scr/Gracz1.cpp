#include <iostream>
#include <string>
#include "../inc/mapa.hpp"
#include "../inc/status.hpp"


using namespace std;

/**
* \brief Funcja rzetwarza plik tekstowy zawierający rozkazy i wykonuje odpowiednie akcje na mapie gry
* Funkcja Rozkazy przetwarza plik tekstowy zawierający rozkazy i wykonuje odpowiednie akcje na mapie gry.
* \param status_R Referencja do obiektu klasy Status, przechowującego aktualny stan gry
* \param mapa_R Referencja do obiektu klasy plansza, przechowującego mapę gry
* \param plik Nazwa pliku tekstowego zawierającego rozkazy
*
* \return void
* \note Funkcja wywołuje funkcję exit z kodem 0 lub 1 w przypadku wystąpienia błędów
*
*/

void Rozdkazy(Status &status_R, plansza &mapa_R, const string& plik,string kto)
{
    ifstream file(plik); 

    mapa_R.UPDATE(status_R.get_jednostki());           //Zaktualizuj mapę
    mapa_R.wypisz_plansze();                           

    if (file.is_open()) // sprawdzenie, czy plik został otwarty
    { 
        string line;

        //vector<Akcja> ruch;                   //Przyszły wektor wszystkich rozkazów

        while (getline(file, line)) 
        {
            // przetwarzanie linii
            istringstream iss(line);
            int w1;
            string w2;

            iss >> w1 >> w2;

            int ID=w1;
            string nazwa=w2;

            //jesli Akcja jest 
            if(nazwa=="M")                     //Move
            {
                int X,Y;
                iss>>X>>Y;
                if(X>=mapa_R.get_X()||Y>=mapa_R.get_Y())
                {
                    cerr<<"Wyszedłeś poza mapę\n";
                    exit(0);
                }
                Move move(ID,'M',X,Y);
                status_R.UWAGA(mapa_R,move);
                
            }
            else if(nazwa=="A")               //Atack
            {
                int id_A;
                iss>>id_A;
                Atak atak(ID,'A',id_A);
                status_R.UWAGA(mapa_R,atak,kto);

            }
            else if(nazwa=="B")                   //Build
            {
                string Nowa_jednostka;
                iss>>Nowa_jednostka;
                Budowanie budowa(ID,'B',Nowa_jednostka);
                status_R.UWAGA(mapa_R,budowa);
            }
            else
            {
                cerr<<"Błąd w nazwie Rozkazu\n";
                exit(0);
            }
        }
        file.close(); // zamknięcie pliku
    } 
    else 
    {
        cerr << "Nie udało się otworzyć pliku rozkazy." << endl;
        exit(1);
        
    } 
}

int main(int argc, char *argv[]) 
{
    //Wypisz wszytskie argumenty programu
    cout << "Liczba argumentów: " << argc << std::endl;
    cout << "Argumenty: ";
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << " ";
    }
    cout << std::endl;

    //Inicjalizacja Mapy
    plansza Mapa("../pliki/"+ string(argv[1]));


    //Inicjalizacja Statusu
    Status status("../pliki/"+ string(argv[2]));
    //status.wypisz(2);

    status.dodaj_zloto(Mapa.czy_kopie());       //Dolicz dodatkowo złoto z kopalni
    

    //Wczytywanie rozkazów 
    Rozdkazy(status,Mapa,"../pliki/"+ string(argv[3]),string(argv[4]));

    Mapa.UPDATE(status.get_jednostki());           //Zaktualizuj mapę
    Mapa.wypisz_plansze();
    
    //Zapisz nowy status gry do pliku
    status.zapisz("../pliki/"+ string(argv[2]));



    return 0;
}