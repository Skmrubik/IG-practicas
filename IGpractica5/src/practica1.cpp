//**************************************************************************
// Práctica 1
//
// F.J. melero
//
// GPL
//**************************************************************************

#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>
#include <ctype.h>
#include "escena.h"
#include "camara.h"
#include <cmath>

Escena *escena;
Camara *camara;
bool moviendo=false;
int yant, xant;

void draw_scene(void)  {
	if (escena!=NULL)	escena->dibujar();
	glutSwapBuffers();
}


//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int newWidth,int newHeight)  {
	if (escena!=NULL)	escena->redimensionar(newWidth,newHeight);
	glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_keys(unsigned char Tecla1,int x,int y)  {

	int salir=0;
	if (escena!=NULL)	salir=escena->teclaPulsada(Tecla1,x,y);
	if (salir) {
		delete escena;
		exit(0);
	} else
		glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_keys(int Tecla1,int x,int y) {
	if (escena!=NULL)
		escena->teclaEspecial(Tecla1,x,y);
	glutPostRedisplay();
}
//__________________________________________________________________________________
//MIS FUNCIONES
//______________________________________________________________________________
void clickRaton( int boton, int estado, int x, int y ){
		if ( boton == GLUT_RIGHT_BUTTON ){ 
			if ( estado == GLUT_DOWN ){
			 	moviendo=true;
			 	xant=x;
			 	yant=y;
			}
			else{
				moviendo=false;
			}
		}
		if( boton== GLUT_LEFT_BUTTON){
			int pixels[1];
			if ( estado == GLUT_DOWN ){
			 	glReadPixels(x, y,1,1,GL_RGB, GL_UNSIGNED_BYTE, pixels);
			 		if(pixels[0]==escena->pieza[1].color){
			 			escena->cam[escena->camAct].at[0]=escena->pieza[1].centro[0];
			 			escena->cam[escena->camAct].at[1]=escena->pieza[1].centro[1];
			 			escena->cam[escena->camAct].at[2]=escena->pieza[1].centro[2];
			 			escena->cam[escena->camAct].examinar=true;
			 			glutPostRedisplay();
			 			cout << "Triangulo, examinar true" << endl;
			 		}
			 		else if(pixels[0]==escena->pieza[0].color){
			 			escena->cam[escena->camAct].at[0]=escena->pieza[0].centro[0];
			 			escena->cam[escena->camAct].at[1]=escena->pieza[0].centro[1];
			 			escena->cam[escena->camAct].at[2]=escena->pieza[0].centro[2];
			 			escena->cam[escena->camAct].examinar=true;
			 			cout << "Cuadrado, examinar true" << endl;
			 			glutPostRedisplay();
			 		}
			 		
			 		else{
			 			escena->cam[escena->camAct].examinar=false;
			 			glutPostRedisplay();
			 			cout << "Examinar false" << endl;
			 		}
			 	
			}
		}
}

void ratonMovido( int x, int y ){ 
		if ( moviendo==true ){
			if(abs(x-xant) > abs(y-yant)){
				if(x-xant>0){
					escena->cam[escena->camAct].girar('a',0.015);
				}
				else{
					escena->cam[escena->camAct].girar('d',0.015);
				}
			}
			else{
				if(y-yant>0){
					escena->cam[escena->camAct].girar('w',0.015);
				}
				else{
					escena->cam[escena->camAct].girar('s',0.015);
				}
			}
		}
		glutPostRedisplay();
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv) {

escena = new Escena();

// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=500,UI_window_height=500;

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);
// tamaño de la ventana (ancho y alto)
glutInitWindowSize(UI_window_width,UI_window_height);

// llamada para crear la ventana, indicando el titulo
glutCreateWindow("Práctica 1: Jorge Castillo Matas");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw_scene);
// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "tecla_normal" al evento correspondiente
glutKeyboardFunc(normal_keys);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_keys);

// funcion de inicialización
escena->inicializar(UI_window_width,UI_window_height);
// inicio del bucle de eventos
glutMouseFunc( clickRaton );
glutMotionFunc( ratonMovido );
glutMainLoop();
return 0;
}
