#include <GL/glut.h>

float sx = 1.5, sy = 2.0, sz = 1.5;
float v[5][3] = {
    {0, 1, 0}, {-1,-1, 1}, { 1,-1, 1}, { 1,-1,-1},{-1,-1,-1}  }; 

float sv[5][3];

void drawPyramid(float vert[5][3])
{
    glBegin(GL_LINES);

    glVertex3fv(vert[1]); glVertex3fv(vert[2]);
    glVertex3fv(vert[2]); glVertex3fv(vert[3]);
    glVertex3fv(vert[3]); glVertex3fv(vert[4]);
    glVertex3fv(vert[4]); glVertex3fv(vert[1]);

    glVertex3fv(vert[0]); glVertex3fv(vert[1]);
    glVertex3fv(vert[0]); glVertex3fv(vert[2]);
    glVertex3fv(vert[0]); glVertex3fv(vert[3]);
    glVertex3fv(vert[0]); glVertex3fv(vert[4]);

    glEnd();
}

void scalePyramid()
{
    for(int i=0;i<5;i++)
    {
        sv[i][0] = v[i][0] * sx;
        sv[i][1] = v[i][1] * sy;
        sv[i][2] = v[i][2] * sz;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(5,5,5, 0,0,0, 0,1,0);

    glColor3f(1,1,1);
    drawPyramid(v);

    glColor3f(1,0,0);
    drawPyramid(sv);

    glutSwapBuffers();
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0,0,0,1);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60,1,1,100);

    glMatrixMode(GL_MODELVIEW);

    scalePyramid(); 
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Manual Scaling of Pyramid");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
