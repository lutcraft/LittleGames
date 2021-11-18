#include <graphics.h>
#include <conio.h>
#include <stdio.h>

#define zuli (float)0.9
#define gravity  (float)0.6
#define wid   600
#define hei   600
#define xmove 8
void init(float* x, float* y, float* vx, float* vy,float* radious) {
    *x = wid/2;
    *y = hei - *radious;
    *vx = 0;
    *vy = 0;
    *radious = 20;
}
void physicalCalc(float* x,float* y,float*vx,float* vy, float* radious) {
    *x += *vx;
    *y += *vy;
    *vx *= zuli;
    *vy += gravity;
    if (*y >= wid - *radious)
    {
        *y = wid - *radious;
        *vy *= -0.5;
    }
    if (*x>=wid)
    {
        *x -= wid;
    }
    if (*x <= 0)
    {
        *x += wid;
    }
}

void getaction(float* x, float* y, float* vx, float* vy,float* radious) {
    if (_kbhit()) {
        char input = _getch();
        if (input == ' ') {
            *vy += -16;
        }
        if (input == 'a')
        {
            *x -= xmove;
        }
        if (input == 'd')
        {
            *x += xmove;
        }
    }
}

int main(int argc, char const* argv[])
{

    float x, y, vx, vy, radious;
    
    initgraph(wid, hei, NULL);


    init(&x, &y, &vx, &vy,&radious);
    while (true) {
        getaction(&x, &y, &vx, &vy ,&radious);
        physicalCalc(&x,&y,&vx,&vy, &radious);
        fillcircle(x,y,radious);
        Sleep(50);
        cleardevice();
    }

    closegraph();
    return 0;
}