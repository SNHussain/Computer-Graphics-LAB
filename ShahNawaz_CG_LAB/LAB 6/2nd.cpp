#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

float x1 = 1, y_1 = 1;
float x2 = 3, y2 = 1;
float x3 = 2, y3 = 3;

float rx1, ry1, rx2, ry2, rx3, ry3;

float angle;

void compute() {
    float rad = angle * M_PI / 180.0;

    rx1 = x1 * cos(rad) - y_1 * sin(rad);
    ry1 = x1 * sin(rad) + y_1 * cos(rad);

    rx2 = x2 * cos(rad) - y2 * sin(rad);
    ry2 = x2 * sin(rad) + y2 * cos(rad);

    rx3 = x3 * cos(rad) - y3 * sin(rad);
    ry3 = x3 * sin(rad) + y3 * cos(rad);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x1, y_1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(rx1, ry1);
        glVertex2f(rx2, ry2);
        glVertex2f(rx3, ry3);
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

    printf("Enter rotation angle: ");
    scanf("%f", &angle);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(600,600);
    glutCreateWindow("Rotation about Origin");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
