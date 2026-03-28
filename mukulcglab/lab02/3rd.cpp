#include <GL/glut.h>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

void ddaLine(int x0, int y0, int x1, int y1, const char* style)
{
    int dx = x1 - x0;
    int dy = y1 - y0;

    int steps = max(abs(dx), abs(dy));

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x0;
    float y = y0;

    int pixelCount = 0;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        bool plot = false;

        if (strcmp(style, "solid") == 0)
        {
            plot = true;
        }
        else if (strcmp(style, "dotted") == 0)
        {
            if (pixelCount % 5 == 0) plot = true;
        }
        else if (strcmp(style, "dashed-dotted") == 0)
        {
            int m = pixelCount % 12;
            if (m < 6 || m == 8) plot = true; 
        }

        if (plot)
        {
            glVertex2i(round(x), round(y));
        }

        x += xInc;
        y += yInc;
        pixelCount++;
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    ddaLine(50, 400, 450, 400, "solid");         
    ddaLine(50, 300, 450, 300, "dotted");       
    ddaLine(50, 200, 450, 200, "dashed-dotted");  

    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 1);
    glPointSize(1.75);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Styles");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

