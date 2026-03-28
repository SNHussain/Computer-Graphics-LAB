#include <GL/glut.h>
#include <cmath>

const int WIDTH = 800;
const int HEIGHT = 600;
void drawSun() {
    float cx = 600, cy = 500, r = 50;
    glBegin(GL_LINE_LOOP);  
    for(int i = 0; i < 100; i++) {
        float angle = 2 * 3.1416 * i / 100;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void drawFence() {
    for(int i = 0; i < 800; i += 20){
        glBegin(GL_LINES);
            glVertex2f(i, 50);  
            glVertex2f(i, 90);
        glEnd();
    }
    glBegin(GL_LINES);
        glVertex2f(0, 70);
        glVertex2f(800, 70);
    glEnd();
}

void drawSimpleHouse(float x, float y) {

    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + 100, y);
        glVertex2f(x + 100, y + 80);
        glVertex2f(x, y + 80);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(x - 10, y + 80);
        glVertex2f(x + 110, y + 80);
        glVertex2f(x + 50, y + 120);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(x + 40, y);
        glVertex2f(x + 60, y);
        glVertex2f(x + 60, y + 40);
        glVertex2f(x + 40, y + 40);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex2f(x + 10, y + 45);
        glVertex2f(x + 30, y + 45);
        glVertex2f(x + 30, y + 65);
        glVertex2f(x + 10, y + 65);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawSun();

    drawSimpleHouse(100, 150);
    drawSimpleHouse(300, 150);  
    drawSimpleHouse(500, 150);

    drawFence();

    glFlush();
}

void init() {
    glClearColor(0, 0, 0, 1); 
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Final Wireframe Scene");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

