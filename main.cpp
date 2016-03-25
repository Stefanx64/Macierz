#include <iostream>
#include "macierz.h"
#include <cstdlib>
#include <exception>
#include <utility>

using namespace std;

//deklaracje funkcji
void Menu();
int wartosc(int);
double wartoscd(double);

Macierz pobierzMacierz()
{
    int row, column;
    double wart;
    int zgoda;
    
    bool ok = false;
    while( !ok )    // dopoki uzytkownik nie wprowadzi popraw
    {
        ok = true;
        try 
        {
            cout<<"Wybierz: \n[1] Czy chcesz wstawic liczby do macierzy?\n[2] Czy chcesz wpisac elementy macierzy jednym ciagiem:"
            <<"\n[3] Czy chcesz wypelnic cala macierz jedna liczba (domyslne)?"<<endl;
            cin>>zgoda;
            if (zgoda==2)
            {
                cout <<"Instrukcje wprowadzania:\nStart macierzy: '[' koniec macierzy: ']'\n"
 <<"' ' badz ',' - kolejne elementy wiersza\n';' - nastepny wiersz, znak inny niz liczba jest traktowany jako 0"
 <<"\nnp. [1, 2, 3; 4, 5, 6]"<<endl;
                Macierz m;
                cin>>m;
                return move(m);
            }
            cout << "Podaj dane macierzy"<<endl;
            cout << "Podaj liczbe wierszy: ";
            row=wczytajLiczbe<int>();
            cout<< "Podaj liczbe kolumn: ";
            column=wczytajLiczbe<int>();
            
            if (zgoda!=1)
            {
                cout<<"Wprowadz liczbe, ktora ma wypelnic cala macierz: "<<endl;
                wart=wczytajLiczbe<double>();
            }
            Macierz m (row,column,wart);
            if (zgoda==1)
            {
                m.wprowadz();
            }
            return move(m);
        }
        catch(exception& e) 
        {
            cout << "== BLAD : "<< e.what() << endl<<endl;
            ok = false;
        }          
    }
}


int main(int argc, char **argv)
{//Zrobic wyczytywanie matlabowe
    double skalar;
    int operacja;
    Menu();
    while(1)    
    {
        try
        {
            Macierz pierwsza = pobierzMacierz();
            pierwsza.wyswietl();
            do
            {
                cout << "wybierz komende: ";
                operacja=wczytajLiczbe<int>();
            } 
            while (((operacja <= 0) || (operacja > 18))); 
            if ((operacja == 1) || (operacja == 2) || (operacja == 3) )
            {
                Macierz druga = pobierzMacierz();
                druga.wyswietl();
                switch (operacja)
                {
                case 1:
                    cout << (pierwsza + druga) << endl;
                    break;
                case 2:
                    cout << pierwsza - druga << endl;
                    break;
                case 3:
                    cout << pierwsza * druga << endl;
                    break;
                }
            }
            else if (operacja == 4)
            {
                cout << "podaj liczbe: ";
                skalar=wczytajLiczbe<double>();
                cout << skalar * pierwsza << endl;
            }
            
            if (operacja>=18)
            {
                return 0;
            }
            
            switch (operacja)
            {
            int ktory,element;
            case 5:
                cout << "Wyznacznik macierzy to: "<<(pierwsza.wyznacznik()) << endl;
                break;
            case 6:
                pierwsza.t();
                cout << pierwsza << endl;
                break;
            case 7:
                pierwsza.invert();
                cout << pierwsza << endl;
                break;
            case 8:
                pierwsza.dodajwiersz();
                cout << pierwsza << endl;
                break;
            case 9:
                pierwsza.dodajkolumne();
                cout << pierwsza << endl;
                break;
            case 10:
                pierwsza.usunwiersz();
                cout << pierwsza << endl;
                break;
            case 11:
                pierwsza.usunkolumne();
                cout << pierwsza << endl;
                break;
            case 12:
                pierwsza.usunmacierz();
                cout << pierwsza << endl;
                break;
            case 13:
                pierwsza.wprowadz();
                cout << pierwsza << endl;
                break;
            case 14:
                cout<<"Ktory wiersz ma byc zmodyfikowany: "<<endl;
                ktory=wczytajLiczbe<int>();
                pierwsza.wprowadz(ktory);
                cout << pierwsza << endl;
                break;
            case 15:
                cout<<"Element, ktorego wiersza ma byc zmodyfikowany: "<<endl;
                ktory=wczytajLiczbe<int>();
                cout<<"Element, ktorej kolumny ma byc zmodyfikowany: "<<endl;
                element=wczytajLiczbe<int>();
                pierwsza.wprowadz(ktory,element);
                cout << pierwsza << endl;
                break;
            case 16:
                cout << pierwsza << endl;
                break;
            case 17:
                pierwsza.wyswietlrozmiar();
                break;
            case 18:
                cout << "Koniec programu" << endl;
                break; 
            }
        }
        catch(exception& e)
        {
            cout << "== BLAD : "<< e.what() << endl<<endl;
        } 
    }
    return 0;
}

void Menu( void )
{
    cout<<  "Program wykonujacy operacje na macierzach\n"
            "Wybierz operacje:\n" 
            "1. Dodawanie\n" 
            "2. Odejmowanie\n" 
            "3. Mnozenie\n" 
            "4. Mnozenie przez skalar.\n" 
            "5. Wyznacznik macierzy\n" 
            "6. Transpozycja\n" 
            "7. Macierz odwrotna\n" 
            "8. Dodanie wiersza\n" 
            "9. Dodanie kolumny\n" 
            "10. Usuniecie wiersza\n" 
            "11. Usuniecie kolumny\n" 
            "12. Usuniecie macierzy\n" 
            "13. Zmodyfikuj dane macierzy\n" 
            "14. Zmodyfikuj wiersz macierzy\n" 
            "15. Zmodyfikuj element macierzy\n" 
            "16. Wyswietl macierz\n" 
            "17. Wyswietl rozmiar macierzy\n" 
            "18. Wyjdz\n\n" << endl;
}
