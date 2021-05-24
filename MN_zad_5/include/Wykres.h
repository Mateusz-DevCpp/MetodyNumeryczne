void rysuj_wykres(double a, double b, char wybor, vector<Punkt<double> >  punkty_aproksymacji, double PRECYZJA=0.01)
{
    double maxim_y = 0;
    double minim_y = 0;

    std::vector<Punkt<double> > punkty_funkcji;

    for(double p=a; p<=b; p+=PRECYZJA)
    {
        double save_y = funkcja(p, wybor);
        punkty_funkcji.push_back(Punkt<double>(p, save_y));

        if(save_y > maxim_y) maxim_y = save_y;
        if(save_y < minim_y) minim_y = save_y;
    }

    GnuPlot::SetSize(a,b,minim_y-1, maxim_y+1);
    GnuPlot::SetTitle("Aproksymacja");
    GnuPlot::AddLines(punkty_funkcji,"1","00FFFF","Funkcja");
    GnuPlot::AddLines(punkty_aproksymacji,"2","FF0000","Aproksymacja");
    GnuPlot::EnableAxis();
    GnuPlot::Draw();
}
