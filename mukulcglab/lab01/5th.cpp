#include <GL/glut.h>
int points[4][2] = { {50, 60}, {90, 150}, {100, 140}, {200, 380} };

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);   
    glColor3f(1.0, 0.0, 0.0);       
    glBegin(GL_LINE_STRIP);         
    for (int i = 0; i < 3; i++)
    glVertex2iv(points[i]);
    
    glEnd();
    glFlush();                      
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                          
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   
    glutInitWindowSize(500, 500);                 
    glutInitWindowPosition(100, 100);               
    glutCreateWindow("Line using Points Array");   

    glClearColor(1.0, 1.0, 1.0, 1.0);       


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);

    glutDisplayFunc(display);      
    glutMainLoop();                 

    return 0;
}

