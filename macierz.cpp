#include "macierz.h"
#include <vector>
#include <math.h>
#include <string>
#include <iostream>

#define _DEBUG 0

typedef vector <double> wiersz;
typedef vector < wiersz > matrix;

using namespace std;

/*Macierz::Macierz(int nwierszy, int mkolumn, double liczba, char opcja)//konstruktor macierzy diagonalnej
{
    if ((nwierszy<=0 || mkolumn<=0) || (nwierszy != mkolumn))
    {
    throw invalid_argument( "Liczba wierszy i kolumn musi byc wieksza od 0" );
    }
    if (opcja == 'd')
    {
        vector<double> kolumna (mkolumn, 0);
        tablica = vector< vector<double> > (nwierszy, kolumna);
        for (int j=0;j<nwierszy;j++)
        {
            this->tablica[j][j]=1;
        }
    }
    else
    {
        if (nwierszy<=0 || mkolumn<=0)
        {
            throw invalid_argument( "Liczba wierszy i kolumn musi byc wieksza od 0" );
        }
    vector<double> kolumna (mkolumn, liczba);
    tablica = vector< vector<double> > (nwierszy, kolumna);  
    }
}
*/
Macierz::Macierz(int nwierszy, int mkolumn, double liczba)//konstruktor macierzy
{
    if (nwierszy<=0 || mkolumn<=0)
    {
    throw invalid_argument( "Liczba wierszy i kolumn musi byc wieksza od 0" );
    }
    vector<double> kolumna (mkolumn, liczba);
    tablica = vector< vector<double> > (nwierszy, kolumna); 
}
/*
Macierz::Macierz()
{    
    vector<double> kolumna(1, 0);
    vector< vector<double> > tablica(1, kolumna);
}*/

void Macierz::wprowadz()//wprowadza cala macierz 
{
    for(unsigned int k=0;k<tablica.size();k++)
    {
        cout<<endl;
        for (unsigned int l=0;l<lkolumn();l++)
    {
        cout<<"Wprowadz element: ["<<k<<"]["<<l<<"] macierzy: "<<endl;
        cin>>tablica[k][l];
    }
    }
}

void Macierz::wprowadz(int i, int j)//wprowadz element o wsp i,j
{
    if (i<0 || j<0)
    {
        throw invalid_argument( "Wpolrzedne elementu musza byc liczbami naturalnymi" );
    }
    cout<<"Wprowadz element: ["<<i<<"]["<<j<<"] macierzy"<<endl;
    cin>>tablica[i][j];
    wyswietl();
}

void Macierz::wprowadz(int i)//wprowadz wiersz
{
    if (i<0)
    {
        throw invalid_argument( "Wpolrzedna wiersza musi byc wyrazona liczba naturalna" );
    }
    cout<<"Wprowadz rzad ["<<i<<"] macierzy"<<endl;
    for(unsigned int j=0;j<lkolumn();j++)
    {
        cin>>tablica[i][j];
    }
    wyswietl();
}

Macierz::~Macierz()//destruktor
{/*cout<<"Usuwamy: "<<this<<endl;*/}

void Macierz::wyswietl()//wyswietla macierz
{
    for(unsigned int i=0;i<tablica.size();i++)
        {for(unsigned int j=0;j<lkolumn();j++)
        {
            cout<<tablica[i][j]<<" ";
        }
        cout<<endl;
        }
}

void Macierz::wyswietl(int i, int j)//wyswietla element
{
    if (i<0 || j<0)
    {
        throw invalid_argument( "Wpolrzedne elementu musza byc liczbami naturalnymi" );
    }
    cout<<tablica[i][j]<<endl;
}

void Macierz::wyswietl(int i)//wyswietla wiersz
{
    if (i<0)
    {
        throw invalid_argument( "Wpolrzedna wiersza musi byc wyrazona liczba naturalna" );
    }
    for(unsigned int j=0;j<lkolumn();j++)
    {
        cout<<tablica[i][j]<<" ";
    }
    cout<<endl;
}

void Macierz::dodajwiersz()//dodaje wiersz
{
    cout<<"Podaj el. nowego wiersza"<<endl;
    wiersz tmp(lkolumn());
    for (unsigned int i = 0; i<lkolumn();i++)
    {
        cin>>tmp[i];
    }
    Macierz::dodajwiersz(tmp);
}

void Macierz::dodajwiersz(vector<double> nowy)//pozwala dodac juz istniejacy wiersz macierzy jako nowy
{
    tablica.push_back(nowy);
}

void Macierz::dodajwiersz(vector<double> nowy, int i)//kiedys pozwoli dodac wiersz w dowolnym miejscu
{
    if (i<0)
    {
        throw invalid_argument( "Wpolrzedna wiersza musi byc wyrazona liczba naturalna" );
    }
}

void Macierz::usunwiersz()//usuwa ostatni wiersz
{
    tablica.erase(tablica.end());
}

void Macierz::usunwiersz(int i)//usuwa i-ty wiersz
{
    if (i<0)
    {
        throw invalid_argument( "Wpolrzedna wiersza musi byc wyrazona liczba naturalna" );
    }
    tablica.erase(tablica.begin()+i);
}

void Macierz::dodajkolumne()//dodaje kolumne
{
    Macierz tmp(tablica.size(),lkolumn());//tymczasowa do przepisania
    
    for(unsigned int i=0;i<tablica.size();i++)
        {for(unsigned int j=0;j<lkolumn();j++)
        {
            tmp.tablica[i][j]=tablica[i][j];//przepisanie
        }
        }
    
    kolumna = wiersz (lkolumn()+1);//nowe wymiary
    tablica = matrix (tablica.size(),kolumna);
    for(unsigned int i=0;i<tablica.size();i++)//przepisywanie
        {for(unsigned int j=0;j<(lkolumn()-1);j++)
        {
            tablica[i][j]=tmp.tablica[i][j];
        }
        }
        for(unsigned int i=0;i<tablica.size();i++)
        {   
            wprowadz(i,lkolumn()-1);
        }
}

void Macierz::dodajkolumne(int i)//dodaje kolumne
{
    if (i<0)
    {
        throw invalid_argument( "Wpolrzedna kolumny musi byc wyrazona liczba naturalna" );
    }
    Macierz tmp(tablica.size(),lkolumn());//tymczasowa do przepisania
    for( int i=0;i<tablica.size();i++)
        {for( int j=0;j<lkolumn();j++)
        {
            tmp.tablica[i][j]=tablica[i][j];//przepisanie
        }
        }
    
    kolumna = wiersz (lkolumn()+1);//nowe wymiary
    tablica = matrix (tablica.size(),kolumna);
    for( int i=0;i<tablica.size();i++)//przepisywanie
        {for( int j=0;j<(lkolumn()-1);j++)
        {
            tablica[i][j]=tmp.tablica[i][j];
        }
        }
        for( int i=0;i<tablica.size();i++)
        {   
            wprowadz(i,lkolumn()-1);
        }
}

void Macierz::dodajkolumne(wiersz nowy)// nie dziala, ale to nie ma prawa dzialac
{
        Macierz tmp(tablica.size(),lkolumn());
    for(unsigned int i=0;i<tablica.size();i++)
        {for(unsigned int j=0;j<lkolumn();j++)
        {
            tmp.tablica[i][j]=tablica[i][j];
        }
        }
    
    kolumna = wiersz (lkolumn()+1);
    tablica = matrix (tablica.size(),kolumna);
    for(unsigned int i=0;i<tablica.size();i++)
        {for(unsigned int j=0;j<(lkolumn()-1);j++)
        {
            tablica[i][j]=tmp.tablica[i][j];
        }
        }
        for(unsigned int i=0;i<tablica.size();i++)
        { cout<<nowy[i]<<" ";  
            tablica[i][lkolumn()-1]=nowy[i];
        }
}

void Macierz::usunmacierz()//usuwa macierz
{
    tablica.clear();
}

bool Macierz::czykwadratowa()//sprawdza czy macierz jest kwadratowa
{
    if(tablica.size()==lkolumn())
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Macierz::determ() //nie oblicza poprawnie
{//sprobowac na tablicach
    if (!Macierz::czykwadratowa())
        return 0.0;
        
        
    int det=0, p, h, k, i, j;
    int n = tablica.size();
    Macierz tmp(n-1,n-1,0);
    if(n==1) 
    {
        return tablica[0][0];
    } 
    else if (n == 2) 
    {
        return( (tablica[0][0] * tablica[1][1]) - (tablica[1][0] * tablica[0][1]));
    }
    else if (n==3)
    {
        return( (tablica[0][0]*tablica[1][1]*tablica[2][2])+(tablica[0][1]*tablica[1][2]*tablica[2][0])+(tablica[0][2]*tablica[1][0]*tablica[2][1])
        -(tablica[2][0]*tablica[1][1]*tablica[0][2])-(tablica[2][1]*tablica[1][2]*tablica[0][0])-(tablica[2][2]*tablica[1][0]*tablica[0][1]));
    }
    else
    {  
        for(p=0;p<n;p++) 
        {
            h = 0;
            k = 0;
            for(i=1;i<n;i++)
            {
                for( j=0;j<n;j++) 
                {
                    if(j==p)
                    {
                        continue;
                    }
                    tmp.tablica[h][k] = tablica[i][j];
                    k++;
                    if(k==n-1)
                    {
                        h++;
                        k = 0;
                    }
                }
            }
            n--;
            
            det=det+tablica[0][p]*pow(-1,p)*tmp.determ(n);
        }
    }
    return det;        
}

double Macierz::determ(int n) //nie dziala poprawnie wina algorytmu
{
    int det=0, p, h, k, i, j;
    Macierz tmp(n-1,n-1,0);
    if(n==1) 
    {
        return tablica[0][0];
    } 
    else if (n == 2) 
    {
        return( (tablica[0][0] * tablica[1][1]) - (tablica[1][0] * tablica[0][1]));
    }
    else if (n==3)
    {
        return( (tablica[0][0]*tablica[1][1]*tablica[2][2])+(tablica[0][1]*tablica[1][2]*tablica[2][0])+(tablica[0][2]*tablica[1][0]*tablica[2][1])
        -(tablica[2][0]*tablica[1][1]*tablica[0][2])-(tablica[2][1]*tablica[1][2]*tablica[0][0])-(tablica[2][2]*tablica[1][0]*tablica[0][1]));
    }
    else
    {  
        for(p=0;p<n;p++) 
        {
            h = 0;
            k = 0;
            for(i=1;i<n;i++)
            {
                for( j=0;j<n;j++) 
                {
                    if(j==p)
                    {
                        continue;
                    }
                    tmp.tablica[h][k] = tablica[i][j];
                    k++;
                    if(k==n-1)
                    {
                        h++;
                        k = 0;
                    }
                }
            }
            n--;            
            det=det+tablica[0][p]*pow(-1,p)*determ(n);
        }
    }
    return det;
}

void Macierz::t()//transpozycja
{
    int nwierszy,nkolumn; 
    nwierszy=lkolumn();
    nkolumn=lwierszy();
    Macierz tmp(nwierszy,nkolumn);//macierz do przepisania
    for(int i=0;i<tmp.lwierszy();i++)
    {
        for(int j=0;j<tmp.lkolumn();j++)
        {
            tmp.tablica[i][j]=tablica[j][i];//przepisywanie
        }
    }
    this->tablica=tmp.tablica;
}

Macierz Macierz::diag(int i)
{
   if (i<=0)
    {
        throw invalid_argument( "Wielkosc macierzy diagonalnej musi byc wyrazona liczba naturalna wieksza od 0" );
    }
    Macierz tmp = Macierz(i,i,0);
    for (int j=0;j<i;j++)
    {
        tmp.tablica[j][j]=1;
    }
    return tmp;
}

void Macierz::invert()//odwrocenie macierzy metoda Gaussa Jordana nie dziala
{
    if (!czykwadratowa())
    {
        throw invalid_argument( "Odwracona moze byc tylko macierz kwadratowa" );
    }
    int j, i, k;
    int n=lwierszy();
    int m=2*n;
    Macierz diagonalna=Macierz::diag(n);
    Macierz tmp(n, m, 0);
    for (i=0;i<n;i++)//przepisanie macierzy do odwrocenia
    {                
        for (j=0;j<n;j++)
        {
            tmp.tablica[i][j]=this->tablica[i][j];
        }
    }
    for (i=0;i<n;i++)//przepisanie macierzy diagonalnej
    {                
        for (j=n;j<m;j++)
        {
            tmp.tablica[i][j]=diagonalna.tablica[i][(j-n)];
        }
    }
    for (j=0;j<n;j++)
    {                   //normalizacja
        for (i=0;i<m;i++)
        {
            if (i != j)
            {
                tmp.tablica[j][i] = tmp.tablica[j][i] / tmp.tablica[j][j];
            }
            else
            {
                tmp.tablica[j][j]=1;
            }
        }               //redukcja
        for (k = 0;k<n;k++)
        {
            if (k != j)
            {
                for (i = 0;i<m; i++)
                {
                    if (i != j)
                    {
                        tmp.tablica[k][i] = tmp.tablica[k][i] - (tmp.tablica[k][j] * tmp.tablica[j][i]);
                    }
                }
                tmp.tablica[k][j] = 0;
            }
        }
    }
    for (i = 0;i<n;i++)//przepisanie na wlasciwa macierz
    {                
        for (j = 0;j<n;j++)
        {
            this->tablica[i][j]=tmp.tablica[i][(j+n)];
        }
    }
}

Macierz operator+(const Macierz &a, const Macierz &m)//operacja dodawania, nie dziala
{
    #if _DEBUG == 1
    std::cout << "przeladowanie +" << std::endl;
    #endif // _DEBUG
    if ((a.lwierszy()==m.lwierszy())&&a.lkolumn()==m.lkolumn())
    {
    Macierz tmp(a.lwierszy(),a.lkolumn());
    for(int i=0;i<a.lwierszy();i++)
    {   for(int j=0;j<(a.lkolumn());j++)
        {
            tmp.tablica[i][j]=a.tablica[i][j]+m.tablica[i][j];
        }
    }
    return tmp;
    }
    else
    {
    throw invalid_argument( "Niekompatybilne rozmiary macierzy! (operator +)" );
    }
}

Macierz operator-(const Macierz& a, const Macierz& m)//operacja odejmowania wszystkie operatory nie dzialaja, czasem dzialaja
{
    #if _DEBUG == 1
    std::cout << "przeladowanie -" << std::endl;
    #endif // _DEBUG
    if ((a.lwierszy()==m.lwierszy())&&a.lkolumn()==m.lkolumn())
    {
        Macierz tmp(a.lwierszy(),a.lkolumn());
        for(int i=0;i<a.lwierszy();i++)
        {   
            for(int j=0;j<(a.lkolumn());j++)
            {
            tmp.tablica[i][j]=a.tablica[i][j]-m.tablica[i][j];
            }
        }
        return tmp;
    }
    else
    {
    throw invalid_argument( "Niekompatybilne rozmiary macierzy! (operator -)" );
    }
}

Macierz operator-( const Macierz& a ) //zmiana znaku elementow macierzy
{
    Macierz tmp(a.lwierszy(),a.lkolumn());
    for(int i=0;i<a.lwierszy();i++)
    {   
        for(int j=0;j<(a.lkolumn());j++)
        {
            tmp.tablica[i][j]=-a.tablica[i][j];
        }
    }
    return tmp;
}

Macierz operator*(const Macierz& a, const Macierz& m)//operacja mnozenia macierzy ze soba
{
    if (a.lkolumn()==m.lwierszy())
    {
        Macierz tmp(a.lwierszy(),m.lkolumn());
        for( int i=0; i<tmp.lwierszy(); i++ )
        {
            for( int j=0; j<tmp.lkolumn(); j++ ) 
                {
                    for( int k=0; k<a.lkolumn(); k++ )
                    {
                        tmp.tablica[i][j] += a.tablica[i][k] * m.tablica[k][j];
                    }
                }
        }
        return tmp;
    }        
    else
    {
        throw invalid_argument( "Niekompatybilne rozmiary macierzy! (operator *)" );
    }
    
}

Macierz operator*(double f, const Macierz& m)//operacja mnozenia macierzy przez stala
{
    Macierz tmp( m.lwierszy(), m.lkolumn() );
    for( int i=0; i<tmp.lwierszy(); i++ ) 
    {
        for( int j=0; j<tmp.lkolumn(); j++ ) 
        {
            tmp.tablica[i][j] = f * m.tablica[i][j];
        }
    }
    return tmp;
}

Macierz operator*(const Macierz& m, double f)//operacja mnozenia macierzy przez stala
{
    return f*m;
}

Macierz operator/(const Macierz& a, Macierz& m)//mnozenie macierzy z odwrotnoscia 2 macierzy nie dziala, ale invert tez nie dziala
{
   Macierz tmp;
   tmp=m;
   tmp.invert();
   return(a*tmp); 
}


/********************************************************************
Kosz:

/*Poprzednia wersja transpozycji
    for(unsigned int i=0;i<(nwierszy);i++)
    {
        for(unsigned int j=0;j<(nkolumn);j++)
        {
            tablica[i][j]=tmp.tablica[i][j];
        }
    }
    

Macierz& Macierz::operator=(const Macierz& m)//operacja przypisania nie dziala, czasem dziala
{
    if( this != &m )
    {
        Macierz ( m.lwierszy(), m.lkolumn() );
    }
    for(int k=0;k<lwierszy();k++)
    {
        for(int j=0;j<lkolumn();j++)
        {
            tablica[k][j]=m.tablica[k][j];
        }
    }
    return *this;
}
*/