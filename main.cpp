#include <iostream>
#include "macierz.h"
#include <cstdlib>

using namespace std;

//deklaracje funkcji
void Menu();
int wartosc(int);
double wartoscd(double);
//void wynik(Macierz, int, Macierz=0,double=0);


int main(int argc, char **argv)
{
    int row, column;
    double wart, skalar;
    int operacja;
    int zgoda;

    Menu();
    while(1)
    {
        cout << "Podaj dane pierwszej macierzy"<<endl;
        cout << "Podaj liczbę wierszy: ";
        row=wartosc(row);
        cout<< "Podaj liczbę kolumn: ";
        column=wartosc(column);
        cout<<"Wybierz: \n[1] Czy chcesz wstawic liczby do macierzy?\n[2] Czy chcesz wypelnic cala macierz jedna liczba (domyslne)?"<<endl;
        zgoda=wartosc(zgoda);
        if (zgoda!=1)
        {
            cout<<"Wprowadz liczbe, ktora ma wypelnic cala macierz: "<<endl;
            wart=wartoscd(wart);
        }
        Macierz pierwsza(row,column,wart);
        wart=0;
        if (zgoda==1)
        {
            pierwsza.wprowadz();
        }        
        pierwsza.wyswietl();
        do
        {
            cout << "wybierz komende: ";
            cin.clear();
            cin.sync();
            cin >> operacja;
        } while (((operacja < 0) && (operacja > 19))); 
        if ((operacja == 1) || (operacja == 2) || (operacja == 3) )
        {
            cout << "Podaj dane drugiej macierzy"<<endl;
            cout << "Podaj liczbę wierszy: ";
            row=wartosc(row);
            cout<< "Podaj liczbę kolumn: ";
            column=wartosc(column);
            cout<<"Wybierz: \n[1] Czy chcesz wstawic liczby do macierzy?\n[2] Czy chcesz wypelnic cala macierz jedna liczba (domyslne)?"<<endl;
            zgoda=wartosc(zgoda);
            if (zgoda!=1)
            {
                cout<<"Wprowadz liczbe, ktora ma byc wypelniona macierz: "<<endl;
                wart=wartoscd(wart);
            }
            Macierz druga(row,column,wart);
            if (zgoda==1)
            {
                druga.wprowadz();
            }
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
            skalar=wartosc(skalar);
            cout << skalar * pierwsza << endl;
        }
        
        if (operacja>=18)
        {
            exit(0);
        }
        
        switch (operacja)
        {
        int ktory,element;
        /*case 1:
            cout << (pierwsza + druga) << endl;
            break;
        case 2:
            cout << pierwsza - druga << endl;
            break;
        case 3:
            cout << pierwsza * druga << endl;
            break;
        case 4:
            cout << skalar * pierwsza << endl;
            break;*/
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
            ktory=wartosc(ktory);
            pierwsza.wprowadz(ktory);
            cout << pierwsza << endl;
            break;
        case 15:
            cout<<"Element, ktorego wiersza ma byc zmodyfikowany: "<<endl;
            ktory=wartosc(ktory);
            cout<<"Element, ktorej kolumny ma byc zmodyfikowany: "<<endl;
            element=wartosc(element);
            pierwsza.wprowadz(ktory,element);
            cout << pierwsza << endl;
            break;
        case 16:
            cout << pierwsza << endl;
            break;
        case 17:
            cout <<"Liczba wierszy macierzy: "<< pierwsza.lwierszy()<<"  Liczba kolumn macierzy: "<<pierwsza.lkolumn() << endl;
            break;
        case 18:
            cout << "Koniec programu" << endl;
            break; 
        }
    }
    return 0;
}

void Menu( void )
{
    cout<<"Program wykonujacy operacje na macierzach"<<endl;
    cout << "Wybierz operacje:" << endl;
    cout << "1. Dodawanie" << endl;
    cout << "2. Odejmowanie" << endl;
    cout << "3. Mnozenie" << endl;
    cout << "4. Mnozenie przez skalar." << endl;
    cout << "5. Wyznacznik macierzy" << endl;
    cout << "6. Transpozycja" << endl;
    cout << "7. Macierz odwrotna" << endl;
    cout << "8. Dodanie wiersza" << endl;
    cout << "9. Dodanie kolumny" << endl;
    cout << "10. Usuniecie wiersza" << endl;
    cout << "11. Usuniecie kolumny" << endl;
    cout << "12. Usuniecie macierzy" << endl;
    cout << "13. Zmodyfikuj dane macierzy" << endl;
    cout << "14. Zmodyfikuj wiersz macierzy" << endl;
    cout << "15. Zmodyfikuj element macierzy" << endl;
    cout << "16. Wyswietl macierz" << endl;
    cout << "17. Wyswietl rozmiar macierzy" << endl;
    cout << "18. Wyjdz" << endl;
    cout<<endl;
}

int wartosc(int n) 
{
    char znak;
    cin >> n;
    if (n>0) 
    {
        cin.get(znak);
        while (znak != '\n') 
        {
                if (znak!= ' ') 
                {
                    n=0;
                }
                cin.get(znak);
        }
    }
    else {
        cin.clear(); // czyszcznie flagi bledu
        cin.ignore(1000,'\n'); // czyszczenie bufora
    }
    return n;
}

double wartoscd(double n)
{
    char znak;
    cin >> n;
    cin.get(znak);
        while (znak != '\n') 
        {
            if (znak!= ' ') 
            {
                n=0;
            }
            cin.get(znak);
        }
        
        /*else 
        {
            cin.clear(); // czyszcznie flagi bledu
            cin.ignore(1000,'\n'); // czyszczenie bufora
        }*/
    return n;
}
