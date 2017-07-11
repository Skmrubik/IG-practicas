#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "ventilador.h"
#include "objeto3D.h"
#include <cmath>

Ventilador::Ventilador(){
	tetra = new Tetra();
	cubo = new Cubo();
	cilindro = new RevolucionY(20,1,"ply/cilindro.ply");
	glo = new RevolucionY(20, 1, "ply/globo.ply");
}
//Pinta la base del ventilador
void Ventilador::base(Objeto3D::Tipo tipo){
	glColor3f(0,0,0);
	glPushMatrix(); 
	glScalef(40,5,40);
	cilindro->Dibujar(tipo);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,30,0);
	glScalef(10,50,10);
	cilindro->Dibujar(tipo);
	glPopMatrix();

	glColor3f(1,0,0);
	glPushMatrix(); 
	glTranslatef(0,3.7,0);
	glScalef(40,2,40);
	cilindro->Dibujar(tipo);
	glPopMatrix();
}
//Pinta el cuerpo, este se podrá mover en el eje Y
void Ventilador::cuerpo(Objeto3D::Tipo tipo, float movGlobo){

	glColor3f(0.3,0.3,0.3);
	glPushMatrix();
	glScalef(6,50,6);
	cilindro->Dibujar(tipo);
	glPopMatrix();

	glColor3f(1, 0.5,0);
	glPushMatrix();
	glTranslatef(0,30,0);
	glScalef(10,10,15);
	cubo->Dibujar(tipo);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,movGlobo);
	globo(tipo);
	glPopMatrix();
}
//Pinta un ala de las 3 que tiene el ventilador, compuesta por un cilindro y un tetraedro
void Ventilador::ala(Objeto3D::Tipo tipo){
//Aplicamos la rotacion para que cada ala tenga una rotacion en el eje Y (para el efecto de hacer aire)
glRotatef(20,0,1,0);

glPushMatrix();
glTranslatef(0,-17,0);
glScalef(15,40,1);
tetra->Dibujar(tipo);
glPopMatrix();

glPushMatrix();
glTranslatef(0,-27,0);
glScalef(12.5,12.5,1);
glRotatef(90,1,0,0);
cilindro->Dibujar(tipo);
glPopMatrix();


}

//Pinta un globo
void Ventilador::globo( Objeto3D::Tipo tipo){
glColor3f(1,0,0);
glPushMatrix();
glScalef(2,2,2);
glTranslatef(0,15,20);
glo->Dibujar(tipo);
glPopMatrix();
}


//Pinto las tres alas y un cilindro que sirve de union de estas tres
void Ventilador::alas(Objeto3D::Tipo tipo){

glColor3f(0.7,0.7,0.7);
glPushMatrix();
ala(tipo);
glPopMatrix();

glPushMatrix();
glRotatef(120,0,0,1);
ala(tipo);
glPopMatrix();

glPushMatrix();
glRotatef(240,0,0,1);
ala(tipo);
glPopMatrix();

glColor3f(0.5,0.5,0.5);
glPushMatrix();
glRotatef(90,1,0,0);
glScalef(5,3,5);
cilindro->Dibujar(tipo);
glPopMatrix();


}

//Por último lo uno todo en un solo objeto
void Ventilador::draw(int alt, int gra, float gra2, float movGlobo, Objeto3D::Tipo tipo)
{

glPushMatrix();
	base(tipo);

	glRotatef(gra,0,1,0);
	glTranslatef(0,alt,0);
	cuerpo(tipo,movGlobo);

	glTranslatef(0,30,9);
	glRotatef(gra2,0,0,1);
	alas(tipo);
glPopMatrix();
}
