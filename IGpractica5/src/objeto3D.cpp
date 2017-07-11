#include <GL/gl.h>
#include <GL/glut.h>
#include "objeto3D.h"
#include <iostream>
#include <material.h>
using namespace std;

jpg::Imagen *pimg2 = new jpg::Imagen("Texturas/text-lata-1.jpg");
	unsigned int tamx2 = pimg2->tamX(); 
	unsigned int tamy2 = pimg2->tamY(); 
	unsigned char *texels2 = pimg2->leerPixels();
	
	jpg::Imagen *pimg = new jpg::Imagen("Texturas/text-madera.jpg");
	unsigned int tamx = pimg->tamX(); 
	unsigned int tamy = pimg->tamY(); 
	unsigned char *texels = pimg->leerPixels();

//Constructor vacio para la herencia
Objeto3D::Objeto3D(){
}
//Dibujar mediante glBegin
void Objeto3D::Dibujar(Objeto3D::Tipo tipo){
int contador=0;
glShadeModel(GL_SMOOTH);
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
		// cout << "textura " << textura.size() << endl;
		// cout << "vertices " << vertices.size() << endl;
		// cout << "normales " << normalVer.size() << endl;
		//Guardamos el entero de triangulos[i] en una variable
		int veruno = triangulos[i];
		veruno= veruno*3;
		//Metemos los tres vertices del triangulo anterior en glVertex
		if(textura.size()>0 ){
			glTexCoord2f( textura[contador], textura[contador+1]);
			contador+=2;
		}
		glNormal3f(normalVer[veruno], normalVer[veruno+1], normalVer[veruno+2]);
		glVertex3f(vertices[veruno],vertices[veruno+1],vertices[veruno+2]);
	}
glEnd();

}

//Dibujar mediante DrawElements
void Objeto3D::Dibujar2(Objeto3D::Tipo tipo){
	CambiarTipo(tipo);

	glEnableClientState( GL_NORMAL_ARRAY ); // habilitar uso de array de normales
 	glNormalPointer( GL_FLOAT, 0, &normalVer[0]); 

	glEnableClientState( GL_VERTEX_ARRAY );
	glVertexPointer(3,GL_FLOAT,0, &vertices[0]) ;
	glDrawElements( GL_TRIANGLES, triangulos.size(),GL_UNSIGNED_INT, &triangulos[0]) ;
}
//Meter las normales de caras y de vertices
void Objeto3D::AsignarNormales(){
//NORMALES DE LAS CARAS

// Primero tenemos que seleccionar una cara y con sus tres vertices conseguir dos vectores
// Por ej, u=b-a, v=c-a (siendo a,b,c los vertices del triangulo)
// Y despues hacer el producto vectorial de UxV
int a,b,c;
float a0, a1, a2, b0, b1, b2, c0, c1, c2;
float U[3], V[3], M[3];
float modulo;
for(int i=0; i<triangulos.size();i+=3){
	a=triangulos[i];
	b=triangulos[i+1];
	c=triangulos[i+2];
	//Las coordenadas de cada uno de los vertices del triangulo almacenadas en variables diferentes para mayor claridad
	a0=vertices[(3*a)+0];
	a1=vertices[(3*a)+1];
	a2=vertices[(3*a)+2];
	b0=vertices[(3*b)+0];
	b1=vertices[(3*b)+1];
	b2=vertices[(3*b)+2];
	c0=vertices[(3*c)+0];
	c1=vertices[(3*c)+1];
	c2=vertices[(3*c)+2];
	//Los vertices donde se almacenará los vectores dados para realizar el producto vectorial.
	V[0]=b0-a0;
	V[1]=b1-a1;
	V[2]=b2-a2;
	U[0]=c0-a0;
	U[1]=c1-a1;
	U[2]=c2-a2;

	
	//Realizamos el producto vectorial
	M[0]=(U[1]*V[2])-(U[2]*V[1]);
	M[1]=(U[2]*V[0])-(U[0]*V[2]);
	M[2]=(U[0]*V[1])-(U[1]*V[0]);
	
	//Y lo hacemos unitario
	 // modulo = sqrt((M[0]*M[0])+(M[1]*M[1])+(M[2]*M[2]))*1.0;
	 // M[0]=M[0]/modulo;
	 // M[1]=M[1]/modulo;
	 // M[2]=M[2]/modulo;
	//Y lo incluimos en el vector de normales
	normalCara.push_back(M[0]);
	normalCara.push_back(M[1]);
	normalCara.push_back(M[2]);
}
//---------------------------------------------------------------------------------------------------

//NORMALES DE LOS VERTICES

//Hay que recorrer todas las caras y ver cuales son adyacentes a cada vertice
//Estas caras las almacenaremos en un vector dinamico y despues tendremos que sumar las normales de estas caras
//Al final, hay que hacerlo unitario de nuevo
vector <int> caras;
float res[3];
float modulo2;
for(int i=0; i<(vertices.size()/3);i++){
	caras.clear();
	for(int b=0; b<3;b++){
		res[b]=0;
	}
	//Buscar las caras 
	for(int j=0; j<triangulos.size(); j++){
		if(triangulos[j]==i){
			//Almacenar j/3, que sería el numero de esa cara
			caras.push_back(j/3);
		}
	}
	//Ya tenemos en el vector caras todas las caras adyacentes al vertice i
	//Ahora hay que sumarlas
	for(int a=0; a<caras.size(); a++){
		res[0]=res[0]+normalCara[(caras[a]*3)+0];
		res[1]=res[1]+normalCara[(caras[a]*3)+1];
		res[2]=res[2]+normalCara[(caras[a]*3)+2];
	}
	//Por ultino, hay que hacerlo unitario
	// modulo2 = sqrt((res[0]*res[0])+(res[1]*res[1])+(res[2]*res[2]));
	// res[0]=res[0]/modulo2;
	// res[1]=res[1]/modulo2;
	// res[2]=res[2]/modulo2;
	//Lo almacenamos en las normales de los vertices
	normalVer.push_back(res[0]);
	normalVer.push_back(res[1]);
	normalVer.push_back(res[2]);

}
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
	if(tipo == SUAVE){
		glShadeModel(GL_SMOOTH);
	}
	if(tipo == PLANO){
		glShadeModel(GL_FLAT);
	}
}











