#include <iostream>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glut.h>
#define STB_IMAGE_IMPLEMENTATION
#include <STB_IMAGE/stb_image.h>
#include <time.h>

using namespace std;

GLfloat xRotated, yRotated, zRotated;
GLdouble radius = 1;

void init(void)
{
	//select clearing (background) color
	glClearColor(0.0, 0.0, 0.0, 1.0);

	//initialize viewing values 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}


void display(void)
{
	glutIdleFunc(display); /// < Refresing

	glMatrixMode(GL_MODELVIEW);
	// clear the drawing buffer.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// clear the identity matrix.


	///////////////////// SUN
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -80.0f);
	// Red color used to draw.
	glColor3f(0.93, 0.31, 0.04);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(radius + 3.5f, 20, 20);
	// Flush buffers to screen

	///////////////////////////////////////// SECOND SPHERE [Mercury]
	glLoadIdentity();
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	gluLookAt(0, 0, -180, 0, 0, -80.0, 0, 1.0, 0.0);
	glTranslatef(sin(SDL_GetTicks() * 0.001f) * 8.0f, cos(SDL_GetTicks() * 0.001f) * 8.0f, -80.0f);
	// Red color used to draw.
	glColor3f(0.39, 0.39, 0.39);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(radius - 0.4f, 20, 20);

	///////////////////////////////////////// SECOND SPHERE [Venus]
	glLoadIdentity();
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	gluLookAt(0, 0, -180, 0, 0, -80.0, 0, 1.0, 0.0);
	glTranslatef(sin(SDL_GetTicks() * 0.0009f) * 11.0f, cos(SDL_GetTicks() * 0.0009f) * 11.0f, -80.0f);
	// Red color used to draw.
	glColor3f(0.83, 0.48, 0.11);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(radius + 0.2f, 20, 20);

	///////////////////////////////////////// SECOND SPHERE [Earth]
	glLoadIdentity();
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	gluLookAt(0, 0, -180, 0, 0, -80.0, 0, 1.0, 0.0);
	glTranslatef(sin(SDL_GetTicks() * 0.0008f) * 15.0f, cos(SDL_GetTicks() * 0.0008f) * 15.0f, -80.0f);
	// Red color used to draw.
	glColor3f(0.44, 0.47, 0.25);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(radius + 0.3f, 20, 20);

	///////////////////////////////////////// SECOND SPHERE [Mars]
	glLoadIdentity();
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	gluLookAt(0, 0, -180, 0, 0, -80.0, 0, 1.0, 0.0);
	glTranslatef(sin(SDL_GetTicks() * 0.0007f) * 19.0f, cos(SDL_GetTicks() * 0.0007f) * 19.0f, -80.0f);
	// Red color used to draw.
	glColor3f(0.68, 0.53, 0.31);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(radius - 0.3f, 20, 20);

	///////////////////////////////////////// SECOND SPHERE [Jupiter]
	glLoadIdentity();
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	gluLookAt(0, 0, -180, 0, 0, -80.0, 0, 1.0, 0.0);
	glTranslatef(sin(SDL_GetTicks() * 0.0006f) * 25.0f, cos(SDL_GetTicks() * 0.0006f) * 25.0f, -80.0f);
	// Red color used to draw.
	glColor3f(0.58, 0.61, 0.68);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(radius + 1.6f, 20, 20);

	///////////////////////////////////////// SECOND SPHERE [Saturn]
	glLoadIdentity();
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	gluLookAt(0, 0, -180, 0, 0, -80.0, 0, 1.0, 0.0);
	glTranslatef(sin(SDL_GetTicks() * 0.0005f) * 32.0f, cos(SDL_GetTicks() * 0.0005f) * 32.0f, -80.0f);
	// Red color used to draw.
	glColor3f(0.79, 0.67, 0.54);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(radius + 1.2f, 20, 20);

	///////////////////////////////////////// SECOND SPHERE [Uranus]
	glLoadIdentity();
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	gluLookAt(0, 0, -180, 0, 0, -80.0, 0, 1.0, 0.0);
	glTranslatef(sin(SDL_GetTicks() * 0.0004f) * 36.0f, cos(SDL_GetTicks() * 0.0004f) * 36.0f, -80.0f);
	// Red color used to draw.
	glColor3f(0.45, 0.60, 0.94);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(radius + 0.6f, 20, 20);

	///////////////////////////////////////// SECOND SPHERE [Neptune]
	glLoadIdentity();
	// traslate the draw by z = -4.0
	// Note this when you decrease z like -8.0 the drawing will looks far , or smaller.
	gluLookAt(0, 0, -180, 0, 0, -80.0, 0, 1.0, 0.0);
	glTranslatef(sin(SDL_GetTicks() * 0.0003f) * 41.0f, cos(SDL_GetTicks() * 0.0003f) * 41.0f, -80.0f);
	// Red color used to draw.
	glColor3f(0.20, 0.30, 0.52);
	// changing in transformation matrix.
	// rotation about X axis
	glRotatef(xRotated, 1.0, 0.0, 0.0);
	// rotation about Y axis
	glRotatef(yRotated, 0.0, 1.0, 0.0);
	// rotation about Z axis
	glRotatef(zRotated, 0.0, 0.0, 1.0);
	// scaling transfomation 
	glScalef(1.0, 1.0, 1.0);
	// built-in (glut library) function , draw you a sphere.
	glutSolidSphere(radius + 0.6f, 20, 20);

	glFlush();
	// sawp buffers called because we are using double buffering 
	// glutSwapBuffers();
}

void reshape(int x, int y)
{
	if (y == 0 || x == 0) return;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(39.0, (GLdouble)x / (GLdouble)y, 0.6, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);  //Use the whole window for rendering
}


int main(int argc, char** argv) {
	//Initialise GLUT with command-line parameters. 
	glutInit(&argc, argv);

	//Set Display Mode
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//Set the window size
	glutInitWindowSize(800, 800);

	//Set the window position
	glutInitWindowPosition(NULL, NULL);

	//Create the window
	glutCreateWindow("Solar System");

	xRotated = yRotated = zRotated = 30.0;
	xRotated = 43;
	yRotated = 50;


	GLenum res = glewInit();
	if (res != GLEW_OK)
	{
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	//Call init (initialise GLUT
	init();


	//Call "display" function
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);

	//Enter the GLUT event loop
	glutMainLoop();

	glDisableVertexAttribArray(0);

	return 0;
}