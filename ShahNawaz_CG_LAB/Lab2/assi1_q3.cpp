#include<GL/glut.h>

int x = 0;
int lower_level = 100;
int upper_level = 200;
int gap = 20;

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
		for(int i=0; i<25; i++) {
			if(i%2 == 0) {
				glVertex2i(x, lower_level);
				glVertex2i(x+gap, upper_level);
			}
			else {
				glVertex2i(x, upper_level);
				glVertex2i(x+gap, lower_level);
			}
			x += gap;
		}
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,800);
	glutCreateWindow("ZigZag Example");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

