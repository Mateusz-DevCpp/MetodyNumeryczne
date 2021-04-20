#include <iostream>
#include <iomanip>

#include "Define.h"
#include "Horner.h"
#include "Czebyszew.h"
#include "Interpolacja.h"
#include "Bledy.h"

#include "gnuplot_manager/Gnuplot_manager.h"

using namespace std;

int main()
{
    char wybor;
    cout << "Wybierz funkcje:" << endl;
    for(int i=1; i<=5; i++)
    {
        cout << Funkcja::idToFunkcja(i) << ". " << Funkcja::podajWzor(Funkcja::idToFunkcja(i)) << endl;
        cout << "   " << Funkcja::podajSugerowanyPrzedzial(Funkcja::idToFunkcja(i)) << endl << endl;
    }
    cout << "e. exit" << endl;
    cout << ">";
    cin >> wybor;

    if(wybor == 'e')
        return 0;

    double poczatek, koniec;
    cout << "Podaj przedzial:" << endl;
    cout << "poczatek: >";
    cin >> poczatek;
    cout << "koniec:   >";
    cin >> koniec;

    Punkt<double> przedzial(poczatek,koniec);

    int ilosc;
    cout << "Ilosc wezlow:" << endl;
    cout << ">";
    cin >> ilosc;

    char inter;
    cout << "Interpolacja:" << endl;
    cout << "n. Newtona" << endl;
    cout << "l. Labgange'a" << endl;
    cout << "o. obie" << endl;
    cout << ">";
    cin >> inter;

    vector<Punkt<double>> wezly = Czebyszew::obliczWartosciWezlow(ilosc, przedzial, wybor);
    vector<Punkt<double>> punkty_funkcji = Funkcja::obliczPunkty(przedzial, wybor, 0.01);
    vector<Punkt<double>> punkty_funkcji_interpolowanej_newton;
    vector<Punkt<double>> punkty_funkcji_interpolowanej_lagrange;

    switch(inter)
    {
    case 'n':
    {
        punkty_funkcji_interpolowanej_newton = Interpolacja::obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Newton(przedzial, wezly, 0.01);
    }
    break;
    case 'l':
    {
        punkty_funkcji_interpolowanej_lagrange = Interpolacja::obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Lagrange(przedzial, wezly, 0.01);
    }
    break;
    default:
    {
        punkty_funkcji_interpolowanej_newton = Interpolacja::obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Newton(przedzial, wezly, 0.01);
        punkty_funkcji_interpolowanej_lagrange = Interpolacja::obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Lagrange(przedzial, wezly, 0.01);
    }
    }

    if(inter == 'n')
    cout << "najwiekszy blad: " << Bledy::najwiekszyBladZbioru(punkty_funkcji, punkty_funkcji_interpolowanej_newton) << endl;
    else if(inter == 'l')
    cout << "najwiekszy blad: " << Bledy::najwiekszyBladZbioru(punkty_funkcji, punkty_funkcji_interpolowanej_lagrange) << endl;
    else
    {
    cout << "najwiekszy blad Newtona:  " << Bledy::najwiekszyBladZbioru(punkty_funkcji, punkty_funkcji_interpolowanej_newton) << endl;
    cout << "najwiekszy blad Lagrange: " << Bledy::najwiekszyBladZbioru(punkty_funkcji, punkty_funkcji_interpolowanej_lagrange) << endl;
    }

    GnuPlot::Clear();
    GnuPlot::EnablePause();
    GnuPlot::SetLegend("bottom");
    GnuPlot::EnableAxis();
    GnuPlot::AddLines(punkty_funkcji,"3","000000","Funkcja");

    if(inter == 'n')
        GnuPlot::AddLines(punkty_funkcji_interpolowanej_newton,"2","00FF00","Interpolacja Newtona");
    else if(inter == 'l')
        GnuPlot::AddLines(punkty_funkcji_interpolowanej_lagrange,"1","0000FF","Interpolacja Lagrange'a");
    else
    {
        GnuPlot::AddLines(punkty_funkcji_interpolowanej_newton,"2","00FF00","Interpolacja Newtona");
        GnuPlot::AddLines(punkty_funkcji_interpolowanej_lagrange,"1","0000FF","Interpolacja Lagrange'a");
    }

    GnuPlot::AddPoints(wezly,"4","FF0000","Wezly");
    GnuPlot::SetTitle(Funkcja::podajWzor(wybor));
    GnuPlot::Draw();

    return 0;
}
