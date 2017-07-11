#include <GL/gl.h>
#include <GL/glut.h>
#include "objeto3D.h"

//Constructor vacio para la herencia
Objeto3D::Objeto3D(){
}

//Dibujar mediante glBegin
void Objeto3D::Dibujar(Objeto3D::Tipo tipo){
CambiarTipo(tipo);
glBegin(GL_TRIANGLES);
	for(int i=0; i<triangulos.size(); i++){
		//Para alternar los colores 										
		if(tipo == AJEDREZ){
			if(i%6 <3){
				glColor3f(1,0,0);
			}	
			else{
				glColor3f(0,0,0);
			}
		}
		//Guardamos el entero de triangulos[i] en una variable
		int veruno = triangulos[i];
		veruno= veruno*3;
		//Metemos los tres vertices del triangulo anterior en glVertex	
		glVertex3f(vertices[veruno],vertices[veruno+1],vertices[veruno+2]);
	}
glEnd();
}

//Dibujar mediante DrawElements
void Objeto3D::Dibujar2(Objeto3D::Tipo tipo){
	CambiarTipo(tipo);
	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer(3,GL_FLOAT,0, &vertices[0]) ;
	glDrawElements( GL_TRIANGLES, triangulos.size(),GL_UNSIGNED_INT, &triangulos[0]) ;
}
//Según el tipo que recibe implementa una llamada a la funcion glPolygonMode u otra
void Objeto3D::CambiarTipo(Objeto3D::Tipo tipo){
	if(tipo == SOLIDO || tipo == AJEDREZ){
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}	
	if(tipo == ALAMBRES){
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	if(tipo == VERTICES){
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
		glPointSize(4);
	}
}











