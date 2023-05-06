#include <iostream>
#include <string>
#include "../inc/mapa.hpp"
#include "../inc/status.hpp"


using namespace std;

void Rozdkazy(Status &status_R, plansza &mapa_R, const string& plik)
{
    ifstream file(plik); 

    mapa_R.UPDATE(status_R.get_jednostki());           //Zaktualizuj mapę

    if (file.is_open()) // sprawdzenie, czy plik został otwarty
    { 
        string line;
        getline(file, line);

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
                if(X>=ROZMIAR_X||Y>=ROZMIAR_Y)
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
                status_R.UWAGA(mapa_R,atak);

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

        mapa_R.wypisz_plansze();

        file.close(); // zamknięcie pliku
    } 
    else 
    {
        cerr << "Nie udało się otworzyć pliku rozkazy." << endl;
        exit(1);
        
    } 
    // int ID;
    // char nazwa;

    // mapa_R.UPDATE(status_R.get_jednostki());   
    // mapa_R.wypisz_plansze();

    // cout<<"Czas na rozkazy: \n";
    // cout<<"Podaj ID jednostki: ";
    // cin>>ID;
    // cout<<"\n";
    // int pom=status_R.Czy_ID_występuje(ID);         
    // status_R.get_jednostki()[pom-1].wypisz();

    // cout<<"Podaj nazwę ruchu: ";
    // cin>>nazwa;

    // if(nazwa=='M')
    // {
    //     Move move(ID,nazwa);
    //     move.wprowadz();
    //     status_R.UWAGA(mapa_R,move);
    // }
    // else if(nazwa=='A')
    // {
    //     Atak atak(ID,nazwa);
    //     atak.wprowadz();
    //     status_R.UWAGA(mapa_R,atak);
    // }
    // else if(nazwa=='B')
    // {
    //     Budowanie budowa(ID,nazwa);
    //     budowa.wprowadz();
    //     status_R.UWAGA(mapa_R,budowa);
    // }
    // else
    // {
    //     cerr<<"Błąd w nazwie Rozkazu\n";
    //     exit(0);
    // }
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
    //Mapa.wypisz_plansze();

    //Inicjalizacja Statusu
    Status status("../pliki/"+ string(argv[2]));
    //status.wypisz(2);

    Rozdkazy(status,Mapa,"../pliki/"+ string(argv[3]));

    status.zapisz("../pliki/"+ string(argv[2]));






    return 1;
}