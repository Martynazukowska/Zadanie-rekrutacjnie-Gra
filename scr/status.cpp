#include "../inc/status.hpp"
#include <fstream>
#include <sstream>


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
            string wartosc_1,wartosc_2,wartosc_3,wartosc_4,wartosc_5,wartosc_6;
            iss >> wartosc_1 >> wartosc_2 >> wartosc_3 >> wartosc_4 >> wartosc_5 >> wartosc_6;
            Jednostka pom(wartosc_1,wartosc_2);
            jednostki.push_back(pom);
            
        }

        file.close(); // zamknięcie pliku
    } 
    else 
    {
        cerr << "Nie udało się otworzyć pliku statusu." << endl;
        exit(1);
        
    }
}


void Status::wypisz()
{
    cout<<zloto<<"\n";
    jednostki[1].wypisz();
    cout<<"\n";
    jednostki[2].wypisz();
    cout<<"\n";
    jednostki[3].wypisz();
}