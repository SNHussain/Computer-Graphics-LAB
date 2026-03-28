#include <GL/glut.h>
int star[5][2] = { {250, 400},  {350, 300},  {300, 150},   
    {200, 150}, {150, 300}   };

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_LINES);

    glVertex2i(star[0][0], star[0][1]);
    glVertex2i(star[2][0], star[2][1]);

    glVertex2i(star[2][0], star[2][1]);
    glVertex2i(star[4][0], star[4][1]);

    glVertex2i(star[4][0], star[4][1]);
    glVertex2i(star[1][0], star[1][1]);

    glVertex2i(star[1][0], star[1][1]);
    glVertex2i(star[3][0], star[3][1]);

    glVertex2i(star[3][0], star[3][1]);
    glVertex2i(star[0][0], star[0][1]);

    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Star using Lines");

    glClearColor(1, 1, 1, 1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

