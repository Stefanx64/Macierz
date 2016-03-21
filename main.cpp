#include <iostream>
#include "macierz.h"

using namespace std;

ostream & operator<< ( ostream & wyjscie, Macierz const& _m )
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

int main(int argc, char **argv)
{
    cout<<"Podaj liczbe wierszy i kolumn macierzy:"<<endl;
    int n=3;
    int m=3; 
    //double z=1;
    cin>>n;
    cin>>m;
    double a;
    //cin>>z;
    Macierz costam(n,m);
    costam.wprowadz();/*
    cout<<"Odwrocona macierz: "<<endl;
    costam.invert();
    costam.wyswietl();
    cout<<"Wyznacznik macierzy: "<<(costam.determ())<<endl;*/
    costam.t();
    cout<<"Macierz po transpozycji: "<<endl;
    costam.wyswietl();
    Macierz druga(n,m,5);
    Macierz trzecia(n,m);
    trzecia=druga+costam;
    cout<<"Macierz 3: +"<<endl;
    trzecia.wyswietl();
    trzecia=druga-costam;
    cout<<"Macierz 3: -"<<endl;
    trzecia.wyswietl();
    a=costam.determ();
    cout<<"cos tam : "<<costam<<"   "<<a<<endl;
    trzecia=a*druga;
    cout<<"Macierz 3: *"<<endl;
    trzecia.wyswietl();
    costam.invert();
    costam.wyswietl();
    trzecia=costam;
    cout<<"Macierz 3: /"<<endl;
    trzecia.wyswietl();

    return 0;
}









//------------------------------------------------------------------------------------
    //double i=costam.n;
    //double j=costam.m;
    //cout<<"ccc"<<i<<"   "<<j<<endl;
    /*    //cout<<costam;
    //costam.dodajwiersz();
    //costam.dodajkolumne();
    //costam.usunwiersz(0);
    cout<<"macierz do transpozycji: "<<costam<<endl;
    Macierz kaczka(n+1,m,5);
    //costam.t();
    kaczka=Macierz::diag(5);
    cout<<"Kaczka to: "<<kaczka<<endl;
    cout<<"po transpozycji"<<endl;
    cout<<kaczka+costam<<endl;
    costam.wyswietl();
    //Macierz wypelniona(n,m,z);
    //cout<<"liczba wierszy: "<<wypelniona.tablica.size()<<"  liczba kolumn: "<<wypelniona.kolumna.size()<<"   "<<endl;
    
    cout<<"Wynik wyznacznika to: "<<costam.determ()<<endl;
    /*
    double d, e; 
    cout<<wyelniona.tablica[0][0];
    cout<<"liczba wierszy macierzy a: "<<d <<"  , a liczba kolumn: "<<e<<endl;
    cout<<endl<<"koniec"<<endl;*/