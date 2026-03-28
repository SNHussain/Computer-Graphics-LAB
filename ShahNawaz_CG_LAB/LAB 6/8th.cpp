#include <GL/glut.h>
#include <iostream>

float oldColor[3] = {1.0, 1.0, 1.0}; 
float newColor[3] = {0.0, 0.0, 1.0}; 

void floodFill4(int x, int y, float* oldC, float* newC) {
    float currentColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, currentColor);

   
    if (currentColor[0] == oldC[0] && currentColor[1] == oldC[1] && currentColor[2] == oldC[2]) {
        
        glColor3fv(newC);
        glBegin(GL_POINTS);
            glVertex2i(x, y);
        glEnd();
        glFlush();

        floodFill4(x + 1, y, oldC, newC); 
        floodFill4(x - 1, y, oldC, newC); 
        floodFill4(x, y + 1, oldC, newC);
        floodFill4(x, y - 1, oldC, newC); 
    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int xi = x;
        int yi = 480 - y;
        floodFill4(xi, yi, oldColor, newColor);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(100, 100);
        glVertex2i(300, 100);
        glVertex2i(300, 300);
        glVertex2i(100, 300);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Flood Fill Algorithm");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse); 
    glutMainLoop();
    return 0;
}
