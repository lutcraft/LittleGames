#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define zuli (float)0.9
#define gravity  (float)0.6
#define wid   600
#define hei   600
#define xmove 8

bool gameRuning = 1;

typedef struct t_range
{
    int up;
    int down;
}range;

float getrandrec(range aRange) {
    return (float)abs((rand() % aRange.up)+aRange.down);
}

void init(float* x_ball, float* y_ball, float* vx, float* vy, float* radious, float* x_rec, float* y_rec, float* v_rec, float* rec_hei, float* rec_weith) {
    *radious = 20;
    *x_ball = wid / 2;
    *y_ball = hei - *radious;
    *vx = 0;
    *vy = 0;


    *x_rec = wid;
    *v_rec = 10;
    range rec_range_hei;
    rec_range_hei.down = 10;
    rec_range_hei.up = 50;
    range rec_range_with;
    rec_range_with.down = 10;
    rec_range_with.up = 20;
    *rec_hei = getrandrec(rec_range_hei);
    *y_rec = hei - *rec_hei;
    *rec_weith = getrandrec(rec_range_with);
}

void updateBall(float* x_ball, float* y_ball, float* vx, float* vy, float* radious) {
    *x_ball += *vx;
    *y_ball += *vy;
    *vx *= zuli;
    *vy += gravity;
    if (*y_ball >= wid - *radious)
    {
        *y_ball = wid - *radious;
        *vy *= -0.5;
    }
    if (*x_ball >= wid)
    {
        *x_ball -= wid;
    }
    if (*x_ball <= 0)
    {
        *x_ball += wid;
    }
}
void updateRec(float* x_rec, float* y_rec, float* v_rec, float* rec_hei,  float* rec_weith){
    *x_rec -= *v_rec;
    if (*x_rec<=0)
    {
        *x_rec = wid;
        *v_rec = 10;
        range rec_range_hei;
        rec_range_hei.down = 10;
        rec_range_hei.up = 400;
        range rec_range_with;
        rec_range_with.down = 10;
        rec_range_with.up = 20;
        *rec_hei = getrandrec(rec_range_hei);
        *y_rec = hei - *rec_hei;
        *rec_weith = getrandrec(rec_range_with);
    }
}
    
bool checkCrash(float* x_ball, float* y_ball, float* radious, float* x_rec, float* y_rec, float* rec_hei, float* rec_weith) {
    if ((*x_ball+*radious >= *x_rec)&&(*x_rec+*rec_weith>= *x_ball-*radious)&&(*y_rec<=*y_ball+*radious))
    {
        return true;
    }
    return false;
}


void physicalCalc(float* x_ball, float* y_ball, float* vx, float* vy, float* radious,float* x_rec, float* y_rec, float* v_rec, float* rec_hei, float* rec_weith) {
    updateBall(x_ball, y_ball, vx, vy, radious);
    updateRec(x_rec, y_rec, v_rec,rec_hei,rec_weith);
    if (checkCrash(x_ball, y_ball, radious, x_rec, y_rec, rec_hei, rec_weith)) {
        gameRuning = false;
    }
}

void getaction(float* x_ball, float* y_ball, float* vx, float* vy, float* radious) {
    if (_kbhit()) {
        char input = _getch();
        if (input == ' ') {
            *vy += -16;
        }
        if (input == 'a')
        {
            *x_ball -= xmove;
        }
        if (input == 'd')
        {
            *x_ball += xmove;
        }
    }
}

void updateGrafic(float* x_ball, float* y_ball, float* radious, float* x_rec, float* y_rec, float* rec_hei, float* rec_weith) {
    cleardevice();
    fillcircle(*x_ball, *y_ball, *radious);
    fillrectangle(*x_rec, *y_rec, *x_rec + *rec_weith, hei);
    Sleep(50);

}

int main(int argc, char const* argv[])
{

    float x_ball, y_ball, vx, vy, radious;
    float x_rec, y_rec, v_rec,rec_hei,rec_weith;
    initgraph(wid, hei, NULL);


    init(&x_ball, &y_ball, &vx, &vy, &radious, &x_rec, &y_rec, &v_rec, &rec_hei, &rec_weith);
    while (gameRuning) {
        getaction(&x_ball, &y_ball, &vx, &vy, &radious);
        physicalCalc(&x_ball, &y_ball, &vx, &vy, &radious, &x_rec, &y_rec, &v_rec, &rec_hei, &rec_weith);
        updateGrafic(&x_ball, &y_ball, &radious ,&x_rec, &y_rec, &rec_hei, &rec_weith);
    }

    closegraph();
    printf("you lose!");
    return 0;
}