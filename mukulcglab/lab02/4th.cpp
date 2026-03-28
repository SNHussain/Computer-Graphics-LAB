#include <GL/glut.h>
#include <cmath>
#include <algorithm>
using namespace std;

void ddaLine(int x0, int y0, int x1, int y1)
{
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

void drawH(int x, int y, int size)
{
    ddaLine(x, y, x, y + size);           
    ddaLine(x + size, y, x + size, y + size); 
    ddaLine(x, y + size/2, x + size, y + size/2); 
}

void drawE(int x, int y, int size)
{
    ddaLine(x, y, x, y + size);            
    ddaLine(x, y + size, x + size, y + size); 
    ddaLine(x, y + size/2, x + size*0.8, y + size/2);  
    ddaLine(x, y, x + size, y);            
}

void drawL(int x, int y, int size)
{
    ddaLine(x, y, x, y + size);             
    ddaLine(x, y, x + size, y);             
}

void drawO(int x, int y, int size)
{
    ddaLine(x, y, x, y + size);              
    ddaLine(x + size, y, x + size, y + size); 
    ddaLine(x, y + size, x + size, y + size); 
    ddaLine(x, y, x + size, y);               
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);

    int startX = 50, startY = 300, size = 50, gap = 20;

    drawH(startX, startY, size);
    drawE(startX + (size + gap), startY, size);
    drawL(startX + 2*(size + gap), startY, size);
    drawL(startX + 3*(size + gap), startY, size);
    drawO(startX + 4*(size + gap), startY, size);

    glFlush();
}

void init()
{
    glClearColor(0,0,0,1);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("HELLO using DDA");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

