#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;
int x0, y0p, x1, y1p;

void bresenhamLine()
{
    int dx = abs(x1 - x0);
    int dy = abs(y1p - y0p);

    int sx = (x1 >= x0) ? 1 : -1;
    int sy = (y1p >= y0p) ? 1 : -1;

    int x = x0, y = y0p;

    glBegin(GL_POINTS);

    if(dx >= dy) 
    {
        int p = 2*dy - dx;
        for(int i=0; i <= dx; i++)
        {
            glVertex2i(x, y);
            x += sx;
            if(p >= 0)
            {
                y += sy;
                p += 2*(dy - dx);
            }
            else
                p += 2*dy;
        }
    }
    else 
    {
        int p = 2*dx - dy;
        for(int i=0; i <= dy; i++)
        {
            glVertex2i(x, y);
            y += sy;
            if(p >= 0)
            {
                x += sx;
                p += 2*(dx - dy);
            }
            else
                p += 2*dx;
        }
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); 
    bresenhamLine();
    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glPointSize(3.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500); 
}

int main(int argc, char** argv)
{
    cout << "Enter starting point (x0 y0): ";
    cin >> x0 >> y0p;

    cout << "Enter ending point (x1 y1): ";
    cin >> x1 >> y1p;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

