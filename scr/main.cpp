#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>


using namespace std;

int main( int argc, char* args[] )
{
	cout<<" 1 . graj\n";
	cout<<" 0 . wyjdz\n";
	int wybor;

	cin>>wybor;

	if(wybor!=0&&wybor!=1)
	{
		cerr<<"Nie znam takiej wartości :(\n";
		return 1;
	}

	cout<<" Zaczynajmy zabawe\n";

	//Zainicjowanie Programu Gracza 1
	string nazwa_programu_gracza,mapa,status,rozkazy;
    int limit_czasowy = 1000;                               // opcjonalny limit czasowy w milisekundach

	cout<<"Podaj nazwę programu Gracza 1: ";
	cin>>nazwa_programu_gracza;

	while(wybor)
	{
			cout<<"Gracza 1: \n";
			cout<<"Podaj plik z mapą: ";
			cin>>mapa;
			cout<<"Podaj plik ze statusem gry: ";
			cin>>status;
			cout<<"Podaj plik z rozkazami dla Gracza 1: ";
			cin>>rozkazy;


    		string polecenie = "./" + nazwa_programu_gracza + " " + mapa + " " + status + " " + rozkazy;

    		if (limit_czasowy > 0) 
			{
        		polecenie += " " + std::to_string(limit_czasowy);
    		}

			//Uruchomienie programu gracza1
    		int status_wyjscia = system(polecenie.c_str());

			cout<<"Gracza 2: \n";
			cout<<"Podaj plik z mapą: ";
			cin>>mapa;
			cout<<"Podaj plik ze statusem gry: ";
			cin>>status;
			cout<<"Podaj plik z rozkazami dla Gracza 2: ";
			cin>>rozkazy;


    		string polecenie2 = "./" + nazwa_programu_gracza + " " + mapa + " " + status + " " + rozkazy;

    		if (limit_czasowy > 0) 
			{
        		polecenie2 += " " + std::to_string(limit_czasowy);
    		}

			//Uruchomienie programu gracza
    		status_wyjscia = system(polecenie2.c_str());

			//Jeśli pojawią się błedy przy uruchomieniu programu gracza1
    		if (status_wyjscia != 0) 
			{
        		cerr << "Błąd uruchamiania programu gracza1" << std::endl;
        		return 1;
    		}
	}
	

	//Koniec programu
	return 1;
	
}