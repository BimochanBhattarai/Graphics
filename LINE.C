#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef struct Points{
    int x;
    int y;
} Point;

void drawTriangle(Point P1, Point P2, Point P3)
{
    line(P1.x, P1.y, P2.x, P2.y);
    line(P1.x, P1.y, P3.x, P3.y);
    line(P2.x, P2.y, P3.x, P3.y);
}

void Transform(Point P, int tx, int ty)
{
    int m1[3][3] = {1,0,tx,0,1,ty,0,0,1}, m2[3][3] = {P.x,0,0,P.y,0,0,1,0,0};
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
