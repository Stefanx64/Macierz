#ifndef MACIERZ_H

#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#define MACIERZ_H
#define _DEBUG 0

using namespace std;

class Macierz
{
private:

    bool czykwadratowa() const;
    int konw(int n);//obsluguje poprawne wpisanie liczb
    double konw(double n);//obsluguje poprawne wpisanie liczb typu double
    
    vector<double> kolumna;//jak cos to dac na public
    vector< vector<double> > tablica;
    
public:

    //Konstruktory
    Macierz(int=1, int=1, double=0);//Konstruktor macierzy, domyslnie 1x1 wypelniona 0

    //Dekstruktor
    ~Macierz();
    
    //Funkcje
    
    int lwierszy() const {return tablica.size();} //wyswietla ilosc wierszy macierz
    int lkolumn() const {return tablica[0].size();} //wyswietla ilosc kolumn macierzy
    
    void wyswietl() const; //wyswietla cala macierz
    void wyswietl(int i, int j) const;//wyswietla element macierzy
    void wyswietl(int i) const;//wsywietla wybrany wiersz macierzy
    void wyswietlrozmiar() const;
    
    void wprowadz();//opcja wprowadzenia calej macierz
    void wprowadz(int i);//opcja wprowadzenia wybranego wiersza
    void wprowadz(int i, int j);//opcja wprowadzenia wybranego elementu
    
    static Macierz diag(int i);//stworzenie macierzy diagonalnej
    
    double wyznacznik();//obliczenie wyznacznika
    
    void dodajwiersz();//dodanie wiersza na koniec macierzy
    void dodajwiersz(int i);//dodanie wiersza w wybranym miejscu macierzy
    void dodajwiersz(vector <double>);//dodanie wektora na koniec (juz zdefiniowanego)
    void dodajwiersz(vector <double>, int);//dodanie wektora w wybrane miejsce (juz zdefiniowanego
    
    void usunwiersz();//usuwa wiersz
    void usunwiersz(int);//usuwa wybrany wiersz
    
    void dodajkolumne();//dodaje kolumne na koniec macierzy
    
    void usunkolumne();//usuwa kolumne
    void usunkolumne(int);//usuwa wybrana kolumne
    
    void usunmacierz();//usuwa cala macierz
    
    void t();//transpozycja macierzy

    void invert();//odwrocenie macierzy
    
    
    //przeciazenia

    Macierz& operator += ( const Macierz& m ) { return *this = *this + m; }
    Macierz& operator -= ( const Macierz& m ) { return *this = *this - m; }
    Macierz& operator *= ( const Macierz& m ) { return *this = *this * m; }
    Macierz& operator *= ( double f )         { return *this = *this * f; }
    Macierz& operator /= ( const Macierz& m ) { return *this = *this / m; }
    friend Macierz operator +  ( const Macierz& a, const Macierz& m );
    friend Macierz operator -  ( const Macierz& m );
    friend Macierz operator -  ( const Macierz& a, const Macierz& m );
    friend Macierz operator *  ( const Macierz& a, const Macierz& m );
    friend Macierz operator *  ( double f, const Macierz& m );
    friend Macierz operator *  ( const Macierz& m, double f );
    friend Macierz operator /  ( const Macierz& a, const Macierz& m );
    
    friend std::ostream & operator << ( std::ostream & wyjscie, Macierz const& _m );
    friend std::istream & operator >> ( std::istream & mat, Macierz& m );
};

template <class T>
T wczytajLiczbe()
{
    T t;
    cin.clear();

    while( cin ) 
    {
        cin >> t;
        if( cin.bad() || cin.fail() ) 
        {
            cin.clear();
            string s;
            cin >> s;
            
            cerr << "Wprowadz liczbe " << endl;
            continue;
        }
        return t;
    }
}


#endif // MACIERZ_H
