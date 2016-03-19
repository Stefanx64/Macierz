#include "macierz.h"
#include <vector>
#include <math.h>
#include <string>
#include <iostream>

#define _DEBUG 0

typedef vector <double> wiersz;
typedef vector < wiersz > matrix;

using namespace std;

Macierz::Macierz(int nwierszy, int mkolumn)
{
    kolumna = vector<double> (mkolumn, 0);
    tablica = vector< vector<double> > (nwierszy, kolumna);
}

Macierz::Macierz(int nwierszy, int mkolumn, double liczba)
{
    kolumna = vector<double> (mkolumn, liczba);
    tablica = vector< vector<double> > (nwierszy, kolumna);
    /*for(unsigned int k=0;k<tablica.size();k++)
    {
        cout<<endl;
        for (unsigned int l=0;l<kolumna.size();l++)
    {
        cout<<tablica[k][l]<<" ";
    }
    }
    cout<<endl;*/    
}

Macierz::Macierz()
{    
    vector<double> kolumna(1, 0);
    vector< vector<double> > tablica(1, kolumna);
}
void Macierz::wprowadz()//wprowadza cala macierz
{
    for(unsigned int k=0;k<tablica.size();k++)
    {
        cout<<endl;
        for (unsigned int l=0;l<kolumna.size();l++)
    {
        cout<<"Wprowadz element: ["<<k<<"]["<<l<<"] macierzy: "<<endl;
        cin>>tablica[k][l];
    }
    }
}

void Macierz::wprowadz(int i, int j)//wprowadz element o wsp i,j
{
    cout<<"Wprowadz element: ["<<i<<"]["<<j<<"] macierzy"<<endl;
    cin>>tablica[i][j];
    wyswietl();
}

void Macierz::wprowadz(int i)//wprowadz wiersz
{
    cout<<"Wprowadz rzad ["<<i<<"] macierzy"<<endl;
    for(unsigned int j=0;j<kolumna.size();j++)
    {
        cin>>tablica[i][j];
    }
    wyswietl();
}

Macierz::~Macierz()
{cout<<"Usuwamy: "<<this<<endl;}

void Macierz::wyswietl()//wyswietla macierz
{
    for(unsigned int i=0;i<tablica.size();i++)
        {for(unsigned int j=0;j<kolumna.size();j++)
        {
            cout<<tablica[i][j]<<" ";
        }
        cout<<endl;
        }
}

void Macierz::wyswietl(int i, int j)//wyswietla element
{
    cout<<tablica[i][j]<<endl;
}

void Macierz::wyswietl(int i)//wyswietla wiersz
{
    for(unsigned int j=0;j<kolumna.size();j++)
    {
        cout<<tablica[i][j]<<" ";
    }
    cout<<endl;
}

void Macierz::dodajwiersz()//dodaje wiersz
{
    cout<<"Podaj el. nowego wiersza"<<endl;
    vector<double> tmp(kolumna.size());
    for (unsigned int i = 0; i<kolumna.size();i++)
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
    
}

void Macierz::usunwiersz()//usuwa wiersz
{
    tablica.erase(tablica.end());
}

void Macierz::usunwiersz(int i)//usuwa ity wiersz
{
    tablica.erase(tablica.begin()+i);
}

void Macierz::dodajkolumne()//dodaje kolumne
{
    Macierz tmp(tablica.size(),kolumna.size());//tymczasowa do przepisania
    
    for(unsigned int i=0;i<tablica.size();i++)
        {for(unsigned int j=0;j<kolumna.size();j++)
        {
            tmp.tablica[i][j]=tablica[i][j];//przepisanie
        }
        }
    
    kolumna = wiersz (kolumna.size()+1);//nowe wymiary
    tablica = matrix (tablica.size(),kolumna);
    for(unsigned int i=0;i<tablica.size();i++)//przepisywanie
        {for(unsigned int j=0;j<(kolumna.size()-1);j++)
        {
            tablica[i][j]=tmp.tablica[i][j];
        }
        }
        for(unsigned int i=0;i<tablica.size();i++)
        {   
            wprowadz(i,kolumna.size()-1);
        }
}

void Macierz::dodajkolumne(int i)//dodaje kolumne
{
    Macierz tmp(tablica.size(),kolumna.size());//tymczasowa do przepisania
    
    for(unsigned int i=0;i<tablica.size();i++)
        {for(unsigned int j=0;j<kolumna.size();j++)
        {
            tmp.tablica[i][j]=tablica[i][j];//przepisanie
        }
        }
    
    kolumna = wiersz (kolumna.size()+1);//nowe wymiary
    tablica = matrix (tablica.size(),kolumna);
    for(unsigned int i=0;i<tablica.size();i++)//przepisywanie
        {for(unsigned int j=0;j<(kolumna.size()-1);j++)
        {
            tablica[i][j]=tmp.tablica[i][j];
        }
        }
        for(unsigned int i=0;i<tablica.size();i++)
        {   
            wprowadz(i,kolumna.size()-1);
        }
}

void Macierz::dodajkolumne(wiersz nowy)
{
        Macierz tmp(tablica.size(),kolumna.size());
    for(unsigned int i=0;i<tablica.size();i++)
        {for(unsigned int j=0;j<kolumna.size();j++)
        {
            tmp.tablica[i][j]=tablica[i][j];
        }
        }
    
    kolumna = wiersz (kolumna.size()+1);
    tablica = matrix (tablica.size(),kolumna);
    for(unsigned int i=0;i<tablica.size();i++)
        {for(unsigned int j=0;j<(kolumna.size()-1);j++)
        {
            tablica[i][j]=tmp.tablica[i][j];
        }
        }
        for(unsigned int i=0;i<tablica.size();i++)
        { cout<<nowy[i]<<" ";  
            tablica[i][kolumna.size()-1]=nowy[i];
        }
}

void Macierz::usunmacierz()
{
    tablica.clear();
}

bool Macierz::czykwadratowa()
{
    if(tablica.size()==kolumna.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

double Macierz::determ() //nie oblicza poprawnie, wina algorytmu
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
    int lwierszy,lkolumn;
    lwierszy=tablica.size();
    lkolumn=kolumna.size();
    Macierz tmp(kolumna.size(),tablica.size());
for(unsigned int i=0;i<tmp.tablica.size();i++)
    {
        for(unsigned int j=0;j<tmp.kolumna.size();j++)
        {
            tmp.tablica[i][j]=tablica[j][i];
        }
    }tmp.wyswietl();
    kolumna.resize(lwierszy,0);
    tablica.resize(lkolumn);
    cout<<"wymiary macierzy: "<<tablica.size()<<" "<<kolumna.size()<<endl<<endl;
    
    for(unsigned int i=0;i<(tablica.size());i++)
    {
        for(unsigned int j=0;j<(kolumna.size());j++)
        {
            tablica[i][j]=tmp.tablica[i][j];
        }
    }
}



/*
Macierz operator = (const Macierz &m)
{
    for(unsigned int k=0;k<tablica.size();k++)
    {
        for(unsigned int j=0;j<kolumna.size();j++)
        {
            this[k][j]->=m[k][j];
        }
    }
    return *this;
}
*/
/*
Macierz operator+(const Macierz &a, const Macierz &b)
{
    #if _DEBUG == 1
    std::cout << "przeladowanie +" << std::endl;
    #endif // _DEBUG
    Macierz tmp(a.tablica.size(),a.kolumna.size());
    for(unsigned int i=0;i<a.tablica.size();i++)
    {   for(unsigned int j=0;j<(a.kolumna.size());j++)
        {
            tmp[i][j]=a[i][j]+b[i][j]);
        }
    }
    return tmp;
}
*/
/*Macierz & operator+=(const Macierz &q)
{
    #if _DEBUG == 1
    std::cout << "przeladowanie +=" << std::endl;
    #endif // _DEBUG
    for(int i=0;i<tablica.size();i++)
    {   for(int j=0;j<kolumna.size();j++)
        {
            this->tablica[i][j]+=q.tablica[i][j];
        }
    }
    return * this;
}*/
/*
Macierz operator-(const Macierz &q)
{
    #if _DEBUG == 1
    std::cout << "przeladowanie -" << std::endl;
    #endif // _DEBUG

    Macierz tmp(this->dane[0] - q.dane[0], this->dane[1] - q.dane[1], this->dane[2] - q.dane[2], this->dane[3] - q.dane[3]);
    return tmp;
}
Macierz & operator-=(const Macierz &q)
{
    #if _DEBUG == 1
    std::cout << "przeladowanie -=" << std::endl;
    #endif // _DEBUG

            this->dane[0] -= q.dane[0];
            this->dane[1] -= q.dane[1];
            this->dane[2] -= q.dane[2];
            this->dane[3] -= q.dane[3];
            return * this;
        }
        Macierz operator*(const Macierz &q)
        {
            #if _DEBUG == 1
            std::cout << "przeladowanie *" << std::endl;
            #endif // _DEBUG

            double a = this->dane[0]*q.dane[0] - this->dane[1]*q.dane[1] - this->dane[2]*q.dane[2] - this->dane[3]*q.dane[3];
            double b = this->dane[0]*q.dane[1] + this->dane[1]*q.dane[0] + this->dane[2]*q.dane[3] - this->dane[3]*q.dane[2];
            double c = this->dane[0]*q.dane[2] - this->dane[1]*q.dane[3] + this->dane[2]*q.dane[0] + this->dane[3]*q.dane[1];
            double d = this->dane[0]*q.dane[3] + this->dane[1]*q.dane[2] - this->dane[2]*q.dane[1] + this->dane[3]*q.dane[0];
            Macierz tmp(a,b,c,d);
            return tmp;
        }
        Macierz & operator*=(const Macierz &q)
        {
            #if _DEBUG == 1
            std::cout << "przeladowanie *=" << std::endl;
            #endif // _DEBUG

            double a = this->dane[0]*q.dane[0] - this->dane[1]*q.dane[1] - this->dane[2]*q.dane[2] - this->dane[3]*q.dane[3];
            double b = this->dane[0]*q.dane[1] + this->dane[1]*q.dane[0] + this->dane[2]*q.dane[3] - this->dane[3]*q.dane[2];
            double c = this->dane[0]*q.dane[2] - this->dane[1]*q.dane[3] + this->dane[2]*q.dane[0] + this->dane[3]*q.dane[1];
            double d = this->dane[0]*q.dane[3] + this->dane[1]*q.dane[2] - this->dane[2]*q.dane[1] + this->dane[3]*q.dane[0];
            this->dane[0] = a;
            this->dane[1] = b;
            this->dane[2] = c;
            this->dane[3] = d;
            return * this;
        }
        Macierz operator*(const int q)
        {
            #if _DEBUG == 1
            std::cout << "przeladowanie * - dla liczb calkowitych" << std::endl;
            #endif // _DEBUG

            Macierz tmp(this->dane[0]*q,this->dane[1]*q,this->dane[2]*q,this->dane[3]*q);
            return tmp;
        }
        Macierz & operator*=(const int q)
        {
            #if _DEBUG == 1
            std::cout << "przeladowanie *= - dla liczb calkowitych" << std::endl;
            #endif // _DEBUG

            this->dane[0] *= q;
            this->dane[1] *= q;
            this->dane[2] *= q;
            this->dane[3] *= q;
            return * this;
        }
        Macierz operator*(const double q)
        {
            #if _DEBUG == 1
            std::cout << "przeladowanie * - dla liczb rzeczywistych" << std::endl;
            #endif // _DEBUG

            Macierz tmp(this->dane[0]*q,this->dane[1]*q,this->dane[2]*q,this->dane[3]*q);
            return tmp;
        }
        Macierz & operator*=(const double q)
        {
            #if _DEBUG == 1
            std::cout << "przeladowanie * - dla liczb rzeczywistych" << std::endl;
            #endif // _DEBUG

            this->dane[0] *= q;
            this->dane[1] *= q;
            this->dane[2] *= q;
            this->dane[3] *= q;
            return * this;
        }

*/

/* KOSZ --------------------------------------------------------------
 * 
    for(int k=0;k<tablica.size();k++)
    {
        cout<<endl;
        for (int l=0;l<kolumna.size();l++)
    {
        cout<<"Wprowadz element"<<k<<" i "<<l<<"macierzy:  ";
        cin>>tablica[k][l];
        cout<<"wprowadzono:  "<<tablica[k][l]<<endl;
    }
    }


double Macierz::at( int i, int j) const
{
    
	if( i<0 || i >= rtab ) throw std::out_of_range( "indeks spoza zakresu lub macierz nie utworzona!" );
	if( j<0 || j >= rozm ) throw std::out_of_range( "indeks spoza zakresu!" );

	return wartosc[i][j];
}
    */
    