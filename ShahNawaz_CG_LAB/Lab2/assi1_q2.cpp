#include<GL/glut.h>

int point[3][2] = { {100, 200}, {150, 150}, {100, 100} };
 
void init() {
	glClearColor(0.2,0.7,0.8,0.5);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,500.0,0.0,500.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,1.0);
	glPointSize(10.0);
	glBegin(GL_LINES);
		for(int i=0; i<3; i++) {
			glVertex2iv(point[i]);
			glVertex2iv(point[(i+1)%3]);
		}
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,800);
	glutCreateWindow("Trianlge");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
