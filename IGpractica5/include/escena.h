#ifndef _ESCENA_H
#define _ESCENA_H
#include <cmath>
#include "cubo.h"
#include "tetra.h"
#include "ply.h"
#include "RevolucionY.h"
#include "ventilador.h"
#include "luz.h"
#include "camara.h"
#include <vector>
#include "pieza.h"

class Escena {
private:
// tama�o de los ejes
static const int AXIS_SIZE=5000;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;
//Enumerado para poder cambiar desde el teclado a una u otra opcion
enum Forma {AXIS, TETRA, CUBO, PLY, REV, VENT};
//Creamos los objetos cubo y tetra para luego inicializar sus vertices y triangulos
Cubo *c;
Tetra *t;
Ply *p;
Luz *l;
public:
vector <Camara> cam;
int camAct;
vector <Pieza> pieza;
private:
//Camara cam[];
RevolucionY *up;
RevolucionY *down;
RevolucionY *med;
RevolucionY *r;
Ventilador *v;
RevolucionY *cilindro;
//Creamos variables de los tipos enumerados para trabajar con ellas despues
Forma forma; 		 
Objeto3D::Tipo tipo;    
int version;
int alt;
int gra;
float gra2;
float globo2;
float movGlobo;
private:
	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformaci�n de c�mara
	void change_projection();

	void change_observer();


public:
     Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacci�n con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
};
#endif
