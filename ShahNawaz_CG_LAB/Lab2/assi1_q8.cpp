#include <GL/glut.h>
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); 

    /* ---- House Body ---- */
    glBegin(GL_LINE_LOOP);
        glVertex2i(150, 150);
        glVertex2i(350, 150);
        glVertex2i(350, 300);
        glVertex2i(150, 300);
    glEnd();

    /* ---- Roof ---- */
    glBegin(GL_LINES);
        glVertex2i(150, 300);
        glVertex2i(250, 380);

        glVertex2i(250, 380);
        glVertex2i(350, 300);
    glEnd();

    /* ---- Door ---- */
    glBegin(GL_LINE_LOOP);
        glVertex2i(230, 150);
        glVertex2i(270, 150);
        glVertex2i(270, 230);
        glVertex2i(230, 230);
    glEnd();

    /* ---- Left Window ---- */
    glBegin(GL_LINE_LOOP);
        glVertex2i(170, 220);
        glVertex2i(210, 220);
        glVertex2i(210, 260);
        glVertex2i(170, 260);
    glEnd();

    /* ---- Right Window ---- */
    glBegin(GL_LINE_LOOP);
        glVertex2i(290, 220);
        glVertex2i(330, 220);
        glVertex2i(330, 260);
        glVertex2i(290, 260);
    glEnd();

    /* ---- Window Cross Lines ---- */
    glBegin(GL_LINES);
        // Left window cross
        glVertex2i(190, 220);
        glVertex2i(190, 260);
        glVertex2i(170, 240);
        glVertex2i(210, 240);

        // Right window cross
        glVertex2i(310, 220);
        glVertex2i(310, 260);
        glVertex2i(290, 240);
        glVertex2i(330, 240);
    glEnd();

    /* ---- Decorative Points ---- */
    glPointSize(5.0);
    glBegin(GL_POINTS);
        glVertex2i(250, 380); // Roof top
        glVertex2i(250, 230); // Door top
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("House using Points and Lines");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}


