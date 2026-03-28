#include <iostream>
#include <GL/glut.h>
using namespace std;

int pntX1, pntY1, r;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x + pntX1, y + pntY1);
    glEnd();
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void midPointCircleAlgo()
{
    int x = 0;
    int y = r;

    // Correct decision parameter
    int decision = 1 - r;

    while (y >= x)
    {
        // Plot all 8 symmetric points
        plot(x, y);
        plot(y, x);
        plot(-x, y);
        plot(-y, x);
        plot(-x, -y);
        plot(-y, -x);
        plot(x, -y);
        plot(y, -x);

        x++;

        if (decision < 0)
        {
            decision += 2 * x + 1;
        }
        else
        {
            y--;
            decision += 2 * (x - y) + 1;
        }
    }
}

void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    midPointCircleAlgo();
    glFlush();
}

int main(int argc, char** argv)
{
    cout << "Enter the coordinates of the center:\n";
    cout << "X-coordinate: ";
    cin >> pntX1;

    cout << "Y-coordinate: ";
    cin >> pntY1;

    cout << "Enter radius: ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Midpoint Circle Algorithm");

    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

    return 0;
}

