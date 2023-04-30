#include "../inc/status.hpp"
#include <fstream>

/**
 * \brief Konstruktor statusu rozgrywki, wczytuje stan planszy z pliku
 * \param plik ścieżka do pliku z danymi planszy
 * \throws std::runtime_error jeśli nie uda się otworzyć pliku
 */
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
            int spacja = line.find(" ");
            string wartosc_1 = line.substr(0, spacja);          //przynależność jednostki
            string wartosc_2 = line.substr(spacja + 1);
            Jednostka pom(wartosc_1);
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
    jednostki[0].wypisz();
}