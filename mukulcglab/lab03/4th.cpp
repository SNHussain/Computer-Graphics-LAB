#include <GL/glut.h>
#include <stdio.h>

#define NUM_CENTRES 5  

int centres[NUM_CENTRES][2] = {
    {0, 0},
    {100, 100},
    {-100, 50},
    {-50, -100},
    {150, -50}
};

int radius[NUM_CENTRES] = {50, 30, 70, 40, 60};  

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

    for (int i = 0; i < NUM_CENTRES; i++)
    drawCircle(centres[i][0], centres[i][1], radius[i]);
    

    glFlush();
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);  
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
    glutCreateWindow("Multiple Circles - OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

