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
    return (tablica.size()==kolumna.size());
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
    if ((a.lwierszy()==m.lwierszy()) && (a.tablica[0].size()==m.tablica[0].size()))
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
    if ((a.lwierszy()==m.lwierszy())&&(a.lkolumn()==m.lkolumn()))
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

Macierz operator/(const Macierz& a, const Macierz& m)//mnozenie macierzy z odwrotnoscia 2 macierzy nie dziala, ale invert tez nie dziala
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
{
    bool ok=false;
    string macierz, sub;
    char znak;
    Macierz tmp(5,5);
    int size=5;
    vector<double> n,nn;
    double tym;
    int i=0, j=0,k=0,h=0;
    mat.clear();
    while(!ok)
    {
        mat>>znak;
        if (znak!='[')
        {
            mat.clear();
            string s;
            mat >> s;
            cout<<"Zacznij deklarowanie macierzy od znaku: '['"<<endl;
            continue;
        }
        mat>>tym;
        n.push_back(tym);
        while(true)
        {
            mat.get(znak);
            size++;
            if ( (znak==',') || (znak==' '))
            {
                j++;
                mat>>tym;
                n.push_back(tym);
            }
            else if (znak==']')
            {
                ok=true;
                break;
            }
            else if (znak==';')
            {
                i++;
                j++;
                mat>>tym;
                n.push_back(tym);
            }
        }
        m.tablica.clear();
        for (int u=0;u<=i;u++)
        {
            for (int v=0;v<=((j)/(i+1));v++)
            {
                nn.push_back(n[h]);
                h++;
            }
            m.tablica.push_back(nn);
            nn.clear();
        }
    }return mat;
}
        /*getline(cin, macierz);
        znaleziono=macierz.find_first_of("abcdefghijklmnopqrstuwxyz!@#$%^&*()_+=/`'~<>?");
        if ((int)znaleziono!=-1)
        {
            throw invalid_argument("Akceptowane sa tylko wartosci liczbowe");
        }
        dlugosc = macierz.size();
        if (macierz.at(0)!='[')
        {
            throw invalid_argument("Macierz musi rozpoczac sie od [");
        }
        macierz.erase(0,1);
        while (!macierz.empty())
        {   
            znaleziono=macierz.find_first_of(" ,");cout<<znaleziono<<"<- to znaleziono\n";
            srednik=macierz.find_first_of(";");cout<<"Srednik "<<srednik<<endl;
            if (srednik<znaleziono)
            {
                i++;
                macierz.erase(0,1);
            znaleziono=macierz.find_first_of(" ,");cout<<znaleziono<<"<- to znaleziono\n";
            }
            sub=macierz.substr(0,znaleziono);cout<<"sub= "<<sub<<"|"<<endl;
            macierz.erase(0,sub.size()+1);
            cout<<macierz;
            m.tablica[i][j]=stod(sub);
            cout<<"Element: "<<m.tablica[i][j]<<endl;
            j++;
            
            if (macierz.find_first_of("]")!=-1)
            {
                ok=true;
            }
        }*/

    /*while(cin)
    {
        cin.get(znak);
        if (znak=='[')
        {
            n=wczytajLiczbe<double>();
            m.tablica[0][0]=n;
            while (!koniec)
            {
               koniecwiersza=false;
               while (!koniecwiersza)
               {
                   if (znak==',' || znak==' ')
                   {cout<<"Wpisz el tablica ["<<i<<"]["<<j<<"]"<<endl;
                       n=wczytajLiczbe<double>();
                       m.tablica[i][j]=n;
                       j++;  
                   }
                   if (znak==';' || znak==']')
                   {
                       koniecwiersza=true;
                       i++;
                       if (znak==']')
                       {
                           koniec=true;
                       }
                   }
               }   
                cin.get(znak);
                if (znak==']')
                {
                    koniec=true;
                }
           }
        }    return mat;
    }
}*/
    /*cin.get
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
    
    int nwiersz, nkolumna;
    mat >> nwiersz >> nkolumna;
    Macierz tmp(nwiersz,nkolumna);
    m=tmp;
    
    for( int i=0; i<nwiersz; i++ ) 
    {
        for( int j=0; j<nkolumna; j++ )
        {
            mat >> m.tablica[i][j];
        }
    }
    return mat;
}*/


/********************************************************************
Kosz:
void Macierz::set(int nwierszy, int nkolumn, double liczba)
{
    if (nwierszy<=0 || nkolumn<=0)
    {
    cout<< "Liczba wierszy i kolumn musi byc wieksza od 0"<<endl;
    }
    kolumna.resize(nkolumn, liczba);
    tablica.resize(nwierszy, kolumna);
    for(int k=0;k<lwierszy();k++)
    {
        for (int l=0;l<nkolumn;l++)
        {
        tablica[k][l]=liczba;
        }
    }
}

 * 
 * Poprzednia wersja usun kolumne:
 *     /*Macierz tmp(lwierszy(),(lkolumn()-1));
    for(int i=0;i<lwierszy();i++)//przepisywanie
    {
        for(int j=0;j<(tmp.tablica[0].size());j++)
        {
            tmp.tablica[i][j]=tablica[i][j];
        }
    }
    kolumna.resize(tmp.lkolumn());
    
    for(int i=0;i<tmp.lwierszy();i++)//przepisywanie
    {
        for(int j=0;j<tmp.lkolumn();j++)
        {
            tablica[i][j]=tmp.tablica[i][j];
        }
    }
     * 
    Poprzednia wersja dodaj kolumne
     Macierz tmp(tablica.size(),lkolumn());//tymczasowa do przepisania
    for(unsigned int i=0;i<tablica.size();i++)
        {for(int j=0;j<lkolumn();j++)
        {
            tmp.tablica[i][j]=tablica[i][j];//przepisanie
        }
        }

    for(unsigned int i=0;i<tablica.size();i++)//przepisywanie
        {for(int j=0;j<(lkolumn()-1);j++)
        {
            tablica[i][j]=tmp.tablica[i][j];
        }
        }
        for(unsigned int i=0;i<tablica.size();i++)
        {   
            wprowadz(i,lkolumn()-1);
        }
Poprzednia wersja transpozycji
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
 * 
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

double Macierz::determ(int n) // fcja private do obliczania wyznacznika
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

*/