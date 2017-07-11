#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"
#include "cubo.h"
#include "tetra.h"
#include "objeto3D.h"

Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
//Inicializamos c y t con sus constructores
	c= new Cubo();
	t= new Tetra();
//Inicializamos la variable forma, tipo y versión 
	forma = AXIS;        					  
	tipo = Objeto3D::ALAMBRES;
	version =1;
	
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {

//Para que el color por defecto sea negro
glColor3f(0,0,0);
if(forma == CUBO){
	if(version==1) c->Dibujar(tipo);
	if(version==2) c->Dibujar2(tipo);
}
if(forma == TETRA){	
	if(version==1) t->Dibujar(tipo);	
	if(version==2) t->Dibujar2(tipo);
	}
}



void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	if(forma != AXIS)
		draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

 std::cout << "Tecla" << Tecla1<< std::endl;
 	if (toupper(Tecla1)=='1')		version=1;
 	if (toupper(Tecla1)=='2')		version=2;
	if (toupper(Tecla1)=='Q')	 	return 1;	
	if (toupper(Tecla1)=='3')		forma = TETRA;
	if (toupper(Tecla1)=='4')		forma =CUBO;	
	if (toupper(Tecla1)=='L')		tipo = Objeto3D::ALAMBRES;
	if (toupper(Tecla1)=='P')		tipo = Objeto3D::VERTICES;
	if (toupper(Tecla1)=='S')		tipo = Objeto3D::SOLIDO;
	if (toupper(Tecla1)=='A')		tipo = Objeto3D::AJEDREZ;

//Para cuando pulso la E no sale nada, no entiendo porque el ultimo if de este metodo siempre que se pulsa su tecla 
//correspondiente se sale de la ventana. Asi que este ultimo lo he puesto de relleno. No sirve para nada darle a la
//E, bueno sí, para salirse de la ventana
	if (toupper(Tecla1)=='E')		forma = AXIS;
	else					return 0;
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_F1:Observer_distance*=1.2;break;
	case GLUT_KEY_F2:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}




