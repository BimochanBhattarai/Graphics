#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
using namespace std;

class Point
{
    float x;
    float y;

    void matMul(float a[3][3], float b[3][3], float mul[3][3])
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

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
    friend void drawTriangle(Point P1, Point P2, Point P3)
    {
        line(P1.x, P1.y, P2.x, P2.y);
        line(P2.x, P2.y, P3.x, P3.y);
        line(P1.x, P1.y, P3.x, P3.y);
    }
    friend Point transpose(Point P, float x, float y)
    {
        float m1[3][3] = {1, 0, x, 0, 1, y, 0, 0, 1}, m2[3][3] = {P.x, 0, 0, P.y, 0, 0, 1, 0, 0}, res[3][3];
        P.matMul(m1, m2, res);
        return Point(int(res[0][0]),int(res[1][0]));
    }

    friend Point rotate(Point P, float angle)
    {
        float angleRad = angle * (M_PI / 180.0);
        float cos_angle = cos(angleRad), sin_angle = sin(angleRad);
        float m1[3][3] = {cos_angle, -sin_angle, 0, sin_angle, cos_angle, 0, 0, 0, 1}, m2[3][3] = {P.x, 0, 0, P.y, 0, 0, 1, 0, 0}, res[3][3];
        P.matMul(m1, m2, res);

        return Point(int(res[0][0]),int(res[1][0]));
    }

    friend Point scaling(Point P, float x, float y)
    {
        float m1[3][3] = {x, 0, 0, 0, y, 0, 0, 0, 1}, m2[3][3] = {P.x, 0, 0, P.y, 0, 0, 1, 0, 0}, res[3][3];
        P.matMul(m1, m2, res);
        return Point(int(res[0][0]),int(res[1][0]));
    }
};

Point transpose(Point P, float x, float y);
void drawTriangle(Point P1, Point P2, Point P3);
Point rotate(Point P, float angle);
Point scaling(Point P, float x, float y);



int main()
{
    Point P, P1(100,10), P2(250, 10), P3(150,250);
    Point Pt1, Pt2, Pt3;
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, "C:/TurboC3/BGI");
    drawTriangle(P1,P2,P3);

    float t = 50;

    Pt1 = transpose(P1,t,t);
    Pt2 = transpose(P2,t,t);
    Pt3 = transpose(P3,t,t);
     drawTriangle(Pt1,Pt2,Pt3);

    float s = 2;

    P1 = scaling(Pt1, s, s);
    P2 = scaling(Pt2, s, s);
    P3 = scaling(Pt3, s, s);
     drawTriangle(P1,P2,P3);

    float a = 30;

    Pt1 = rotate(P1, a);
    Pt2 = rotate(P2, a);
    Pt3 = rotate(P3, a);
    drawTriangle(Pt1,Pt2,Pt3);
 
    getch();
    closegraph();
    return 0;
}