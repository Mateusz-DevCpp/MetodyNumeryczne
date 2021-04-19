/**<!>**
 *
 * \Informations
 * \Author: Mateusz Darul
 * \Version: 1.2.1
 * \Contact: mateuszdarul7@gmail.com
 *
 **<!>**/

#ifndef __MN_GNUPLOT_H__
#define __MN_GNUPLOT_H__

#include "include/Define.h"
#include "include/GnuPlot.h"

#define GNUPLOT_NAME "gnuplot"
/**
class GnuPlot -> jest to klasa statyczna (wszystkie metody sa metodami statycznymi).
{
    Clear() -> metoda sluzaca wyczyszczeniu okna gnuplot
    Draw() -> metoda sluzaca do wyswietlenia okna gnuplot
    AddPoint(double x, double y, std::string point_type="1", std::string rgb_color="FF0000", std::string title="-");
    AddPoints(std::vector<Point<double>> points ,std::string point_type="1", std::string rgb_color="FF0000", std::string title="-");
    AddLine(double x1, double y1, double x2, double y2, std::string point_type="1", std::string rgb_color="FF0000");

    SetSize(double range_x_begin, double range_x_end, double range_y_begin, double range_y_end);
    SetSize(Range przedzial_x, Range przedzial_y);
    SetSize(Range przedzial);
    SetTitle(std::string title);
    EnableGrid(bool x_grid=true, bool y_grid=true);
    DisableGrid();
    EnableAxis(bool x_axis=true, bool y_axis=true);
    DisableAxis();
    SetLegend(std::string option);
    EnablePause();
    DisablePause();

    AddCommand_main_cmd( wartosc tekstowa - polecenia konsoli gnuplot );
    AddCommand_point_cmd(wartosc tekstowa - polecenia konsoli gnuplot );
};
*/
#endif // __MN_GNUPLOT_H__
