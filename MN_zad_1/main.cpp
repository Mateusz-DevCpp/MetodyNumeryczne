#include <iostream>
#include <math.h>
#include <stdio.h>
#include <windows.h>

#include "include/GnuPlot.h"

#include "Define.h"
#include "Funkcje.h"
#include "MetodaSiecznych.h"
#include "MetodaStycznych.h"
#include "Horner.h"

bool mozeWystepowacPierwiastek(fun funkcja, Przedzial p);
bool mozeWystepowacPierwiastek_Horner(std::vector<double> f, Przedzial p);

fun fun_list[8] {wielomian,trygon,wykladnicza,mieszana,wielomian_p,trygon_p,wykladnicza_p,mieszana_p};

int main()
{
    std::vector<double> wsp_f;
    wsp_f.push_back(1);
    wsp_f.push_back(1);
    wsp_f.push_back(-2);
    wsp_f.push_back(-1);
    std::vector<double> wsp_p;
    wsp_p.push_back(1);
    wsp_p.push_back(2);
    wsp_p.push_back(3);

    int f_id = 0;
    Przedzial przedzial;
    int warunek_stop = 0;
    double stop = 0;

    std::cout << "Wybiez funkcje:" << std::endl;
    std::cout << "0. ((x+1)*x-2)*x-1" << std::endl;
    std::cout << "1. sin(x)-cos(x+1)" << std::endl;
    std::cout << "2. exp(x)-4*x" << std::endl;
    std::cout << "3. sin(exp(-x*x))-0.5" << std::endl;
    std::cin >> f_id;

    std::cout << "Podaj przedzial:" << std::endl;
    std::cout << "poczatek: >";
    std::cin >> przedzial.begin;
    std::cout << "koniec  : >";
    std::cin >> przedzial.end;

    std::cout << "Wybiez warunek stopu:" << std::endl;
    std::cout << "0. spelnienie warunku nalozonego na dokladnosc" << std::endl;
    std::cout << "1. osiagniecie zadanej liczby iteracji" << std::endl;
    std::cin >> warunek_stop;

    if(warunek_stop == 0)
    {
        std::cout << "Podaj wartosc E:" << std::endl;
        std::cin >> stop;
        if(f_id == 0)
        {
            if(mozeWystepowacPierwiastek_Horner(wsp_f, przedzial))
            {
                std::cout << "Metoda siecznych: ";
                std::cout << MetodaSiecznych::szukanieMtSiecznych_E_W(wsp_f, przedzial, stop) << std::endl;
                std::cout << "ilosc iteracji: " << MetodaSiecznych::PodajIloscIteracji() << std::endl << std::endl;

                std::cout << "Metoda stycznych: ";
                std::cout << MetodaStycznych::szukanieMtStycznych_E_W(wsp_f, wsp_p, przedzial, stop) << std::endl;
                std::cout << "ilosc iteracji: " << MetodaStycznych::PodajIloscIteracji() << std::endl << std::endl;
            }
            else
            {
                std::cout << "W podanym przedziale nie mozna znalesc pierwiastka funkcji" << std::endl;
            }
        }
        else
        {
            if(mozeWystepowacPierwiastek(fun_list[f_id], przedzial))
            {
                std::cout << "Metoda siecznych: ";
                std::cout << MetodaSiecznych::szukanieMtSiecznych_E(fun_list[f_id], przedzial, stop) << std::endl;
                std::cout << "ilosc iteracji: " << MetodaSiecznych::PodajIloscIteracji() << std::endl << std::endl;

                std::cout << "Metoda stycznych: ";
                std::cout << MetodaStycznych::szukanieMtStycznych_E(fun_list[f_id], fun_list[f_id+4], przedzial, stop) << std::endl;
                std::cout << "ilosc iteracji: " << MetodaStycznych::PodajIloscIteracji() << std::endl << std::endl;
            }
            else
            {
                std::cout << "W podanym przedziale nie mozna znalesc pierwiastka funkcji" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "Podaj ilosc iteracji:" << std::endl;
        std::cin >> stop;
        if(mozeWystepowacPierwiastek(fun_list[f_id], przedzial))
        {
            std::cout << "Metoda siecznych: ";
            std::cout << MetodaSiecznych::szukanieMtSiecznych_IT(fun_list[f_id], przedzial, stop) << std::endl;
            std::cout << "ilosc iteracji: " << MetodaSiecznych::PodajIloscIteracji() << std::endl << std::endl;

            std::cout << "Metoda stycznych: ";
            std::cout << MetodaStycznych::szukanieMtStycznych_IT(fun_list[f_id], fun_list[f_id+4], przedzial, stop) << std::endl;
            std::cout << "ilosc iteracji: " << MetodaStycznych::PodajIloscIteracji() << std::endl << std::endl;
        }
        else
        {
            std::cout << "W podanym przedziale nie mozna znalesc pierwiastka funkcji" << std::endl;
        }
    }

    return 0;
}

bool mozeWystepowacPierwiastek(fun f, Przedzial p)
{
    if(f(p.begin) * f(p.end) < 0) return true;
    else return false;
}

bool mozeWystepowacPierwiastek_Horner(std::vector<double> f, Przedzial p)
{
    if(Horner::wartoscWielomianuHorner(p.begin, f) * Horner::wartoscWielomianuHorner(p.end, f) < 0) return true;
    else return false;
}

///    7x^2 + 4x + 1
///    double ws[] = {7,4,1};
///    std::cout << wartoscWielomianu(X, 2, ws) << std::endl;






/*
    //#define __TESTY__   // comment this line to run main program
    #ifdef __TESTY__

    GnuPlot::EnableGrid();
    GnuPlot::EnableAxis();
    GnuPlot::SetSize(-10,10,-10,10);
    GnuPlot::SetLegend("outside");

    GnuPlot::AddPoint(1,1,"1");
    GnuPlot::AddPoint(2,2,"2");
    GnuPlot::AddLine(0,0,3,3,"2");
    GnuPlot::Draw();

    GnuPlot::Clear();
    GnuPlot::AddPoint(2,2,"1");
    GnuPlot::AddLine(0,0,3,3,"2");
    GnuPlot::Draw();

    GnuPlot::Clear();
    GnuPlot::SetLegend("disable");
    GnuPlot::AddPoint(1.5,1.5,"1");
    GnuPlot::AddLine(0,0,3,3,"2");
    GnuPlot::AddLine(3,3,5,0,"2");
    GnuPlot::AddCommand_main_cmd("cos(x)+sin(x+1)");
    GnuPlot::Draw();

    return 0;
    #endif // __TESTY__
*/
