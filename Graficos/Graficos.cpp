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
GLfloat ty = 0.0f;
GLfloat tx = 0.0f;

 double tiempoAnterior = 0.0;
 double velocidad = 0.4; 

 GLfloat angulo = 0.0f;
 GLfloat velocidadangular = 180.0f;

 GLfloat enemigox = 0.0f;
 GLfloat enemigoy = 0.6f;

 void malo() {
	 glPushMatrix();
	 glTranslatef(enemigox, enemigoy, 0.0f);
	 glScalef(0.06f, 0.06f, 0.06f);
	 glBegin(GL_TRIANGLES); //Inicia la rutina con un modo de dibujo

	 glColor3f(1.0f, 0.0f, 0.0f);
	 glVertex3f(-1.0f, 0.0f, 0.0f);

	 glColor3f(0.0f, 1.0f, 0.0f);
	 glVertex3f(0.2f, 1.0f, 0.0f);

	 glColor3f(0.0f, 0.0f, 1.0f);
	 glVertex3f(1.0, 0.0f, 0.0f);

	 glEnd();//Finaliza la rutina
	 glPopMatrix();

 }

 void dibujarpistola() {
	 glPushMatrix();
	 glTranslatef(tx, ty, 0.0f);

	 glRotatef(angulo, 0.0f, 0.0f, 1.0f);
	 glScalef(0.10f, 0.10f, 0.10f);
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

 void balas() {
	 glPushMatrix();
	 glTranslatef(tx, ty, 0.0f);

	 glRotatef(angulo, 0.0f, 0.0f, 1.0f);
	 glScalef(0.2f, 0.0f, 0.2f);
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

 void dibujar()
 {
	 dibujarpistola();
	 malo();
	 balas();
	 
 }

 void checardebalas(){
	 if (tx >= enemigox - 0.06 &&
		 tx <= enemigox + 0.06 &&
		 ty >= enemigoy - 0.06 &&
		 ty <= enemigoy + 0.06) {
		 exit(0);
	 }
 }

 void actualizar() {


	 double tiempoActual = glfwGetTime();
	 double Tiempotranscrrido = tiempoActual - tiempoAnterior;

	 int estadoizq = glfwGetKey(window, GLFW_KEY_LEFT );
	 if (estadoizq == GLFW_PRESS) {
		 angulo += velocidadangular * Tiempotranscrrido;
		 
	 }

	 int estadoderecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	 if (estadoderecha == GLFW_PRESS) {
		 angulo -= velocidadangular * Tiempotranscrrido;
		
	 }

	 int estadoderecha = glfwGetKey(window, GLFW_KEY_SPACE);
	 if (estadoderecha == GLFW_PRESS) {      
		 angulo -= velocidadangular * Tiempotranscrrido;

	 }


	/* checarcolisiones();*/
	  
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

