#include <GL/glut.h>

struct Circle {
    int xc, yc, r;
    float color[3];
};

Circle rings[5] = {
    {-120, 50, 50, {0.0, 0.0, 1.0}},  
    {0, 50, 50, {0.0, 0.0, 0.0}},      
    {120, 50, 50, {1.0, 0.0, 0.0}},   
    {-60, 0, 50, {1.0, 1.0, 0.0}},     
    {60, 0, 50, {0.0, 1.0, 0.0}}       
};

void plotPoints(int x, int y, int xc, int yc) {
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
    glEnd();
}

void drawCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int p = 1 - r;
    while (x <= y) {
        plotPoints(x, y, xc, yc);
        x++;
        if (p < 0)
            p = p + 2*x + 1;
        else {
            y--;
            p = p + 2*x - 2*y + 1;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    for(int i = 0; i < 5; i++) {
        glColor3f(rings[i].color[0], rings[i].color[1], rings[i].color[2]);
        drawCircle(rings[i].xc, rings[i].yc, rings[i].r);
    }

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0,1.0); 
    glPointSize(5.0);                 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -100, 150); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 400);
    glutCreateWindow("Olympic Logo - OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

