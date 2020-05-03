#include <GL/glut.h>
#include <math.h> 
#include <time.h>
#include <cstdlib>
#define PI 3.14159265

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -100.0, 100.0);
}

void drawLine(double x, double y, int a, double len) {
	glVertex2d(x, y);
	float e = (float)(rand()) / RAND_MAX;
	float b = (float)(rand()) / RAND_MAX;
	float c = (float)(rand()) / RAND_MAX;
	glColor3f(e, b, c);
	glVertex2d(x - len * cos(a*PI / 180), y + len * sin(a*PI / 180));
}

void tree(double x, double y, int a, double len, int deph) {
	drawLine(x, y, a, len);
	if (deph > 0) {
		x = x - len * cos(a*PI / 180);
		y = y + len * sin(a*PI / 180);
		len = len * 0.7;
		tree(x, y, a + 45, len, deph - 1);
		tree(x, y, a - 45, len, deph - 1);
	}
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.2f, 0.5f);
	glBegin(GL_LINES);
	tree(50, 10, 90, 15, 10);
	glEnd();
	glFlush();
}


int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Ex 3");
	init();
	srand(time(NULL));
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}