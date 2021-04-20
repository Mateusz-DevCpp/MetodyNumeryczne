#include "Bledy.h"

double Bledy::najwiekszyBladZbioru(std::vector<Punkt<double>> wartosci_poprawne, std::vector<Punkt<double>> wartosci_wyliczone)
{
    std::vector<double> blad;
    for(int i=0; i<wartosci_poprawne.size(); i++)
    {
        if(wartosci_poprawne[i].x == wartosci_wyliczone[i].x)
            blad.push_back(bladDanegoPunktu(wartosci_poprawne[i], wartosci_wyliczone[i]));
    }
    sort(blad.begin(), blad.end());
    return blad[blad.size()-1];
}

double Bledy::bladDanegoPunktu(Punkt<double> poprawny, Punkt<double> obliczony)
{
    return fabs( poprawny.y - obliczony.y );
}
