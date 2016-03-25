#include "macierz.h"
#include <vector>
#include <math.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include <cstddef>

#define _DEBUG 0

typedef vector <double> wiersz;
typedef vector < wiersz > matrix;

using namespace std;

Macierz::Macierz(int nwierszy, int mkolumn, double liczba)//konstruktor macierzy
{
    if (nwierszy<0 || mkolumn<0)
    {
        throw invalid_argument("Liczba wierszy i kolumn musi byc wieksza od 0");
    }
    vector<double> kolumna (mkolumn, liczba);
    tablica = vector< vector<double> > (nwierszy, kolumna); 
}

void Macierz::wprowadz()//wprowadza cala macierz 
{
    for(int k=0;k<lwierszy();k++)
    {
        cout<<endl;
        for (int l=0;l<lkolumn();l++)
        {
            cout<<"Wprowadz element: ["<<k<<"]["<<l<<"] macierzy: "<<endl;
            tablica[k][l]=wczytajLiczbe<double>();
        }
    }
}

void Macierz::wprowadz(int i, int j)//wprowadz element o wsp i,j
{
    if (i<0 || j<0)
    {
        cout<< "Wpolrzedne elementu musza byc liczbami naturalnymi" <<endl;
        return;
    }
    cout<<"Wprowadz element: ["<<i<<"]["<<j<<"] macierzy"<<endl;
    tablica[i][j]=wczytajLiczbe<double>();
}

void Macierz::wprowadz(int i)//wprowadz wiersz
{
    if (i<0)
    {
        cout<< "Wpolrzedna wiersza musi byc wyrazona liczba naturalna" <<endl;
    }
    for(int j=0;j<lkolumn();j++)
    {        
        cout<<"Wprowadz element ["<<i<<"]["<<j<<"] macierzy"<<endl;
        tablica[i][j]=wczytajLiczbe<double>();
    }
}

Macierz::~Macierz()//destruktor
{/*cout<<"Usuwamy: "<<this<<endl;*/}

void Macierz::wyswietl() const//wyswietla macierz
{
    for(unsigned int i=0;i<tablica.size();i++)
        {
            for(int j=0;j<lkolumn();j++)
            {
                cout<<tablica[i][j]<<" ";//wyswietla element
            }
            cout<<endl;
        }
}

void Macierz::wyswietl(int i, int j) const//wyswietla element
{
    if (tablica.size()==0 || tablica[0].size()==0)
    {
        throw invalid_argument( "Rozmiary wiersza lub kolumny sa rowne 0" );
    }
    if (i<0 || j<0)
    {
        throw invalid_argument( "Wpolrzedne elementu musza byc liczbami naturalnymi" );
    }
    cout<<tablica[i][j]<<endl;
}

void Macierz::wyswietl(int i) const//wyswietla wiersz
{
    if (tablica.size()==0 || tablica[0].size()==0)
    {
        throw invalid_argument( "Rozmiary wiersza lub kolumny sa rowne 0" );
    }    
    if (i<0)
    {
        throw invalid_argument( "Wpolrzedna wiersza musi byc wyrazona liczba naturalna" );
    }
    for(int j=0;j<lkolumn();j++)
    {
        cout<<tablica[i][j]<<" ";
    }
    cout<<endl;
}

void Macierz::wyswietlrozmiar() const//wyswietla wymiary macierzy
{
    if (tablica.size()==0 || tablica[0].size()==0)
    {
        throw invalid_argument( "Rozmiary wiersza lub kolumny sa rowne 0" );
    }
    cout<<"Liczba wierszy: "<<tablica.size()<<", a liczba kolumn: "<<tablica[0].size()<<endl;
}

void Macierz::dodajwiersz()//dodaje wiersz
{
    if (tablica.size()==0 || tablica[0].size()==0)
    {
        throw invalid_argument("Nie mozna dodac wiersza do macierzy ktora ma 0 liczbe wierszy badz kolumn");
    }
    wiersz tmp(lkolumn());
    for (int i = 0; i<lkolumn();i++)
    {
        cout<<"Podaj nowy element ["<<i<<"] wiersza"<<endl;
        tmp[i]=wczytajLiczbe<double>();
    }
    Macierz::dodajwiersz(tmp);
}

void Macierz::dodajwiersz(int i)//dodaje wiersz w itym polozeniu
{
    if (tablica.size()==0 || tablica[0].size()==0)
    {
        throw invalid_argument("Nie mozna dodac wiersza do macierzy ktora ma 0 liczbe wierszy badz kolumn");
    }
    if (i<0)
    {
        throw invalid_argument( "Wpolrzedna wiersza musi byc wyrazona liczba naturalna" );
    }
    if (i>tablica.size())
    {
        throw invalid_argument( "Wpolrzedna wiersza musi byc mniejsza od rozmiaru macierzy" );
    }
    cout<<"Podaj el. nowego wiersza"<<endl;
    wiersz tmp(lkolumn());   // tworzy wiersz do ktorego beda wklejone wyniki
    for (int j = 0; j<lkolumn();j++)
    {
        tmp[j]=wczytajLiczbe<double>();
    }
    tablica.insert(tablica.begin()+i, tmp); 
}

void Macierz::dodajwiersz(vector<double> nowy)//pozwala dodac juz istniejacy wiersz macierzy jako nowy
{
    tablica.push_back(nowy);
}

void Macierz::dodajwiersz(vector<double> nowy, int i)//pozwala dodac wiersz w innym miejscu
{
    if (tablica.size()==0 || tablica[0].size()==0)
    {
        throw invalid_argument("Nie mozna dodac wiersza do macierzy ktora ma 0 liczbe wierszy badz kolumn");
    }
    if (i<0)
    {
        throw invalid_argument( "Wpolrzedna wiersza musi byc wyrazona liczba naturalna" );
    }
    if (i>tablica.size())
    {
        throw invalid_argument( "Wpolrzedna wiersza musi byc mniejsza od rozmiaru macierzy" );
    }
    tablica.insert(tablica.begin()+i,nowy);
}

void Macierz::usunwiersz()//usuwa ostatni wiersz
{
    tablica.erase(tablica.end());
}

void Macierz::usunwiersz(int i)//usuwa i-ty wiersz
{
    if (tablica.size()==0 || tablica[0].size()==0)
    {
        throw invalid_argument("Nie mozna usunac wiersza do macierzy ktora ma 0 liczbe wierszy badz kolumn");
    }
    if (i<0)
    {
        throw invalid_argument( "Wpolrzedna wiersza musi byc wyrazona liczba naturalna" );
    }
    tablica.erase(tablica.begin()+i);
}

void Macierz::usunkolumne()//usuwa kolumne
{
    if (tablica.size()==0 || tablica[0].size()==0)
    {
        throw invalid_argument("Nie mozna usunac kolumny macierzy ktora ma 0 liczbe wierszy badz kolumn");
    }
    for(unsigned int i=0;i<tablica.size();i++)
    {
        (tablica[i]).pop_back();
    }
}

void Macierz::dodajkolumne()//dodaje kolumne
{
    if (tablica.size()==0 || tablica[0].size()==0)
    {
        throw invalid_argument("Nie mozna dodac wiersza do macierzy ktora ma 0 liczbe wierszy");
    }
    for(unsigned int i=0;i<tablica.size();i++)
    { 
        cout<<"Podaj nowy element ["<<i<<"] kolumny"<<endl;
        (tablica[i]).push_back(wczytajLiczbe<double>());
    }
}

void Macierz::usunmacierz()//usuwa macierz
{
    tablica.clear();
}

bool Macierz::czykwadratowa() const //sprawdza czy macierz jest kwadratowa
{
    return (tablica.size()==tablica[0].size());
}

double Macierz::wyznacznik()
{
    if (tablica.size()==0 || tablica[0].size()==0)
    {
        throw invalid_argument("Nie mozna obliczyc wyznacznika macierzy, ktora ma 0 liczbe wierszy badz kolumn");
    }
    
    if(!Macierz::czykwadratowa())   // wyznaczik moze byc liczony tylko w przypadku macierzy kwadratowej
    throw invalid_argument ("Nie jest to macierz kwadratowa");
    
    int i,j,k;
    Macierz copy(lwierszy(),lkolumn());                          // kopia macierzy z ktorej liczony jest wyznaczik
    double multiplier;                          // przechowuje skalar przez ktory mnozony jest pierwszy wiersz
    double determinant;
   

    for(i=0; i < lwierszy(); i++)                     // kopiowanie macierzy
    for(j=0; j < lkolumn(); j++)
    copy.tablica[i][j] = tablica[i][j];
    for(i=0; i < lkolumn()-1; i++)                         // zerowanie elementow w i-tej kolumnie
    {
        for(j=i+1; j < lwierszy(); j++)                   // zerowanie w j-tym wierszu i-tej kolumny
        {
            multiplier = copy.tablica[j][i] / copy.tablica[i][i];        // obliczanie odpowiedniej wielokrotnosci 1-go (i-tego) wierza
            for(k=i+1; k< lkolumn() ; k++)                              // dodawanie 1-go (i-tego) wiersza do wiersza j-tego (po k kolumnach)
            {   
                copy.tablica[j][k] -= copy.tablica[i][k] * multiplier;
            }
        }
    }
    determinant = 1;                            // w efekcie otrzymana zostala macierz trojkatna
    for(i=0; i < lwierszy(); i++)
    {                                         // ktorej wyznacznik jest iloczynem elementow na glownej przekatnej
        determinant *= copy.tablica[i][i];
    }
    return determinant;
}

void Macierz::t()//transpozycja macierzy
{
    if (tablica.size()==0 || tablica[0].size()==0)
    {
        throw invalid_argument("Nie mozna transponowac macierzy ktora ma 0 liczbe wierszy badz kolumn");
    }
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
    for(int i=0;i<tmp.lwierszy();i++)
    {
        for(int j=0;j<tmp.lkolumn();j++)
        {
            tablica[i][j]=tmp.tablica[i][j];//przepisywanie
        }
    }
}

Macierz Macierz::diag(int i)//przeksztalca macierz na diagonalna o danym rozmiarze
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

void Macierz::invert()//odwrocenie macierzy metoda Gaussa Jordana
{
    if (tablica.size()==0)
    {
        throw invalid_argument("Nie mozna obrocic macierzy 0 wierszowej");
    }
    if (!czykwadratowa())
    {
        throw invalid_argument( "Odwrocona moze byc tylko macierz kwadratowa" );
    }
    int j, i, k, kj;
    int n=lwierszy();
    const int m=2*n;
    Macierz tmp(n, m, 0.0);
    
    vector<double> tym(m); //do poprawnej normalizacji
    vector<double> tym2(m);
    
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
            tmp.tablica[i][j] = (j == n+i) ? 1 : 0;
        }
    }
    for (j=0;j<n;j++) //petla po kazdym wierszu
    {                    //normalizacja
        for (i=0;i<m;i++) // petla dla kazdej kolumny danego wiersza dla normalizacji
        {
            if (i != j)
            {
                if(tmp.tablica[j][j]==0) // Zamiana wierszy miejscami, w sytuacji, gdyby tablica[j][j] = 0
                {   
                    kj=j;
                    for(int v=0;v<n;v++)
                    {
                        tym=tmp.tablica[kj];
                        tym2=tmp.tablica[kj+1];
                        if(j==n)
                        {
                           throw invalid_argument("Ta macierz nie moze byc odwrocona");
                        } 
                        tmp.tablica[kj]=tym2;
                        tmp.tablica[kj+1]=tym;
                        kj++;
                    }
                }
                tmp.tablica[j][i] /= tmp.tablica[j][j];
            }
        }
        tmp.tablica[j][j]=1;              //redukcja
        for (k = 0;k<n;k++)   // dla kolejnych wierszy
        {
            if (k != j)
            {
                for (i = 0;i<m; i++)  // dla kolejnych kolumn
                {
                    if (i != j)
                    {
                        tmp.tablica[k][i] -= (tmp.tablica[k][j] * tmp.tablica[j][i]);
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

Macierz operator+(const Macierz &a, const Macierz &m)//operacja dodawania
{
    if (a.tablica.size()==0 || a.tablica[0].size()==0)
    {
        throw invalid_argument("Nie mozna dodac macierzy ktora ma 0 liczbe wierszy badz kolumn");
    }
    if ((a.lwierszy()==m.lwierszy()) && (a.tablica[0].size()==m.tablica[0].size()))//warunek poprawnych wymiarow
    {
        Macierz tmp(a.lwierszy(), a.tablica[0].size());
        for(int i=0;i<a.lwierszy();i++)
        {   
            for(unsigned int j=0;j<(a.tablica[0].size());j++)
            {
                tmp.tablica[i][j]=a.tablica[i][j]+m.tablica[i][j];
            }
        }
        return tmp;
    }
    else
    {
        throw invalid_argument ("Niekompatybilne rozmiary macierzy! (operator +)");
    }
}

Macierz operator-(const Macierz& a, const Macierz& m)//operacja odejmowania wszystkie operatory nie dzialaja, czasem dzialaja
{
    if (a.tablica.size()==0 || a.tablica[0].size()==0)
    {
        throw invalid_argument("Nie mozna odjac macierzy ktora ma 0 liczbe wierszy badz kolumn");
    }
    if ((a.lwierszy()==m.lwierszy())&&(a.lkolumn()==m.lkolumn()))//warunek czy te same rozmiary
    {
        Macierz tmp(a.lwierszy(),a.lkolumn(),0);
        for(int i=0;i<(a.lwierszy());i++)
        {   
            for(int j=0;j<(a.lkolumn());j++)
            {
            tmp.tablica[i][j]=(a.tablica[i][j]-m.tablica[i][j]);
            }
        }
        return tmp;
    }
    else
    {
    throw invalid_argument ("Niekompatybilne rozmiary macierzy! (operator -)");
    }
}

Macierz operator-( const Macierz& a ) //zmiana znaku elementow macierzy
{
    if (a.tablica.size()==0 || a.tablica[0].size()==0)
    {
        throw invalid_argument("Nie mozna zmienic znaku macierzy ktora ma 0 liczbe wierszy badz kolumn");
    }
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
    if (a.tablica.size()==0 || a.tablica[0].size()==0)
    {
        throw invalid_argument("Nie mozna pomozyc macierzy ktora ma 0 liczbe wierszy badz kolumn");
    }
    if (a.lkolumn()==m.lwierszy())// sprawdzenie czy mozna pomnozyc te macierze
    {
        Macierz tmp(a.lwierszy(),m.lkolumn());
        for( int i=0; i<tmp.lwierszy(); i++ )
        {
            for( int j=0; j<tmp.lkolumn(); j++ ) 
                {
                    for( int k=0; k<a.lkolumn(); k++ )
                    {
                        tmp.tablica[i][j] += a.tablica[i][k] * m.tablica[k][j];//wymnazanie elementow
                    }
                }
        }
        return tmp;
    }        
    else
    {
        throw invalid_argument ("Niekompatybilne rozmiary macierzy! (operator *)");
    }
    
}

Macierz operator*(double f, const Macierz& m)//operacja mnozenia macierzy przez stala
{
    if (m.tablica.size()==0 || m.tablica[0].size()==0)
    {
        throw invalid_argument("Nie mozna pomozyc macierzy ktora ma 0 liczbe wierszy badz kolumn");
    }
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

Macierz operator/(const Macierz& a, const Macierz& m)//mnozenie macierzy z odwrotnoscia 2 macierzy
{
   Macierz tmp;
   tmp=m;
   tmp.invert();
   return(a*tmp); 
}

std::ostream & operator << ( std::ostream & wyjscie, Macierz const& _m )  // przeciazony operator << zwraca wskaznik na obiekt klasy ostream o (np cout)
{
    for(int k=0;k<_m.lwierszy();k++)
    {
        wyjscie<<std::endl;
        for (int l=0;l<_m.lkolumn();l++)
    {
        wyjscie<<_m.tablica[k][l]<<" ";
    }
    }
    wyjscie << std::endl;
}

std::istream & operator >> ( std::istream & mat, Macierz& m ) // przeciazony operator << zwraca wskaznik na obiekt klasy istream o (np cin)
{                    //przykladowy wzor wprowadzania macierzy: [a1, a2, a3; a4, a5, a6], spacje tez moga byc separatorem
    bool ok=false;
    string macierz, sub;
    char znak;
    vector<double> n,nn;
    double tym;
    int i=0, j=0, k=0, l=0,h=0;
    mat.clear();
    while(!ok)
    {
        mat>>znak;
        if (znak!='[')//petla, ktora spawdza czy wprowadzono poprawny znak poczatku macierzy
        {
            mat.clear();
            cout<<"Zacznij deklarowanie macierzy od znaku: '['"<<endl;
            continue;
        }
        mat>>tym;
        mat.clear();
        n.push_back(tym);
        while(true)
        {
            mat.get(znak);
            if ( (znak==',') || (znak==' '))//akcja dla nowych elementow w wierszu
            {
                j++;
                mat>>tym;
                mat.clear();
                n.push_back(tym);
            }
            else if (znak==']')//akcja dla konca macierzy
            {
                if(i>=1)
                {
                    l=j-k+1-((i-1)*k);//obliczenie 2 zmiennej do porownania
                    if (k!=l)//jezeli sa rozne to znaczy, ze wprowadzono mniej elementow niz powinno
                    {
                        throw invalid_argument("Zle wpisane dane, macierz musi miec taka sama ilosc elementow w kazdym wierszu");
                    }
                }
                ok=true;
                break;
            }
            else if (znak==';')//akcja dla srednika, nowy wiersz
            {
                i++;
                j++;
                k=j-k*(i-1);//zmienna, ktora jest potrzebna do wyliczenia czy jest wprowadzona taka sama liczba el. w wierszu
                mat>>tym;
                mat.clear();
                n.push_back(tym);
            }
        }
        m.tablica.clear();
        for (int u=0;u<=i;u++)//przepisanie poszczegolnych elementow na wektor, ktory nastepnie jest wklejany do macierzy
        {
            for (int v=0;v<=((j)/(i+1));v++)
            {
                nn.push_back(n[h]);
                h++;
            }
            m.tablica.push_back(nn);
            nn.clear();
        }
    }
    return mat;
}