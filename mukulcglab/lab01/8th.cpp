#include <GL/glut.h>
#include <cmath>

int windowWidth = 600, windowHeight = 600;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.8, 0.5, 0.2); 
    glBegin(GL_LINE_LOOP);
        glVertex2i(200, 200);
        glVertex2i(400, 200);
        glVertex2i(400, 400);
        glVertex2i(200, 400);
    glEnd();

   
    glColor3f(1.0, 0.0, 0.0); 
    glBegin(GL_LINE_LOOP);
        glVertex2i(200, 400);
        glVertex2i(400, 400);
        glVertex2i(300, 500);
    glEnd();

    glColor3f(0.5, 0.35, 0.05);
    glBegin(GL_LINE_LOOP);
        glVertex2i(270, 200);
        glVertex2i(330, 200);
        glVertex2i(330, 300);
        glVertex2i(270, 300);
    glEnd();

    glColor3f(0.0, 0.8, 1.0); 
    glBegin(GL_LINE_LOOP);
        glVertex2i(220, 330);
        glVertex2i(260, 330);
        glVertex2i(260, 370);
        glVertex2i(220, 370);
    glEnd();
  
    glBegin(GL_LINE_LOOP);
        glVertex2i(340, 330);
        glVertex2i(380, 330);
        glVertex2i(380, 370);
        glVertex2i(340, 370);
    glEnd();



    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Simple House Scene");

    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

