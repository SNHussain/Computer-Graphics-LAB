#include <GL/glut.h>
#include <stdio.h>

int rMax = 200;   
int rStep = 20;   

void plotPoints(int x, int y, int xc, int yc)
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

void drawCircle(int xc, int yc, int r)
{
    int x = 0, y = r;
    int p = 1 - r;

    while (x <= y)
    {
        plotPoints(x, y, xc, yc);
        x++;
        if (p < 0)
            p = p + 2*x + 1;
        else
        {
            y--;
            p = p + 2*x - 2*y + 1;
        }
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); 

    int r;
    for(r = rStep; r <= rMax; r += rStep)  
    drawCircle(0, 0, r); 
    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glPointSize(2.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250, 250, -250, 250); 
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Concentric Circles - OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

