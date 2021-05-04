#ifndef __GNUPLOT_MANAGER_H__
#define __GNUPLOT_MANAGER_H__

/**<!>**
 *
 * \Informations
 * \Author: Mateusz Darul
 * \Version: 1.2.1
 * \Contact: mateuszdarul7@gmail.com
 *
 **<!>**/

/** DOC

    clear plot memory (clear plot window and commands)
void Clear()

    draw plot window
void Draw();

    add one point to graph
        x - position x
        y - position y
        point type - string {"1", "2", "3", "...", "78"} different point look
        rgb_color - color in hex {"00ff00", ...}
        title - title of points - title is showed in legend
void AddPoint(double x, double y, std::string point_type, std::string rgb_color, std::string title);

    add list of points to graph
        points - vector with points (type Point<double>)
        point type - string {"1", "2", "3", "...", "78"} different point look
        rgb_color - color in hex {"00ff00", ...}
        title - title of points - title is showed in legend
void AddPoints(std::vector<Point<double>> points ,std::string point_type, std::string rgb_color, std::string title);

    add line to graph
        x1, y1 - position of begin line
        x2, y2 - position of end line
        point type - string {"1", "2", "3", "...", "78"} different point look
        rgb_color - color in hex {"00ff00", ...}
void AddLine(double x1, double y1, double x2, double y2, std::string point_type, std::string rgb_color);

    set view range
void SetSize(double range_x_begin, double range_x_end, double range_y_begin, double range_y_end);
void SetSize(Range przedzial_x, Range przedzial_y);
void SetSize(Range przedzial);

    set graph title
void SetTitle(std::string title);

    enable graph grid
        x_grid - enable x lines
        y_grid - enable y lines
void EnableGrid(bool x_grid, bool y_grid);

    disable graph grid
void DisableGrid();

    enable graph axis
        x_axis - enable x axis
        y_axis - enable y axis
void EnableAxis(bool x_axis, bool y_axis)

    disable graph axis
void DisableAxis();

    set legend config
        option - {"disable", "outside", "default", "bottom", "at 2,3.5,2", ...}
void SetLegend(std::string option);

    if graph is visible for 1 sec on this option
void EnablePause();
void DisablePause();

    you can add your own gnuplot commands
void AddCommand_main_cmd(std::string command);
void AddCommand_point_cmd(std::string command);

*/

#include "include/GnuPlot.h"
#include "include/Define.h"

#endif // __GNUPLOT_MANAGER_H__
