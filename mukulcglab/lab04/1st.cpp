#include <GL/glut.h>
#include <cmath>

int xc = 0, yc = 0;
int a = 200;   
int b = 200;  

void plotPoint(int x, int y) {
    glBegin(GL_POINTS);
        glVertex2i(xc + x, yc + y);
        glVertex2i(xc - x, yc + y);
        glVertex2i(xc + x, yc - y);
        glVertex2i(xc - x, yc - y);
    glEnd();
}

void midpointEllipse() {

    float dx, dy, d1, d2, x, y;
    x = 0;
    y = b;

    d1 = (b*b) - (a*a*b) + (0.25*a*a);
    dx = 2 * b * b * x;
    dy = 2 * a * a * y;

    while (dx < dy) {
        plotPoint(x, y);

        if (d1 < 0) {
            x++;
            dx = dx + (2 * b * b);
            d1 = d1 + dx + (b * b);
        }
        else {
            x++; 
            y--;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            d1 = d1 + dx - dy + (b * b);
        }
    }

    d2 = ((b*b) * ((x + 0.5)*(x + 0.5))) +((a*a) * ((y - 1)*(y - 1))) - (a*a*b*b);

    while (y >= 0) {
        plotPoint(x, y);

        if (d2 > 0) {
            y--;
            dy = dy - (2 * a * a);
            d2 = d2 + (a * a) - dy;
        }
        else {
            y--;
            x++;
            dx = dx + (2 * b * b);
            dy = dy - (2 * a * a);
            d2 = d2 + dx - dy + (a * a);
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); 
    midpointEllipse();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-400, 400, -300, 300);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Midpoint Ellipse Algorithm - OpenGL");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

