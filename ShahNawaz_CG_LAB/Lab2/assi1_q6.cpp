#include <GL/glut.h>
#define MAX_POINTS 100
int points[MAX_POINTS][2];
int pointCount = 0;
int windowWidth = 800;
int windowHeight = 800;
void init() {
    glClearColor(0.0, 1.0, 0.0, 1.0);   // Green background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);
}

void myMouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (pointCount < MAX_POINTS) {
            points[pointCount][0] = x;
            points[pointCount][1] = windowHeight - y; // flip Y
            pointCount++;
        }
        glutPostRedisplay();
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);  // Red points
    glPointSize(8.0);

    glBegin(GL_POINTS);
        for (int i = 0; i < pointCount; i++) {
            glVertex2i(points[i][0], points[i][1]);
        }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Mouse Click Point Plot");

    init();
    glutDisplayFunc(display);
    glutMouseFunc(myMouseClick);

    glutMainLoop();
    return 0;
}
