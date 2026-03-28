#include <GL/glut.h>
#define MAX_POINTS 100
int points[MAX_POINTS][2];
int pointCount = 0;
int windowHeight = 500;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.56, 0.78, 0.97);

    glPointSize(5.0);   
    glBegin(GL_POINTS);

    for (int i = 0; i < pointCount; i++)
    glVertex2i(points[i][0], points[i][1]);

    glEnd();
    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        if (pointCount < MAX_POINTS)
        {
            points[pointCount][0] = x;
            points[pointCount][1] = windowHeight - y; 
            pointCount++;
        }

        glutPostRedisplay(); 
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Click to Plot Points");

    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);

    glutDisplayFunc(display);
    glutMouseFunc(mouse);   

    glutMainLoop();
    return 0;
}

