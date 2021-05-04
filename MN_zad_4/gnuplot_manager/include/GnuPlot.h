#ifndef __GNUPLOT_H__
#define __GNUPLOT_H__

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <math.h>

#include "Define.h"
#include "../../include/Define.h"

#define GNUPLOT_NAME "gnuplot"

class GnuPlot
{
private:
    static bool use_moues_pause;
    static std::string main_cmd;
    static std::string config_cmd;
    static std::vector<std::string> points_cmd;

public:
    static void Clear();
    static void Draw();
    static void AddPoint(double x, double y, std::string point_type="1", std::string rgb_color="FF0000", std::string title="-");
    static void AddPoints(std::vector<Punkt<double>> points ,std::string point_type="1", std::string rgb_color="FF0000", std::string title="-");
    static void AddLine(double x1, double y1, double x2, double y2, std::string point_type="1", std::string rgb_color="FF0000");
    static void AddLines(std::vector<Punkt<double>> points ,std::string point_type="1", std::string rgb_color="FF0000",  std::string title="-");

    static void SetSize(double range_x_begin, double range_x_end, double range_y_begin, double range_y_end);
    static void SetSize(Range przedzial_x, Range przedzial_y);
    static void SetSize(Range przedzial);
    static void SetTitle(std::string title);
    static void EnableGrid(bool x_grid=true, bool y_grid=true);
    static void DisableGrid();
    static void EnableAxis(bool x_axis=true, bool y_axis=true);
    static void DisableAxis();
    static void SetLegend(std::string option);
    static void EnablePause();
    static void DisablePause();

    static void AddCommand_main_cmd(std::string cmd);
    static void AddCommand_point_cmd(std::string cmd);
};

/** std::string group -> Liczba calkowita np "0" lub "2" ... */

#endif // __GNUPLOT_H__
