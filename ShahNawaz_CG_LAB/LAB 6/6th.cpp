#include <GL/glut.h>
#include <iostream>

float boundaryColor[3] = {0.0, 0.0, 0.0}; 
float fillColor[3] = {0.0, 1.0, 0.0};     

void boundaryFill8(int x, int y, float* fillC, float* boundC) {
    float interiorColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, interiorColor);

    if ((interiorColor[0] != boundC[0] || interiorColor[1] != boundC[1] || interiorColor[2] != boundC[2]) &&
        (interiorColor[0] != fillC[0] || interiorColor[1] != fillC[1] || interiorColor[2] != fillC[2])) {
 
        glColor3fv(fillC);
        glBegin(GL_POINTS);
            glVertex2i(x, y);
        glEnd();
        glFlush();

     
        boundaryFill8(x + 1, y, fillC, boundC);    
        boundaryFill8(x - 1, y, fillC, boundC);     
        boundaryFill8(x, y + 1, fillC, boundC);    
        boundaryFill8(x, y - 1, fillC, boundC);    
        boundaryFill8(x + 1, y + 1, fillC, boundC); 
        boundaryFill8(x - 1, y + 1, fillC, boundC); 
        boundaryFill8(x + 1, y - 1, fillC, boundC); 
        boundaryFill8(x - 1, y - 1, fillC, boundC); 
    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
  	int xi = x;
        int yi = 600 - y;
        boundaryFill8(xi, yi, fillColor, boundaryColor);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

  
    glColor3fv(boundaryColor);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(150, 150);
        glVertex2i(450, 150);
        glVertex2i(450, 450);
        glVertex2i(150, 450);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 600, 0, 600);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Boundary Fill 8-Connected");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse); 
    glutMainLoop();
    return 0;
}
