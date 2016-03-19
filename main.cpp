#include <iostream>
#include "macierz.h"

using namespace std;

ostream & operator<< ( ostream & wyjscie, Macierz const& _m )
{

    for(int k=0;k<_m.tablica.size();k++)
    {
        wyjscie<<std::endl;
        for (int l=0;l<_m.kolumna.size();l++)
    {
        wyjscie<<_m.tablica[k][l]<<" ";
    }
    }
    wyjscie << std::endl;
}

int main(int argc, char **argv)
{
    int n=3;
    int m=3; 
    double z=1;
    cin>>n;
    cin>>m;
    //cin>>z;
    Macierz costam(n,m);
    //costam.wprowadz();
    //cout<<costam;
    costam.dodajwiersz();
    //costam.dodajkolumne();
    //costam.usunwiersz(0);
    cout<<costam<<"macierz do transpozycji"<<endl;
    costam.t();
    cout<<costam;
    costam.wyswietl();
    //Macierz wypelniona(n,m,z);
    //cout<<"liczba wierszy: "<<wypelniona.tablica.size()<<"  liczba kolumn: "<<wypelniona.kolumna.size()<<"   "<<endl;
    
    cout<<"Wynik wyznacznika to: "<<costam.determ()<<endl;
    /*
    double d, e; 
    cout<<wyelniona.tablica[0][0];
    cout<<"liczba wierszy macierzy a: "<<d <<"  , a liczba kolumn: "<<e<<endl;
    cout<<endl<<"koniec"<<endl;*/
    
    return 0;
}









//------------------------------------------------------------------------------------
    //double i=costam.n;
    //double j=costam.m;
    //cout<<"ccc"<<i<<"   "<<j<<endl;
    /*int nwierszy;
    
    int mkolumn;
    
    
    vector<double> kolumna(mkolumn, 1);
    vector< vector<double> > tablica(nwierszy, kolumna);
    vector<double>::iterator itk;
    vector< vector<double> >::iterator itw;
    
    cout<<tablica.size()<<" "<<"   "<<endl;
    for(int k=0;k<tablica.size();k++)
    {
        cout<<endl;
        for (int l=0;l<kolumna.size();l++)
    {
        cout<<tablica[k][l]<<" ";
    }
    }
    
    for (itw=tablica.begin(); itw!=tablica.end(); ++itw) {
    for (itk=itk->begin(); itk!=itk->end(); ++itk) {
      cout<<("%d\n", *itk);
    }
  }*/