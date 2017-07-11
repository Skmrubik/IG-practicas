#include "cubo.h"

//Constructor
Cubo::Cubo(){	
//VÉRTICES
vertices.push_back(50);  vertices.push_back(50);  vertices.push_back(50);
vertices.push_back(50);  vertices.push_back(50);  vertices.push_back(-50);
vertices.push_back(50);  vertices.push_back(-50); vertices.push_back(50);
vertices.push_back(50);  vertices.push_back(-50); vertices.push_back(-50);
vertices.push_back(-50); vertices.push_back(50);  vertices.push_back(50);
vertices.push_back(-50); vertices.push_back(50);  vertices.push_back(-50);
vertices.push_back(-50); vertices.push_back(-50); vertices.push_back(50);
vertices.push_back(-50); vertices.push_back(-50); vertices.push_back(-50);

//TRIÁNGULOS
triangulos.push_back(1); triangulos.push_back(0); triangulos.push_back(3);
triangulos.push_back(0); triangulos.push_back(2); triangulos.push_back(3);
triangulos.push_back(4); triangulos.push_back(1); triangulos.push_back(5);
triangulos.push_back(4); triangulos.push_back(0); triangulos.push_back(1);
triangulos.push_back(5); triangulos.push_back(3); triangulos.push_back(7);
triangulos.push_back(5); triangulos.push_back(1); triangulos.push_back(3);
triangulos.push_back(4); triangulos.push_back(7); triangulos.push_back(6);
triangulos.push_back(4); triangulos.push_back(5); triangulos.push_back(7);
triangulos.push_back(0); triangulos.push_back(4); triangulos.push_back(2);
triangulos.push_back(2); triangulos.push_back(4); triangulos.push_back(6);
triangulos.push_back(2); triangulos.push_back(6); triangulos.push_back(3);
triangulos.push_back(6); triangulos.push_back(7); triangulos.push_back(3);
}


