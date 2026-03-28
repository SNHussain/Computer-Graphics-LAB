#include <GL/glut.h>
#include <math.h>

float x1 = 0, y_1 = 0;
float x2 = 0, y_2 = 5;

float rx2, ry2;
float tx1, ty1, tx2, ty2;

void compute() {
    float angle = 30 * M_PI / 180.0;

    rx2 = x2 * cos(angle) - y_2 * sin(angle);
    ry2 = x2 * sin(angle) + y_2 * cos(angle);


    tx1 = x1 + 3;
    ty1 = y_1 + 2;

    tx2 = rx2 + 3;
    ty2 = ry2 + 2;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0x00FF);

    glBegin(GL_LINES);
        glVertex2f(x1, y_1);
        glVertex2f(x2, y_2);
    glEnd();

    glDisable(GL_LINE_STIPPLE);

    glColor3f(1,0,0);
    glBegin(GL_LINES);
        glVertex2f(x1, y_1);
        glVertex2f(rx2, ry2);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_LINES);
        glVertex2f(tx1, ty1);
        glVertex2f(tx2, ty2);
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
    glutCreateWindow("Ladder Transformation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
}
