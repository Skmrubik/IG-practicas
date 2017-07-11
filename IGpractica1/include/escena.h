#ifndef _ESCENA_H
#define _ESCENA_H
#include <cmath>
#include "cubo.h"
#include "tetra.h"



class Escena {
private:
// tamaño de los ejes
static const int AXIS_SIZE=5000;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;
//Enumerado para poder cambiar desde el teclado a una u otra opcion
enum Forma {AXIS, TETRA, CUBO};
//Creamos los objetos cubo y tetra para luego inicializar sus vertices y triangulos
Cubo *c;
Tetra *t;
//Creamos variables de los tipos enumerados para trabajar con ellas despues
Forma forma; 		 
Objeto3D::Tipo tipo;    
int version;
private:
	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformación de cámara
	void change_projection();
	void change_observer();


public:
     Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacción con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
};
#endif
