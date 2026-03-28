#include <GL/glut.h>
#include <cmath>
#include<iostream>

int numSides;       
float radius = 100.0;  
int windowWidth = 1000, windowHeight = 1000;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.56, 0.78, 0.97); 

 
    float cx = windowWidth / 2.0;
    float cy = windowHeight / 2.0;


    glBegin(GL_LINE_LOOP); 
    for (int i = 0; i < numSides; i++)
    {
        float angle = 2.0 * M_PI * i / numSides; 
        float x = cx + radius * cos(angle);      
        float y = cy + radius * sin(angle);    
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    std::cout << "Enter the number of sides for the polygon: ";
    std::cin >> numSides;

    if(numSides < 3) {
        std::cout << "A polygon must have at least 3 sides!\n";
        return 0;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Regular Polygon");

    glClearColor(0, 0, 0,1);         
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight); 

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

