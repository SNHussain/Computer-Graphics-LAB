#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

float x1 = 1, y1_ = 1;
float x2 = 3, y2_ = 1;
float x3 = 2, y3_ = 3;

float rx1, ry1, rx2, ry2, rx3, ry3;

float xf, yf;

float angle;

void computeRotation() {
    float rad = angle * M_PI / 180.0;

    float tx = x1 - xf;
    float ty = y1_- yf;
    rx1 = tx * cos(rad) - ty * sin(rad) + xf;
    ry1 = tx * sin(rad) + ty * cos(rad) + yf;

    tx = x2 - xf;
    ty = y2_ - yf;
    rx2 = tx * cos(rad) - ty * sin(rad) + xf;
    ry2 = tx * sin(rad) + ty * cos(rad) + yf;

    tx = x3 - xf;
    ty = y3_ - yf;
    rx3 = tx * cos(rad) - ty * sin(rad) + xf;
    ry3 = tx * sin(rad) + ty * cos(rad) + yf;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x1, y1_);
        glVertex2f(x2, y2_);
        glVertex2f(x3, y3_);
    glEnd();

    glColor3f(0,1,0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(rx1, ry1);
        glVertex2f(rx2, ry2);
        glVertex2f(rx3, ry3);
    glEnd();

    glPointSize(6);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
        glVertex2f(xf, yf);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);

    computeRotation();
}

int main(int argc, char** argv) {
    printf("Enter rotation angle (degrees): ");
    scanf("%f", &angle);

    printf("Enter fixed point coordinates (xf yf): ");
    scanf("%f %f", &xf, &yf);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Triangle Rotation about Fixed Point");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
}
