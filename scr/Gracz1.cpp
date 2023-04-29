#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) 
{
    //Wypisz wszytskie argumenty programu
    cout << "Liczba argumentów: " << argc << std::endl;
    cout << "Argumenty: ";
    for (int i = 0; i < argc; i++) {
        cout << argv[i] << " ";
    }
    cout << std::endl;
    return 0;
}