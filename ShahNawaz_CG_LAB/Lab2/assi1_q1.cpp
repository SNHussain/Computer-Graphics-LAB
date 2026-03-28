#include<GL/glut.h>

int point[3][2] = { {50, 100}, {75, 150}, {100, 200} };
 
void init() {
	glClearColor(0.0,1.0,0.0,0.5);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,500.0,0.0,500.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,1.0);
	glPointSize(10.0);
	glBegin(GL_LINE_STRIP);
		for(int i=0; i<3; i++) {
			glVertex2iv(point[i]);	
			
		}
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("Point Example");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
