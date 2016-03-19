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
    Macierz(int nwierszy, int mkolumn);//jkonstruktor macierzy o n wierszach i m kolumnach (wypelnia wybrana macierz 0)
    Macierz(int nwierszy, int mkolumn, double liczba);//j.w. wypelnia wybrana liczba
    Macierz(Macierz &) {cout<<"skopiowano albo i nie\n w sumie to ... nie"<<endl;}
    Macierz();
    //Dekstruktor
    ~Macierz();
    
    //Funkcje
    int lwierszy() {return tablica[0].size();}
    int lkolumn() {return tablica.size();}
    
    void wyswietl();
    void wyswietl(int i, int j);
    void wyswietl(int i);
    
    void wprowadz();
    void wprowadz(int i);
    void wprowadz(int i, int j);
    
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


    Macierz odwrotnosc();
    double at( int i, int j ) const;
    
    
    //przeciazenia
    Macierz operator = (const Macierz &m);
    friend Macierz operator +  ( const Macierz& a, const Macierz& b );
    //Macierz& operator += ( const Macierz& m ) { return *this = *this + m; }

};

#endif // MACIERZ_H
