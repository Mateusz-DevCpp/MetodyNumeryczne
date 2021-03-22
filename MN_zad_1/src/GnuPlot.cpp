#include "GnuPlot.h"

std::string GnuPlot::config_cmd = "";
std::string GnuPlot::main_cmd = "plot ";
std::vector<std::string> GnuPlot::points;

void GnuPlot::Draw()
{
    main_cmd += "\n";

    FILE *pipe = popen(GNUPLOT_NAME, "w");

    if(pipe != NULL)
    {
        fprintf(pipe, config_cmd.c_str());

        fprintf(pipe, "set term wx\n");

        fprintf(pipe, main_cmd.c_str());
        for(unsigned int i=0; i<points.size(); i++)
        {
            fprintf(pipe, points[i].c_str());
        }

        fprintf(pipe, "pause mouse\n");

        fflush(pipe);
        std::cin.get();
        pclose(pipe);
    }
    else
    {
        std::cout << "Could not open pipe" << std::endl;
    }
}

void GnuPlot::AddPoint(double x, double y, std::string group)
{
    main_cmd += "'-' w p ls " + group + ",";

    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%f %f", x, y);
    points.push_back(buffer);
    points.push_back("\ne\n");
}

void GnuPlot::AddLine(double x1, double y1, double x2, double y2, std::string group)
{
    main_cmd += "'-'with lines ls " + group + ",";

    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%f %f\n", x1, y1);
    points.push_back(buffer);
    snprintf(buffer, sizeof(buffer), "%f %f\n", x2, y2);
    points.push_back(buffer);
    points.push_back("e\n");
}

void GnuPlot::Clear()
{
    main_cmd = "plot ";
    config_cmd = "";
    points.clear();
}

void GnuPlot::AddCommand_main_cmd(std::string cmd)
{
    main_cmd += cmd;
}

void GnuPlot::AddCommand_point_cmd(std::string cmd)
{
    points.push_back(cmd);
}

void GnuPlot::SetTitle(std::string title)
{
    config_cmd += "set title '" + title + "'\n";
    config_cmd += "show title\n";
}

void GnuPlot::SetSize(Przedzial przedzial)
{
    SetSize(przedzial.begin-1,przedzial.end+1, -(przedzial.begin+przedzial.end+2), (przedzial.begin+przedzial.end+2));
}

void GnuPlot::SetSize(double range_x_begin, double range_x_end, double range_y_begin, double range_y_end)
{
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "set xrange [%f : %f]\n", range_x_begin, range_x_end);
    config_cmd += buffer;
    snprintf(buffer, sizeof(buffer), "set yrange [%f : %f]\n", range_y_begin, range_y_end);
    config_cmd += buffer;
}

void GnuPlot::EnableGrid(bool x_grid, bool y_grid)
{
    if(x_grid)
        config_cmd += "set grid xtics mytics\n";
    if(y_grid)
        config_cmd += "set grid ytics mytics\n";
}

void GnuPlot::DisableGrid()
{
    config_cmd += "unset grid\n";
}

void GnuPlot::EnableAxis(bool x_axis, bool y_axis)
{
    if(x_axis)
        config_cmd += "set xzeroaxis\n";
    if(y_axis)
        config_cmd += "set yzeroaxis\n";
}

void GnuPlot::DisableAxis()
{
    config_cmd += "unset xzeroaxis\n";
    config_cmd += "unset yzeroaxis\n";
}

void GnuPlot::SetLegend(std::string option)
{
    if(option == "disable")
        config_cmd += "unset key\n";
    else
        config_cmd += "set key " + option + "\n";
}
