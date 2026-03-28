#include <GL/glut.h>

float tx = 2.0, ty = 2.0, tz = -2.0;
float v[8][3] = {
    {-1,-1,-1}, {1,-1,-1}, {1,1,-1}, {-1,1,-1},
    {-1,-1, 1}, {1,-1, 1}, {1,1, 1}, {-1,1, 1}
};

int e[12][2] = {
    {0,1},{1,2},{2,3},{3,0},
    {4,5},{5,6},{6,7},{7,4},
    {0,4},{1,5},{2,6},{3,7}
};

void drawCube(float v[8][3])
{
    glBegin(GL_LINES);
    for(int i=0;i<12;i++)
    {
        glVertex3fv(v[e[i][0]]);
        glVertex3fv(v[e[i][1]]);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(5,5,5, 0,0,0, 0,1,0);
    glColor3f(1,1,1);
    drawCube(v);

    glPushMatrix();
    glTranslatef(tx, ty, tz);
    glColor3f(1,0,0);
    drawCube(v);
    glPopMatrix();

    glutSwapBuffers();
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0,0,0,1);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60,1,1,100);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("3D Translation of Cube");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
