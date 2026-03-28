#include<GL/glut.h>

int points[5][2] = { {100, 100}, {150, 200}, {200, 100}, {100, 175}, {200, 175} };

void init() {
	glClearColor(0.0,1.0,0.0,0.5);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,500.0,0.0,500.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,1.0);
	glPointSize(10.0);
	glBegin(GL_LINES);
		for(int i=0; i<5; i++) {
			glVertex2iv(points[i%5]);
			glVertex2iv(points[(i+1)%5]);
		}
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,800);
	glutCreateWindow("Star");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
