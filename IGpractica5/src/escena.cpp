#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"
#include "cubo.h"
#include "tetra.h"
#include "objeto3D.h"
#include "ply.h"
#include "luz.h"
#include "RevolucionY.h"
#include "ventilador.h"
#include "jpg_imagen.hpp"

Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
//Inicializamos c y t con sus constructores
	c= new Cubo();
	t= new Tetra();
//Inicializamos las camaras
	camAct =0;

	float up0[]={0,1,0};
	float at0[]={0,0,0};
	float eye0[]={0,0,Observer_distance};

	float up1[]={0,0,-1};
	float at1[]={0,0,0};
	float eye1[]={0,Observer_distance,0};

	float up2[]={0,1,0};
	float at2[]={0,0,0};
	float eye2[]={Observer_distance,0,0};
	
	Camara c1(eye0, up0, at0, true,0);
	Camara c2(eye1, up1, at1, true,1);
	Camara c3(eye2, up2, at2, false,2);
	cam.push_back(c1);
	cam.push_back(c2);
	cam.push_back(c3);
//Inicializamos las piezas
	Pieza p1(1,16776960);
	p1.calcularCentro(c->vertices);
	Pieza p2(2,16711935);
	p2.calcularCentro(t->vertices);
	pieza.push_back(p1);
	pieza.push_back(p2);
	pieza[0].trasladar(-50,0,-50);
	pieza[1].trasladar(50,0,50);
//Inicializamos la luz
	l= new Luz();

//	cilindro = new RevolucionY(20,80, "ply/cilindro.ply");
//Inicializamos la variable forma, tipo y versión 
	forma = VENT;        					  
	tipo = Objeto3D::SOLIDO;
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
glDisable(GL_LIGHTING);
glDisable(GL_DITHER);
glPushMatrix();
glColor3ub(0,255,255);
//glColor3f(0,1,1);
glTranslatef(-50,0,-50);
glScalef(80,80,80);
c->Dibujar(tipo);
glPopMatrix();

glPushMatrix();
//glColor3f(1,1,0);
glColor3ub(255,0,255);
glTranslatef(50,0,50);
glScalef(80,80,80);
t->Dibujar(tipo);
glPopMatrix();
glEnable(GL_DITHER);



// glColor3f(1,1,1);
// jpg::Imagen *pimg2 = new jpg::Imagen("Texturas/text-lata-1.jpg");
// 	unsigned int tamx = pimg2->tamX(); 
// 	unsigned int tamy = pimg2->tamY(); 
// 	unsigned char *texels2 = pimg2->leerPixels();
// 	glEnable( GL_TEXTURE_2D);
// 	gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, tamx, tamy, GL_RGB, GL_UNSIGNED_BYTE, texels2);
	

// 	glBegin(GL_QUADS);
// 		glNormal3f( 0.0, 0.0, 1.0);
// 		glTexCoord2f(0.0, 1.0);
// 		glVertex3f(-100.0, -100.0, 0.0);
// 		glTexCoord2f(1.0, 1.0);
// 		glVertex3f( 100.0, -100.0, 0.0);
// 		glTexCoord2f(1.0, 0.0);
// 		glVertex3f( 100.0, 100.0, 0.0);
// 		glTexCoord2f(0.0, 0.0);
// 		glVertex3f(-100.0, 100.0, 0.0);
// 	glEnd();
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
	if (toupper(Tecla1)=='Q')	 	return 1;	
	if (toupper(Tecla1)=='A')		cam[camAct].Mover1Persona('a');
	if (toupper(Tecla1)=='D')		cam[camAct].Mover1Persona('d');
	if (toupper(Tecla1)=='W')		cam[camAct].Mover1Persona('w');
	if (toupper(Tecla1)=='S')		cam[camAct].Mover1Persona('s');
	

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
	case GLUT_KEY_F1:camAct=0; change_projection(); break;
	case GLUT_KEY_F2:camAct=1; change_projection(); break;
	case GLUT_KEY_F3:camAct=2;change_projection(); break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(cam[camAct].perspectiva==false){
	glOrtho(-Width*3,Width*3,-Height*3,Height*3,Front_plane,Back_plane);
}
else{
	glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}
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
gluLookAt(cam[camAct].eye[0],cam[camAct].eye[1] , cam[camAct].eye[2],
			cam[camAct].at[0], cam[camAct].at[1], cam[camAct].at[2],
			cam[camAct].up[0], cam[camAct].up[1], cam[camAct].up[2]);

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




