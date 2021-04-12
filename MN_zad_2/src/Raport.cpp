#include "Raport.h"

Raport::Raport()
{
    ilosc_iteracji = 0;
    ilosc_iteracji_z_dzialaniami = 0;
}

void Raport::reset()
{
    ilosc_iteracji = 0;
    ilosc_iteracji_z_dzialaniami = 0;
}

std::string Raport::toString()
{
    std::stringstream ss;
    ss << char(201);
    for(int i=0; i<5; i++)
        ss << char(205);
    ss << "RAPORT";
    for(int i=0; i<5; i++)
        ss << char(205);
    ss << "\n";
    ss << char(204) << "ilosc iteracji: " << ilosc_iteracji << "\n";
    ss << char(204) << "ilosc iteracji z dzialaniami: " << ilosc_iteracji_z_dzialaniami << "\n";
    ss << char(204) << "numer iteracji - ilosc zer w macierzy\n";
    for(int i=0; i<historia.size(); i++)
        ss << char(204) << char(205) << historia[i].x << " - " << historia[i].y << "\n";
    ss << char(200);
    for(int i=0; i<16; i++)
        ss << char(205);
    ss << "\n";
    return ss.str();
}

void Raport::drawRaport()
{
    GnuPlot::EnablePause();
    GnuPlot::Clear();
    GnuPlot::SetLegend("disable");
    GnuPlot::EnableAxis();
    GnuPlot::SetSize(Range(0.0, (double)historia[historia.size()-1].x), Range(0.0, (double)historia[historia.size()-1].y));
    GnuPlot::AddPoints(historia,"2","000000");
    GnuPlot::SetTitle("Ilosc zer w macierzy od ilosci iteracji");
    GnuPlot::Draw();
}

void Raport::dodajHistorie(int x, int y)
{
    historia.push_back(Point<double>(x,y));
}
