#include <graphics.h>
#include <conio.h>
#include <stdio.h>
int main(int argc, char const* argv[])
{
    initgraph(600, 600, NULL);
    float g = 0.5;
    float vy = 0;
    float vx = 20;
    float y = 0;
    float x = 300;
    float zuli = 0.9;
    while (true)
    {
        vy += g;
        y += vy;
        x += vx;
        fillcircle(x, y, 20);
        Sleep(10);
        cleardevice();
        if (y >= 580)
        {
            vy *= -zuli;
        }
        if (y <= 20)
        {
            vy *= -zuli;
        }
        if (x >= 580) 
        {
            vx *= -zuli;
        }
        if (x <= 20)
        {
            vx *= -zuli;
        }
        if (y > 580)
        {
            y = 580;
        }
        if (y < 20)
        {
            y = 20 + (20 - y);
        }
        if (x > 580)
        {
            x = 580 - (x - 580);
        }
        if (x < 20)
        {
            x = 20 + (x - 20);
        }
    }


    closegraph();
    return 0;
}