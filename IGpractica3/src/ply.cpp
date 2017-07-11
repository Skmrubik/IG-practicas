#include "ply.h"
#include "objeto3D.h"
#include "file_ply_stl.h"
Ply::Ply(char  *file){
//Creamos un objeto _file_ply
	_file_ply ply;
//Abrimos el fichero dado como parametro	
	ply.open(file);
//Almacenamos lo leido en los vectores de objeto3D
	ply.read(vertices, triangulos);
	for(int i=0; i<vertices.size(); i++){
		vertices[i]=vertices[i]*10;
	}
}

