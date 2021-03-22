#ifndef GNUPLOT_H
#define GNUPLOT_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define GNUPLOT_NAME "gnuplot"

class GnuPlot
{
private:
    static std::string main_cmd;
    static std::string config_cmd;
    static std::vector<std::string> points;

public:
    static void Clear();
    static void Draw();
    static void AddPoint(double x, double y, std::string group="1");
    static void AddLine(double x1, double y1, double x2, double y2, std::string group="1");

    static void SetSize(double range_x_begin, double range_x_end, double range_y_begin, double range_y_end);
    static void EnableGrid(bool x_grid=true, bool y_grid=true);
    static void DisableGrid();
    static void EnableAxis(bool x_axis=true, bool y_axis=true);
    static void DisableAxis();
    static void SetLegend(std::string option);

    static void AddCommand_main_cmd(std::string cmd);
    static void AddCommand_point_cmd(std::string cmd);
};

/** std::string group -> Liczba calkowita np "0" lub "2" ... */

#endif // GNUPLOT_H
