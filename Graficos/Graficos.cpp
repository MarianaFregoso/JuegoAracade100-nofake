// Graficos.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#define GLEW_STATIC
#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include <iostream>
using namespace std;


//Declaración de ventana
GLFWwindow *window;

GLfloat red, green, blue;
GLfloat ty = -0.8f;
GLfloat tx = 0.0f;

GLfloat ly = -0.77f;
GLfloat lx = 0.0f;


double tiempoAnterior = 0.0;
double velocidad = 0.4;

GLfloat angulo = 0.0f;
GLfloat velocidadangular = 180.0f;

GLfloat enemigox = 0.0f;
GLfloat enemigoy = 0.6f;

GLfloat enemigodosx = 0.2f;
GLfloat enemigotresx = 0.4f;
GLfloat enemigocuatrox = 0.6f;
GLfloat enemigocincox = 0.8f;

GLfloat enemigomenosdosx = -0.2f;
GLfloat enemigomenostresx = -0.4f;
GLfloat enemigomenoscuatrox = -0.6f;
GLfloat enemigomenoscincox = -0.8f;

void dibujarEnemigo() {
	glPushMatrix();
	glTranslatef(enemigox, enemigoy, 0.0f);
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 0.0f, 0.0f);

	glEnd();//Finaliza la rutina
	glPopMatrix();

}

void dibujarEnemigo2() {
	glPushMatrix();
	glTranslatef(enemigodosx, enemigoy, 0.0f);
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 0.0f, 0.0f);

	glEnd();//Finaliza la rutina
	glPopMatrix();

}

void dibujarEnemigo3() {
	glPushMatrix();
	glTranslatef(enemigotresx, enemigoy, 0.0f);
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 0.0f, 0.0f);

	glEnd();//Finaliza la rutina
	glPopMatrix();

}

void dibujarEnemigo4() {
	glPushMatrix();
	glTranslatef(enemigocuatrox, enemigoy, 0.0f);
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 0.0f, 0.0f);

	glEnd();//Finaliza la rutina
	glPopMatrix();

}

void dibujarEnemigo5() {
	glPushMatrix();
	glTranslatef(enemigocincox, enemigoy, 0.0f);
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 0.0f, 0.0f);

	glEnd();//Finaliza la rutina
	glPopMatrix();

}

void dibujarEnemigo2x() {
	glPushMatrix();
	glTranslatef(enemigomenosdosx, enemigoy, 0.0f);
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 0.0f, 0.0f);

	glEnd();//Finaliza la rutina
	glPopMatrix();

}

void dibujarEnemigo3x() {
	glPushMatrix();
	glTranslatef(enemigomenostresx, enemigoy, 0.0f);
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 0.0f, 0.0f);

	glEnd();//Finaliza la rutina
	glPopMatrix();

}

void dibujarEnemigo4x() {
	glPushMatrix();
	glTranslatef(enemigomenoscuatrox, enemigoy, 0.0f);
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 0.0f, 0.0f);

	glEnd();//Finaliza la rutina
	glPopMatrix();

}

void dibujarEnemigo5x() {
	glPushMatrix();
	glTranslatef(enemigomenoscincox, enemigoy, 0.0f);
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 0.0f, 0.0f);

	glEnd();//Finaliza la rutina
	glPopMatrix();

}


void dibujarheroe() {
	glPushMatrix();
	glTranslatef(tx, ty, 0.0f);

	glRotatef(angulo, 0.0f, 0.0f, 1.0f);
	glScalef(0.08f, 0.08f, 0.08f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.6f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(0.6f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.6f, 0.0f, 1.0f);
	glVertex3f(1.0, 0.0f, 0.0f);

	glEnd();//Finaliza la rutina
	glPopMatrix();
}

void bala()
{
	glPushMatrix();
	glTranslatef(lx, ly, 0.0f);
	glRotatef(angulo, 0.0f, 0.0f, 1.0f);
	glScalef(0.05f, 0.05f, 0.05f);
	glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 0.0f, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0, 0.0f, 0.0f);

	glEnd();//Finaliza la rutina
	glPopMatrix();
}


void dibujar()
{
	dibujarheroe();
	dibujarEnemigo();
	dibujarEnemigo2();
	dibujarEnemigo3();
	dibujarEnemigo4();
	dibujarEnemigo5();
	dibujarEnemigo2x();
	dibujarEnemigo3x();
	dibujarEnemigo4x();
	dibujarEnemigo5x();
	bala();
}

void checarcolisiones() {
	if (lx >= enemigox - 0.01 &&
		lx <= enemigox + 0.01 &&
		ly >= enemigoy - 0.01 &&
		ly <= enemigoy + 0.01 &&
		lx >= enemigodosx - 0.01 &&
		lx <= enemigodosx + 0.01 &&
		ly >= enemigoy - 0.01 &&
		ly <= enemigoy + 0.01 &&
		lx >= enemigotresx - 0.01 &&
		lx <= enemigotresx + 0.01 &&
		ly >= enemigoy - 0.01 &&
		ly <= enemigoy + 0.01 &&
		lx >= enemigocuatrox - 0.01 &&
		lx <= enemigocuatrox + 0.01 &&
		ly >= enemigoy - 0.01 &&
		ly <= enemigoy + 0.01 &&
		lx >= enemigocincox - 0.01 &&
		lx <= enemigocincox + 0.01 &&
		ly >= enemigoy - 0.01 &&
		ly <= enemigoy + 0.01 &&
		lx >= enemigomenosdosx - 0.01 &&
		lx <= enemigomenosdosx + 0.01 &&
		ly >= enemigoy - 0.01 &&
		ly <= enemigoy + 0.01 &&
		lx >= enemigomenostresx - 0.01 &&
		lx <= enemigomenostresx + 0.01 &&
		ly >= enemigoy - 0.01 &&
		ly <= enemigoy + 0.01 &&
		lx >= enemigomenoscuatrox - 0.01 &&
		lx <= enemigomenoscuatrox + 0.01 &&
		ly >= enemigoy - 0.01 &&
		ly <= enemigoy + 0.01 &&
		lx >= enemigomenoscincox - 0.01 &&
		lx <= enemigomenoscincox + 0.01)
	
	
	
	{
		exit(0);
	}
}

void actualizar() {


	double tiempoActual = glfwGetTime();
	double Tiempotranscrrido = tiempoActual - tiempoAnterior;

	int estadoizq = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoizq == GLFW_PRESS) {
		angulo += velocidadangular * Tiempotranscrrido;
		if (angulo > 360) {
			angulo -= 360.0f;
		}
	}

	int estadoderecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoderecha == GLFW_PRESS) {
		angulo -= velocidadangular * Tiempotranscrrido;
		if (angulo > 0) {
			angulo += 360.0f;
		}
	}

	/*int disparar = glfwGetKey(window, GLFW_KEY_SPACE);
	if (disparar == GLFW_PRESS) {
		angulo -= ;
	}*/

	checarcolisiones();

	tiempoAnterior = tiempoActual;
}

int main()
{
	//Propiedades de la ventana
	GLfloat ancho = 1024;
	GLfloat alto = 768;

	//Inicialización de GLFW
	if (!glfwInit()) {
		//Si no se inició bien, terminar la ejecución
		exit(EXIT_FAILURE);
	}

	//Inicializar la ventana
	window = glfwCreateWindow(ancho, alto, "Graficos", NULL, NULL);
	//Verficar si se creó bien la ventana
	if (!window) {
		//Cerrar todos los procesos de GLFW
		glfwTerminate();
		//Termina ejecución
		exit(EXIT_FAILURE);
	}

	//Establecer "window" como contexto
	glfwMakeContextCurrent(window);

	//Se trae las funciones de OpenGL Moderno
	glewExperimental = true;
	//Inicializar GLEW
	GLenum glewError = glewInit();
	//Verificar que GLEW se inicializó bien
	if (glewError != GLEW_OK) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}



	const GLubyte *version = glGetString(GL_VERSION);
	cout << "Version de OpenGL: " << version << endl;

	red = green = blue = 0.0f;

	tiempoAnterior = glfwGetTime();

	//Ciclo de dibujo
	while (!glfwWindowShouldClose(window)) {
		//Establecer el area de render (viewport)
		glViewport(0, 0, ancho, alto);
		//Establecer el color con el que se limpia la pantalla
		glClearColor(red, green, blue, 1);
		//Limpiar la pantalla
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//rutina de dibujo
		actualizar();
		dibujar();

		//Intercambio de buffers
		glfwSwapBuffers(window);
		//Buscar señales de entrada
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}

