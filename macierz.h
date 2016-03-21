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

    double determ(int);
    bool czykwadratowa();
    
public:

    // Zmienne
    vector<double> kolumna;
    vector< vector<double> > tablica;
    
    //Konstruktory
    Macierz(int nwierszy=1, int mkolumn=1, double liczba=0);//Konstruktor macierzy, domyslnie 1x1 wypelniona 0
    //Macierz(int nwierszy=1, int mkolumn=1, double liczba=0, char opcja='a');//Konstruktor macierzy diagonalnej
    Macierz(const Macierz& m )  { operator = (m);}
    //Dekstruktor
    ~Macierz();
    
    //Funkcje
    int lwierszy() const {return tablica.size();}
    int lkolumn() const {return tablica[0].size();}
    
    void wyswietl();
    void wyswietl(int i, int j);
    void wyswietl(int i);
    
    void wprowadz();
    void wprowadz(int i);
    void wprowadz(int i, int j);
    
    static Macierz diag(int i);
    
    double determ();    
        
    void dodajwiersz();
    void dodajwiersz(vector <double>);
    void dodajwiersz(vector <double>, int);
    
    void usunwiersz();
    void usunwiersz(int);
    
    void dodajkolumne();
    void dodajkolumne(vector <double>);
    void dodajkolumne(int i);
    void dodajkolumne(vector <double>, int);
    
    void usunkolumne();
    void usunkolumne(int);
    
    void usunmacierz();
    
    void t();


    void invert();
    double at( int i, int j ) const;
    
    
    //przeciazenia

    Macierz& operator += ( const Macierz& m ) { return *this = *this + m; }
    Macierz& operator -= ( const Macierz& m ) { return *this = *this - m; }
    Macierz& operator *= ( const Macierz& m ) { return *this = *this * m; }
    Macierz& operator *= ( double f )         { return *this = *this * f; }
    Macierz& operator /= ( const Macierz& m ) { return *this = *this / m; }
    friend Macierz operator +  ( const Macierz& a, const Macierz& m );
    friend Macierz operator -  ( const Macierz& m );
    friend Macierz operator +  ( const Macierz& a, const Macierz& m );
    friend Macierz operator -  ( const Macierz& a, const Macierz& m );
    friend Macierz operator *  ( const Macierz& a, const Macierz& m );
    friend Macierz operator *  ( double f, const Macierz& m );
    friend Macierz operator *  ( const Macierz& m, double f );
    friend Macierz operator /  ( const Macierz& a, const Macierz& m );
};

#endif // MACIERZ_H
