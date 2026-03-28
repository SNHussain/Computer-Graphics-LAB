#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

/* Plot a point */
void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

/* ---------------- DDA Line Algorithm ---------------- */
void DDA(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        plot(round(x), round(y));
        x += xInc;
        y += yInc;
    }
}

/* ---------------- Bresenham Line Algorithm ---------------- */
void Bresenham(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (true)
    {
        plot(x1, y1);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

/* ---------------- Dotted Line ---------------- */
void dottedLine(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        if (i % 4 == 0)   // dot pattern
            plot(round(x), round(y));

        x += xInc;
        y += yInc;
    }
}

/* ---------------- Dotted-Dashed Line ---------------- */
void dottedDashedLine(int x1, int y1, int x2, int y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        if (i % 10 < 5 || i % 10 == 7) // dash + dot pattern
            plot(round(x), round(y));

        x += xInc;
        y += yInc;
    }
}

/* ---------------- Draw HELLO using Lines ---------------- */
void drawHELLO()
{
    // H
    DDA(50, 200, 50, 300);
    DDA(80, 200, 80, 300);
    DDA(50, 250, 80, 250);

    // E
    DDA(100, 200, 100, 300);
    DDA(100, 300, 140, 300);
    DDA(100, 250, 130, 250);
    DDA(100, 200, 140, 200);

    // L
    DDA(160, 300, 160, 200);
    DDA(160, 200, 200, 200);

    // L
    DDA(220, 300, 220, 200);
    DDA(220, 200, 260, 200);

    // O
    DDA(280, 200, 280, 300);
    DDA(280, 300, 320, 300);
    DDA(320, 300, 320, 200);
    DDA(320, 200, 280, 200);
}

/* ---------------- Display Function ---------------- */
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // DDA Line
    glColor3f(1, 0, 0);
    DDA(50, 50, 200, 100);

    // Bresenham Line
    glColor3f(0, 1, 0);
    Bresenham(50, 80, 200, 150);

    // Dotted Line
    glColor3f(0, 0, 1);
    dottedLine(50, 120, 200, 200);

    // Dotted-Dashed Line
    glColor3f(1, 0, 1);
    dottedDashedLine(50, 160, 200, 260);

    // HELLO
    glColor3f(1, 1, 1);
    drawHELLO();

    glFlush();
}

/* ---------------- Initialization ---------------- */
void init()
{
    glClearColor(0, 0, 0, 1);
    glColor3f(1, 1, 1);
    glPointSize(2);
    gluOrtho2D(0, 500, 0, 500);
}

/* ---------------- Main ---------------- */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Line Drawing Algorithms");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

