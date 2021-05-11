#include "Wykres.h"

void Wykres::Rysuj(std::string funkcja_str, funkcja wzor, double przedzial_p, double przedzial_k)
{
    double maxim_y = 0;
    double minim_y = 0;
    std::vector<Punkt<double>> punkty_funkcji;
    for(double p=-4; p<=4; p+=0.1)
    {
        double save_y = wzor(p)*f_w(p);
        punkty_funkcji.push_back(Punkt<double>(p, save_y));

        if(save_y > maxim_y) maxim_y = save_y;
        if(save_y < minim_y) minim_y = save_y;
    }

    double skala_kroku = 1;
    if(maxim_y - minim_y < 4) skala_kroku = 0.5;

    double o_krok = 0.1;
    std::vector<Punkt<double>> obszar_calki;
    for(double p=przedzial_p; p<=przedzial_k; p+=o_krok)
    {
        double y_max = wzor(p)*f_w(p);
        if(y_max < 0)
        {
            for(double y=-o_krok*skala_kroku; y>y_max; y-=o_krok*skala_kroku)
            {
                obszar_calki.push_back(Punkt<double>(p,y));
            }
        }
        else
        {
            for(double y=o_krok*skala_kroku; y<y_max; y+=o_krok*skala_kroku)
            {
                obszar_calki.push_back(Punkt<double>(p,y));
            }
        }
    }

    GnuPlot::SetSize(-4,4,minim_y, maxim_y);
    GnuPlot::AddPoints(obszar_calki, "0", "8c8c8c", "Wynik calki");
    GnuPlot::AddLines(punkty_funkcji,"3","00FFFF","Funkcja");
    GnuPlot::SetTitle(funkcja_str+"e^-^x^^2");
}

void Wykres::Rysuj_Hermite(std::vector<Punkt<double>> punkty)
{
    std::vector<Punkt<double>> punkty_funkcji_interpolowanej = Interpolacja::obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Lagrange(Punkt<double>(-4,4), punkty, 0.01);

    GnuPlot::AddLines(punkty_funkcji_interpolowanej, "1", "FF0000", "Wielomian Hermite'a");
    GnuPlot::AddPoints(punkty, "1", "FF0000", "Punkty Hermite'a");
}

void Wykres::Rysuj_Simsona(std::vector<Punkt<double>> punkty)
{
    std::vector<Punkt<double>> punkty_funkcji_interpolowanej;

    for(unsigned int i=0; i<punkty.size()-1; i++)
    {
        std::vector<Punkt<double>> wezly;
        for(int x=0; x<3; x++)
        {
            wezly.push_back(Punkt<double>(punkty[i+x].x, punkty[i+x].y));
        }

        std::vector<Punkt<double>> tmp;
        tmp = Interpolacja::obliczWartosciFunkcjiInterpolowanejNaPrzedziale_Lagrange(Punkt<double>(wezly[0].x,wezly[2].x), wezly, 0.01);
        for(unsigned int z=0; z<tmp.size(); z++)
        {
            punkty_funkcji_interpolowanej.push_back(tmp[z]);
        }

        wezly.clear();
        tmp.clear();
    }

    GnuPlot::AddLines(punkty_funkcji_interpolowanej, "1", "FF0000", "Metoda Simpsona");
    GnuPlot::AddPoints(punkty, "1", "FF0000", "Punkty Simpsona");
}

void Wykres::Draw()
{
    GnuPlot::EnablePause();
    GnuPlot::EnableAxis();
    GnuPlot::Draw();
}
