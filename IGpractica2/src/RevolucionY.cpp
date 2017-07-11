#include "RevolucionY.h"
#include "objeto3D.h"
#include "file_ply_stl.h"
#include <math.h>

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
float altMax= vertices[tamVer-2];
float altMin= vertices[1];

//Y ahora calculo el resto de vertices por rotacion
for(i=0; i<=lados;i++){
	for(j=0; j<tamVer;j+=3){
		vertices.push_back((vertices[j]*(cos(rot*(i+1))) + vertices[(j+2)]*(sin(rot*(i+1))))*tam);
		vertices.push_back((vertices[j+1])*tam);
		vertices.push_back((vertices[j]*(-sin(rot*(i+1))) + vertices[(j+2)]*(cos(rot*(i+1))))*tam);
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
}
