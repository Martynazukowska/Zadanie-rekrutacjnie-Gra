#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>

#include "../inc/status.hpp"


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
	cout<<"Podaj plik z mapą: ";
	cin>>mapa;
	cout<<"Podaj plik ze statusem gry: ";
	cin>>status;

	int runda=0;
	string gracz;

	while(wybor)
	{
			cout<<"Gracza 1: \n";
			cout<<"Podaj plik z rozkazami dla Gracza 1: ";
			cin>>rozkazy;

			gracz="N";

    		string polecenie = "./" + nazwa_programu_gracza + " " + mapa + " " + status + " " + rozkazy+" "+gracz;

    		if (limit_czasowy > 0) 
			{
        		polecenie += " " + std::to_string(limit_czasowy);
    		}

			//Uruchomienie programu gracza1
    		int status_wyjscia = system(polecenie.c_str());

			cout<<"Gracza 2: \n";
			cout<<"Podaj plik z rozkazami dla Gracza 2: ";
			cin>>rozkazy;

			gracz="E";


    		string polecenie2 = "./" + nazwa_programu_gracza + " " + mapa + " " + status + " " + rozkazy+" "+gracz;

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

			if(runda>=1000)
			{
				wybor=0;
			}
	}

	Status koncowy(status);					// wczytywanie końcowego statusu
	int gracz1=0;
	int gracz2=0;

	//zliczanie jednostek
	for (int i = 0; i < koncowy.get_jednostki().size(); i++)
	{
		if(koncowy.get_jednostki()[i].get_przynaleznosc()=="P")
		{
			gracz2++;					// jeśli jednostka nalezy do gracza 2
		}
		else if(koncowy.get_jednostki()[i].get_przynaleznosc()=="E")
		{
			gracz1++;					// jeśli jednostka należy do gracza 1
		}
	}

	if(gracz1>gracz2)
	{
		cout<<"Wygrywa gracz 1\n";
	}
	else if(gracz1<gracz2)
	{
		cout<<"Wygrywa gracz 2\n";
	}
	else
	{
		cout<<"Remis\n";
	}

	

	//Koniec programu
	return 1;
	
}