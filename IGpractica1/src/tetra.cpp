#include "tetra.h"

//Constructor
Tetra::Tetra(){
	//VÉRTICES
vertices.push_back(0);         		vertices.push_back(50);      	vertices.push_back(0);
vertices.push_back(0);         		vertices.push_back(-50*0.5); 	vertices.push_back(50);
vertices.push_back(-50*0.866); 	vertices.push_back(-50*0.5); 	vertices.push_back(-50*0.5);
vertices.push_back(50*0.866);  	vertices.push_back(-50*0.5); 	vertices.push_back(-50*0.5);

	//TRIÁNGULOS
triangulos.push_back(0); 	triangulos.push_back(2); 	triangulos.push_back(1);
triangulos.push_back(0); 	triangulos.push_back(3); 	triangulos.push_back(2);
triangulos.push_back(0); 	triangulos.push_back(1); 	triangulos.push_back(3);
triangulos.push_back(1); 	triangulos.push_back(2); 	triangulos.push_back(3);

}


