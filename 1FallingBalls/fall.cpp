#include <graphics.h>
#include <conio.h>
#include <stdio.h>
int main(int argc, char const* argv[])
{
    initgraph(600, 600, NULL);
    fillcircle(300, 300, 100);
    _getch();
    closegraph();
    return 0;
}