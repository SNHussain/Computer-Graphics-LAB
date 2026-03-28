#include <GL/glut.h>

float x1 = -2, y1_ = 1;
float x2 = 3, y2 = 5;

float rx1, ry1, rx2, ry2;

float fx1, fy1, fx2, fy2;

void compute() {
   
    rx1 = x1;
    ry1 = -y1_;

    rx2 = x2;
    ry2 = -y2;

    fx1 = -x1;
    fy1 = y1_;

    fx2 = -x2;
    fy2 = y2;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex2f(x1, y1_);
        glVertex2f(x2, y2);
    glEnd();

    glColor3f(1,0,0);
    glBegin(GL_LINES);
        glVertex2f(rx1, ry1);
        glVertex2f(rx2, ry2);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_LINES);
        glVertex2f(fx1, fy1);
        glVertex2f(fx2, fy2);
    glEnd();
     glBegin(GL_POINTS);
        glVertex2f(0, 0);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0,0,0,1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);

    compute();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600,600);
    glutCreateWindow("Reflection of Line");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
