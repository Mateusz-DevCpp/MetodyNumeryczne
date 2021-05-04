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

    GnuPlot::Clear();
    GnuPlot::EnablePause();
    GnuPlot::EnableAxis();
    GnuPlot::AddPoints(obszar_calki, "0", "ff0000", "Calka");
    GnuPlot::AddLines(punkty_funkcji,"3","000000","Funkcja");
    GnuPlot::SetTitle(funkcja_str+"e^-^x^^2");
    GnuPlot::Draw();
}
