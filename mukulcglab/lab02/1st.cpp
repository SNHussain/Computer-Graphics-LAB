#include <GL/glut.h>
#include <cmath>
#include <algorithm>
using namespace std;

void ddaLine()
{
    int x0 = 70, y0 = 10;
    int x1 = 10, y1 = 100;

    int dx = x1 - x0;
    int dy = y1 - y0;

    int steps = max(abs(dx), abs(dy));

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x0;
    float y = y0;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2i(round(x), round(y));
        x += xInc;
        y += yInc;
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    ddaLine();
    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glPointSize(2.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Simple DDA Line");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

