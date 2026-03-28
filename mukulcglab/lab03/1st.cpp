//Implement the midpoint circle draw algo print the pixel coordinates of the circles centre of origin.
#include <GL/glut.h>
#include <stdio.h>

int xc = 0, yc = 0, r = 100;

void plotPoints(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);

    glEnd();
}

void midpointCircle()
{
    int x = 0;
    int y = r;
    int p = 1 - r;

    while (x <= y)
    {
        plotPoints(x, y);
        x++;

        if (p < 0)
        {
            p = p + 2 * x + 1;
        }
        else
        {
            y--;
            p = p + 2 * x - 2 * y + 1;
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);   
    midpointCircle();
    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);  
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Algorithm - OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

