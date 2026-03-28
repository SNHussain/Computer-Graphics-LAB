#include <GL/glut.h>
#include <iostream>
#include <vector>

using namespace std;

float boundaryColor[3] = {0.0, 0.0, 0.0}; 
float fillColor[3] = {1.0, 0.0, 0.0};    

void boundaryFill8(int x, int y, float* fColor, float* bColor) {
    float currentColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, currentColor);

    if ((currentColor[0] != bColor[0] || currentColor[1] != bColor[1] || currentColor[2] != bColor[2]) &&
        (currentColor[0] != fColor[0] || currentColor[1] != fColor[1] || currentColor[2] != fColor[2])) {
        
        glColor3fv(fColor);
        glBegin(GL_POINTS);
            glVertex2i(x, y);
        glEnd();
        glFlush(); 
     
        boundaryFill8(x + 1, y, fColor, bColor);
        boundaryFill8(x - 1, y, fColor, bColor);
        boundaryFill8(x, y + 1, fColor, bColor);
        boundaryFill8(x, y - 1, fColor, bColor);
        boundaryFill8(x + 1, y + 1, fColor, bColor);
        boundaryFill8(x - 1, y + 1, fColor, bColor);
        boundaryFill8(x + 1, y - 1, fColor, bColor);
        boundaryFill8(x - 1, y - 1, fColor, bColor);
    }
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        int xi = x;
        int yi = 600 - y; 
        
        cout << "Filling started at: " << xi << ", " << yi << endl;
        boundaryFill8(xi, yi, fillColor, boundaryColor);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3fv(boundaryColor);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
        glVertex2i(150, 150);
        glVertex2i(450, 200);
        glVertex2i(500, 400);
        glVertex2i(250, 500);
        glVertex2i(100, 350);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 600, 0, 600);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Polygon Boundary Fill (8-Connected)");
    init();
    
    cout << "Polygon draw ho gaya hai. Ab uske andar click karo fill karne ke liye!" << endl;
    
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}
