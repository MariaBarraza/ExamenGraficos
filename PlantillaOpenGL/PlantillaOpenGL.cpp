// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "Shader.h"
#include "Vertice.h"

#include "Modelo.h"

using namespace std;



Shader *shader;
GLuint posicionID;
GLuint colorID;

Modelo *rectangulo;
Modelo *cuadrado;
Modelo *ojoIzquierdo;
Modelo *ojoDerecho;
Modelo *piernaIzquierda;
Modelo *piernaDerecha;
Modelo *cuadrito;
Modelo *cuadrito2;
Modelo *bocaIzquierda;
Modelo *bocaDerecha;
Modelo *antenaIzquierda;
Modelo *antenaDerecha;



void inicializarCuadrado() {

	cuadrado = new Modelo();

	Vertice v1 = {
		vec3(-0.6f,0.5f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v2 = {
		vec3(0.6f,0.5f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v3 = {
		vec3(0.6f,-0.5f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v4 = {
		vec3(-0.6f,-0.5f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	cuadrado->vertices.push_back(v1);
	cuadrado->vertices.push_back(v2);
	cuadrado->vertices.push_back(v3);
	cuadrado->vertices.push_back(v4);
}

void inicializarRectangulo() {

	rectangulo = new Modelo();

	Vertice v1 =
	{
		vec3(-0.83f,0.33f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v2 =
	{
		vec3(0.83f,0.33f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v3 =
	{
		vec3(0.83f,-0.33f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v4 =
	{
		vec3(-0.83f,-0.33f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	rectangulo->vertices.push_back(v1);
	rectangulo->vertices.push_back(v2);
	rectangulo->vertices.push_back(v3);
	rectangulo->vertices.push_back(v4);
	
}

void inicializarOjoIzquierdo() {

	ojoIzquierdo = new Modelo();

	Vertice v1 = {
		vec3(-0.43f,0.33f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};

	Vertice v2 = {
		vec3(-0.26f,0.33f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};

	Vertice v3 = {
		vec3(-0.26f,-0.16f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};

	Vertice v4 = {
		vec3(-0.43f,-0.16f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};

	ojoIzquierdo->vertices.push_back(v1);
	ojoIzquierdo->vertices.push_back(v2);
	ojoIzquierdo->vertices.push_back(v3);
	ojoIzquierdo->vertices.push_back(v4);
}
void inicializarOjoDerecho() {

	ojoDerecho = new Modelo();

	Vertice v1 = {
		vec3(0.43f,0.33f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};

	Vertice v2 = {
		vec3(0.26f,0.33f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};

	Vertice v3 = {
		vec3(0.26f,-0.16f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};

	Vertice v4 = {
		vec3(0.43f,-0.16f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};

	ojoDerecho->vertices.push_back(v1);
	ojoDerecho->vertices.push_back(v2);
	ojoDerecho->vertices.push_back(v3);
	ojoDerecho->vertices.push_back(v4);
}

void inicializarPiernaIzquierda() {

	piernaIzquierda = new Modelo();

	Vertice v1 = {
		vec3(-1.0f,0.0f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v2 = {
		vec3(-0.83f,0.0f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v3 = {
		vec3(-0.83f,-0.68f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v4 = {
		vec3(-1.0f,-0.68f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	piernaIzquierda->vertices.push_back(v1);
	piernaIzquierda->vertices.push_back(v2);
	piernaIzquierda->vertices.push_back(v3);
	piernaIzquierda->vertices.push_back(v4);
}
void inicializarPiernaDerecha() {

	piernaDerecha = new Modelo();

	Vertice v1 = {
		vec3(1.0f,0.0f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v2 = {
		vec3(0.83f,0.0f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v3 = {
		vec3(0.83f,-0.68f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v4 = {
		vec3(1.0f,-0.68f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	piernaDerecha->vertices.push_back(v1);
	piernaDerecha->vertices.push_back(v2);
	piernaDerecha->vertices.push_back(v3);
	piernaDerecha->vertices.push_back(v4);
}

void inicializarCuadrito() {

	cuadrito = new Modelo();

	Vertice v1 = {
		vec3(-0.6f,-0.5f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v2 = {
		vec3(-0.43f,-0.5f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v3 = {
		vec3(-0.43f,-0.68f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v4 = {
		vec3(-0.6f,-0.68f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	cuadrito->vertices.push_back(v1);
	cuadrito->vertices.push_back(v2);
	cuadrito->vertices.push_back(v3);
	cuadrito->vertices.push_back(v4);
}
void inicializarCuadrito2() {

	cuadrito2 = new Modelo();

	Vertice v1 = {
		vec3(0.6f,-0.5f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v2 = {
		vec3(0.43f,-0.5f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v3 = {
		vec3(0.43f,-0.68f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v4 = {
		vec3(0.6f,-0.68f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	cuadrito2->vertices.push_back(v1);
	cuadrito2->vertices.push_back(v2);
	cuadrito2->vertices.push_back(v3);
	cuadrito2->vertices.push_back(v4);
}

void inicializarBocaIzquierda() {

	bocaIzquierda = new Modelo();

	Vertice v1 = {
		vec3(-0.43f,-0.68f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v2 = {
		vec3(-0.09f,-0.68f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v3 = {
		vec3(-0.09f,-0.85f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v4 = {
		vec3(-0.43f,-0.85f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	bocaIzquierda->vertices.push_back(v1);
	bocaIzquierda->vertices.push_back(v2);
	bocaIzquierda->vertices.push_back(v3);
	bocaIzquierda->vertices.push_back(v4);
}

void inicializarBocaDerecha() {

	bocaDerecha = new Modelo();

	Vertice v1 = {
		vec3(0.43f,-0.68f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v2 = {
		vec3(0.09f,-0.68f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v3 = {
		vec3(0.09f,-0.85f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v4 = {
		vec3(0.43f,-0.85f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	bocaDerecha->vertices.push_back(v1);
	bocaDerecha->vertices.push_back(v2);
	bocaDerecha->vertices.push_back(v3);
	bocaDerecha->vertices.push_back(v4);
}

void inicializarAntenaIzquierda() {

	antenaIzquierda = new Modelo();

	Vertice v1 = {
		vec3(-0.43f,0.67f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v2 = {
		vec3(-0.26f,0.67f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v3 = {
		vec3(-0.26f,0.5f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v4 = {
		vec3(-0.43f,0.5f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};
	
	//antena parte 2
	Vertice v5 = {
		vec3(-0.6f,0.84f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v6 = {
		vec3(-0.43f,0.84f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v7 = {
		vec3(-0.43f,0.67f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v8 = {
		vec3(-0.6f,0.67f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	antenaIzquierda->vertices.push_back(v1);
	antenaIzquierda->vertices.push_back(v2);
	antenaIzquierda->vertices.push_back(v3);
	antenaIzquierda->vertices.push_back(v4);

	antenaIzquierda->vertices.push_back(v5);
	antenaIzquierda->vertices.push_back(v6);
	antenaIzquierda->vertices.push_back(v7);
	antenaIzquierda->vertices.push_back(v8);

}

void inicializarAntenaDerecha() {

	antenaDerecha = new Modelo();

	Vertice v1 = {
		vec3(0.43f,0.67f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v2 = {
		vec3(0.26f,0.67f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v3 = {
		vec3(0.26f,0.5f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v4 = {
		vec3(0.43f,0.5f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	//antena parte 2
	Vertice v5 = {
		vec3(0.6f,0.84f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v6 = {
		vec3(0.43f,0.84f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v7 = {
		vec3(0.43f,0.67f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	Vertice v8 = {
		vec3(0.6f,0.67f,0.0f),
		vec4(0.0f,0.0f,1.0f,1.0f)
	};

	antenaDerecha->vertices.push_back(v1);
	antenaDerecha->vertices.push_back(v2);
	antenaDerecha->vertices.push_back(v3);
	antenaDerecha->vertices.push_back(v4);

	antenaDerecha->vertices.push_back(v5);
	antenaDerecha->vertices.push_back(v6);
	antenaDerecha->vertices.push_back(v7);
	antenaDerecha->vertices.push_back(v8);

}





void dibujar() {

	rectangulo->dibujar(GL_QUADS);
	cuadrado->dibujar(GL_QUADS);
	ojoIzquierdo->dibujar(GL_QUADS);
	ojoDerecho->dibujar(GL_QUADS);
	piernaIzquierda->dibujar(GL_QUADS);
	piernaDerecha->dibujar(GL_QUADS);
	cuadrito->dibujar(GL_QUADS);
	cuadrito2->dibujar(GL_QUADS);
	bocaIzquierda->dibujar(GL_QUADS);
	bocaDerecha->dibujar(GL_QUADS);
	antenaIzquierda->dibujar(GL_QUADS);
	antenaDerecha->dibujar(GL_QUADS);
}

void actualizar() {
	
}


int main()
{
	//Declaramos apuntador de ventana
	GLFWwindow *window;
	
	//Si no se pudo iniciar glfw
	//terminamos ejcución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//entonces inicializamos la ventana
	window = glfwCreateWindow(1024, 768, "Ventana", 
			NULL, NULL);
	//Si no podemos iniciar la ventana
	//Entonces terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido  el contexto
	//Activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();

	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	//---------------------------------------------------------------------....................................................................................

	//AQUI INICIALIZAMOS METODOS/PROCEDIMIENTO
	
	inicializarRectangulo();
	inicializarCuadrado();
	inicializarOjoIzquierdo();
	inicializarOjoDerecho();
	inicializarPiernaIzquierda();
	inicializarPiernaDerecha();
	inicializarCuadrito();
	inicializarCuadrito2();
	inicializarBocaIzquierda();
	inicializarBocaDerecha();
	inicializarAntenaIzquierda();
	inicializarAntenaDerecha();




	const char *rutaVertex = "VertexShader.shader";
	const char *rutaFragment = "FragmentShader.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");

	//Desenlazar el shader
	shader->desenlazar();




	//-------------AQUI MANDAMOS LLAMAR LOS SHADERS Y VERTEX ARRAY DE LOS OBJETOS------------------------

	/*----------------------------------RECTANGULO----------------------------------*/
	//Establecer shader al modelo
	rectangulo->shader = shader;
	//Inicializar el vertex array
	rectangulo->inicializarVertexArray(posicionID, colorID);



	/*----------------------------------CUADRADO----------------------------------*/
	//Establecer shader al modelo
	cuadrado->shader = shader;
	//Inicializar el vertex array
	cuadrado->inicializarVertexArray(posicionID, colorID);

	/*----------------------------------OJO IZQUIERDO----------------------------------*/
	//Establecer shader al modelo
	ojoIzquierdo->shader = shader;
	//Inicializar el vertex array
	ojoIzquierdo->inicializarVertexArray(posicionID, colorID);

	/*----------------------------------OJO DERECHO----------------------------------*/
	//Establecer shader al modelo
	ojoDerecho->shader = shader;
	//Inicializar el vertex array
	ojoDerecho->inicializarVertexArray(posicionID, colorID);

	/*----------------------------------PIERNA IZQUIERDA----------------------------------*/
	//Establecer shader al modelo
	piernaIzquierda->shader = shader;
	//Inicializar el vertex array
	piernaIzquierda->inicializarVertexArray(posicionID, colorID);

	/*----------------------------------PIERNA DERECHA----------------------------------*/
	//Establecer shader al modelo
	piernaDerecha->shader = shader;
	//Inicializar el vertex array
	piernaDerecha->inicializarVertexArray(posicionID, colorID);

	/*----------------------------------CUADRITO IZQUIERDA----------------------------------*/
	//Establecer shader al modelo
	cuadrito->shader = shader;
	//Inicializar el vertex array
	cuadrito->inicializarVertexArray(posicionID, colorID);

	/*----------------------------------CUADRITO DERECHA----------------------------------*/
	//Establecer shader al modelo
	cuadrito2->shader = shader;
	//Inicializar el vertex array
	cuadrito2->inicializarVertexArray(posicionID, colorID);

	/*----------------------------------BOCA IZQUIERDA----------------------------------*/
	//Establecer shader al modelo
	bocaIzquierda->shader = shader;
	//Inicializar el vertex array
	
	bocaIzquierda->inicializarVertexArray(posicionID, colorID);

	/*----------------------------------BOCA DERECHA----------------------------------*/
	//Establecer shader al modelo
	bocaDerecha->shader = shader;
	//Inicializar el vertex array
	bocaDerecha->inicializarVertexArray(posicionID, colorID);

	/*----------------------------------ANTENA IZQUIERDA----------------------------------*/
	//Establecer shader al modelo
	antenaIzquierda->shader = shader;
	//Inicializar el vertex array
	antenaIzquierda->inicializarVertexArray(posicionID, colorID);

	/*----------------------------------ANTENA DERECHA----------------------------------*/
	//Establecer shader al modelo
	antenaDerecha->shader = shader;
	//Inicializar el vertex array
	antenaDerecha->inicializarVertexArray(posicionID, colorID);

	
	




	
	
	





	//----------------------------------------------------------------------....................................................................................

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {

		//Esablecer region de dibujo
		glViewport(0, 0, 1024, 768);

		//Establece el color de borrado
		glClearColor(0.0f, 0.0f, 0.f, 1);

		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);

		//Reconocer si hay entradas
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;

}

