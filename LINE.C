#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x1, y1, x3, y3);
}

void Transform(int x, int y, int tx, int ty)
{
    int m1[3][3] = {1,0,tx,0,1,ty,0,0,1}, m2[3][3] = {x,y,1,0,0,0,0,0,0};
}

void matMul(int a[3][3], int b[3][3], int mul[3][3])
{
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (k = 0; k < 3; k++)
            {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}


void display(int arr[3][3])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d    ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m1[3][3] = {1, 1, 1, 2, 2, 2, 3, 3, 3}, m2[3][3] = {1, 1, 1, 2, 2, 2, 3, 3, 3}, i, j, res[3][3];
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:/TurboC3/BGI");

    // drawTriangle(10, 10, 30, 10, 20, 20);
    matMul(m1, m2, res);

    display(res);

    getch();
    closegraph();
    return 0;
}
