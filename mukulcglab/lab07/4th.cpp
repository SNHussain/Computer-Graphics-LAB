#include <GL/glut.h>
#include <iostream>
using namespace std;

float xmin = 100, ymin = 100, xmax = 400, ymax = 400;

const int INSIDE = 0; 
const int LEFT   = 1; 
const int RIGHT  = 2; 
const int BOTTOM = 4; 
const int TOP    = 8; 

float x0 = 50, y_0 = 50, x1 = 450, y_1 = 450;

int computeCode(float x, float y)
{
    int code = INSIDE;

    if(x < xmin) code |= LEFT;
    else if(x > xmax) code |= RIGHT;
    if(y < ymin) code |= BOTTOM;
    else if(y > ymax) code |= TOP;

    return code;
}

void cohenSutherlandClip(float x0, float y_0, float x1, float y_1)
{
    int code0 = computeCode(x0, y_0);
    int code1 = computeCode(x1, y_1);
    bool accept = false;

    while(true)
    {
        if(code0 == 0 && code1 == 0)
        {
            accept = true;
            break;
        }
        else if(code0 & code1) break;
   	else
        {
            float x, y;
            int code_out = code0 ? code0 : code1;

            if(code_out & TOP)
            {
                x = x0 + (x1 - x0) * (ymax - y_0) / (y_1 - y_0);
                y = ymax;
            }
            else if(code_out & BOTTOM)
            {
                x = x0 + (x1 - x0) * (ymin - y_0) / (y_1 - y_0);
                y = ymin;
            }
            else if(code_out & RIGHT)
            {
                y = y_0 + (y_1 - y_0) * (xmax - x0) / (x1 - x0);
                x = xmax;
            }
            else if(code_out & LEFT)
            {
                y = y_0 + (y_1 - y_0) * (xmin - x0) / (x1 - x0);
                x = xmin;
            }

            if(code_out == code0)
            {
                x0 = x; y_0 = y;
                code0 = computeCode(x0, y_0);
            }
            else
            {
                x1 = x; y_1 = y;
                code1 = computeCode(x1, y_1);
            }
        }
    }

    if(accept)
    {
        glColor3f(1,0,0); 
        glBegin(GL_LINES);
            glVertex2f(x0, y_0);
            glVertex2f(x1, y_1);
        glEnd();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(xmin, ymin);
        glVertex2f(xmax, ymin);
        glVertex2f(xmax, ymax);
        glVertex2f(xmin, ymax);
    glEnd();

 
    glColor3f(0,0,1);
    glBegin(GL_LINES);
        glVertex2f(x0, y_0);
        glVertex2f(x1, y_1);
    glEnd();


    cohenSutherlandClip(x0, y_0, x1, y_1);

    glFlush();
}


void init()
{
    glClearColor(0,0,0,1);
    gluOrtho2D(0,500,0,500);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Cohen–Sutherland Line Clipping");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
