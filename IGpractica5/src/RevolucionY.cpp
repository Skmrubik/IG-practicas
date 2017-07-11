#include "RevolucionY.h"
#include "objeto3D.h"
#include "file_ply_stl.h"
#include <math.h>
#include <iostream>
using namespace std;

RevolucionY::RevolucionY(int lados,float tam, char* file){
//Creamos un objeto _file_ply
	_file_ply ply;
//Abrimos el fichero dado como parametro	
	ply.open(file);
//Almacenamos lo leido en los vectores 
	ply.read(vertices, triangulos);

float grados=360/lados;
float rot= (grados*3.14)/180;
int i,j;
int tamVer= vertices.size();
//Coordenada Y más alta
float altMax= vertices[tamVer-2];
//Coordenada Y más baja
float altMin= vertices[1];
vector <float> aux;
for(int i=0; i<vertices.size(); i++){
	aux.push_back(vertices[i]);
}
vertices.clear();
//Y ahora calculo el resto de vertices por rotacion
for(i=0; i<=lados+1;i++){
	for(j=0; j<tamVer;j+=3){
		vertices.push_back((aux[j]*(cos(rot*(i+1))) + aux[(j+2)]*(sin(rot*(i+1))))*tam);
		vertices.push_back((aux[j+1])*tam);
		vertices.push_back((aux[j]*(-sin(rot*(i+1))) + aux[(j+2)]*(cos(rot*(i+1))))*tam);

		}
	}

//Borro los triangulos que ya venian en el archivo PLY
triangulos.clear();
//Y creo los triangulos verdaderos
for(i=1; i<=lados;i++){
	for(j=0; j<((tamVer/3)-1);j++){
		triangulos.push_back(j+(i*(tamVer/3)));
		triangulos.push_back(j+1+(i*(tamVer/3)));
		triangulos.push_back(j+(tamVer/3)+(i*(tamVer/3)));

		triangulos.push_back(j+1+(i*(tamVer/3)));
		triangulos.push_back(j+1+(tamVer/3)+(i*(tamVer/3)));
		triangulos.push_back(j+(tamVer/3)+(i*(tamVer/3)));
		}
	}	
//Tapas de abajo
int alturaMax=vertices[(3*tamVer)-2];
vertices.push_back(0);
vertices.push_back(altMin*tam);
vertices.push_back(0);
j=0;
for(i=0; i<=lados;i++){
	triangulos.push_back(j+(i*((tamVer-1)/3)));
	triangulos.push_back(j+(tamVer/3)+(i*((tamVer-1)/3)));
	triangulos.push_back((vertices.size()/3)-1);
j++;
}

 //Tapa de arriba
 vertices.push_back(0);
 vertices.push_back(altMax*tam);
 vertices.push_back(0);
 j=0;
 for(i=0; i<=lados;i++){
 	triangulos.push_back(j+(i*((tamVer-1)/3))+((tamVer/3)-1));
 	triangulos.push_back((vertices.size()/3)-1);
 	triangulos.push_back(j+(tamVer/3)+(i*((tamVer-1)/3))+((tamVer/3)-1));
 	
	 j++;
  }

AsignarNormales();

textura.clear();
for(int i=0; i<lados+1; i++){
	for(int j=0; j<tamVer/3; j++){
		float n=lados*1.0;
		float auxI=i*1.0;
		
		textura.push_back(auxI/n-1);
		float m=(tamVer/3)*1.0;
		float auxJ=j*1.0;
		textura.push_back(auxJ/m-1);
	}
}

}
