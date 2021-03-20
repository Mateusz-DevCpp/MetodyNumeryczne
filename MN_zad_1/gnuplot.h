#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define GNUPLOT_NAME "gnuplot"

int draw()
{
    FILE *pipe = popen(GNUPLOT_NAME, "w");

    if(pipe != NULL)
    {
        /*
        fprintf(pipe, "set term wx\n");         // set the terminal
        fprintf(pipe, "plot '-' with lines\n"); // plot type
        for(int i = 0; i < 10; i++)             // loop over the data [0,...,9]
            fprintf(pipe, "%d\n", i);           // data terminated with \n
        fprintf(pipe, "%s\n", "e");             // termination character
        */

        //fprintf(pipe, "plot sin(x), x");
        fprintf(pipe, "plot '-' w p ls 1, '-' w p ls 2, '-' w p ls 3");
        fprintf(pipe, "%s", "\n");             // termination character
        fprintf(pipe, "1 1");
        fprintf(pipe, "%se\n", "\n");             // termination character
        fprintf(pipe, "1.5 1.5");
        fprintf(pipe, "%se\n", "\n");             // termination character
        fprintf(pipe, "2 2");
        fprintf(pipe, "%se\n", "\n");             // termination character

        fflush(pipe);                           // flush the pipe

        std::cin.get();
        pclose(pipe);
    }
    else
    {
        std::cout << "Could not open pipe" << std::endl;
    }
return 0;
}
