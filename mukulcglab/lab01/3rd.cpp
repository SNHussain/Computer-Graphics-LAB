#include <GL/glut.h>
int x = 0;
int gap = 50;
int lowery = 100;
int uppery = 250;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);   
    glColor3f(1.0, 0.0, 0.0);       
    glBegin(GL_LINES);         
    for (int i = 0; i < 80; i++)
    {
	if(!(i&1))
	{
	glVertex2i(x + i * gap, lowery);
	glVertex2i(x+ (i+1) * gap , uppery);
	}
	else
	{
	glVertex2i(x + gap * i, uppery);
	glVertex2i(x+  gap * (i+1) , lowery);
	}
	
    }
    

    glEnd();
    glFlush();                      
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                          
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);   
    glutInitWindowSize(500, 500);                 
    glutInitWindowPosition(100, 100);               
    glutCreateWindow("Line using Points Array");   

    glClearColor(1.0, 1.0, 1.0, 1.0);       


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);

    glutDisplayFunc(display);      
    glutMainLoop();                 

    return 0;
}
