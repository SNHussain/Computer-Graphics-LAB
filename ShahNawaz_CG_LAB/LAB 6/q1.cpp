#include <GL/glut.h>
#include <cmath>

// Rotation angle
float angle = 30.0;

// Draw ladder (line)
void drawLadder() {
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0); // Bottom
        glVertex2f(0.0, 5.0); // Top
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // Step 1: Translate to (3,2)
    glTranslatef(3.0f, 2.0f, 0.0f);

    // Step 2: Rotate 30° about origin (bottom of ladder)
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    // Draw ladder
    glColor3f(1.0, 1.0, 1.0);
    drawLadder();

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set coordinate system
    gluOrtho2D(-10, 10, -10, 10);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Ladder Transformation");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
