#include <GL/glut.h>
#include <math.h>

float angle = 45;
float v[8][3] = {
    {-1,-1,-1}, {1,-1,-1}, {1,1,-1}, {-1,1,-1},
    {-1,-1, 1}, {1,-1, 1}, {1,1, 1}, {-1,1, 1}
};

float rv[8][3];
int e[12][2] = {
    {0,1},{1,2},{2,3},{3,0},
    {4,5},{5,6},{6,7},{7,4},
    {0,4},{1,5},{2,6},{3,7}
};

void rotateX()
{
    float rad = angle * 3.14 / 180;

    for(int i=0;i<8;i++)
    {
        rv[i][0] = v[i][0];
        rv[i][1] = v[i][1]*cos(rad) - v[i][2]*sin(rad);
        rv[i][2] = v[i][1]*sin(rad) + v[i][2]*cos(rad);
    }
}

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

    glColor3f(1,0,0);
    drawCube(rv);
    glutSwapBuffers();
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0,0,0,1);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60,1,1,100);

    glMatrixMode(GL_MODELVIEW);

    rotateX(); 
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Manual Rotation about X-axis");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
