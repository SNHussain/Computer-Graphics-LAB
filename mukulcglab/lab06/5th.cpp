#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.23f, 0.89f, 0.64f); 
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.0f, 0.0f);  
        glVertex2f(6.0f, 0.0f); 
        glVertex2f(6.0f, 9.0f);  
        glVertex2f(0.0f, 9.0f);   
    glEnd();


    glColor3f(0.76f, 0.40f, 0.33f); 
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.0f, 0.0f); 
        glVertex2f(2.0f, 0.0f);  
        glVertex2f(1.0f, 1.0f); 
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f); 
    glBegin(GL_LINE_LOOP);
        glVertex2f(5.0f, 0.0f);  
        glVertex2f(11.0f, 0.0f); 
        glVertex2f(11.0f, 9.0f);  
        glVertex2f(5.0f, 9.0f);   
    glEnd();


    glColor3f(1.0f, 0.0f, 0.0f); 
    glBegin(GL_LINE_LOOP);
        glVertex2f(5.0f, 9.0f); 
        glVertex2f(11.0f, 9.0f);  
        glVertex2f(8.0f, 12.0f); 
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 15.0, -1.0, 12.0); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Rectangle and Triangle Transformation");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
