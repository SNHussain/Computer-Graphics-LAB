#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
int n;              
float radius = 200; 
float cx = 250, cy = 250; 

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); 

    float angle, x, y;

    glBegin(GL_LINE_LOOP);   
    for (int i = 0; i < n; i++) {
        angle = 2 * M_PI * i / n;
        x = cx + radius * cos(angle);
        y = cy + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    printf("Enter number of sides: ");
    scanf("%d", &n);

    if (n < 3) {
        printf("Polygon must have at least 3 sides!\n");
        return 0;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Regular Polygon");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
