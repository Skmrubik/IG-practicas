#ifndef OBJETO3D
#define OBJETO3D
#include <vector>
using namespace std;

class Objeto3D{
public:
	//Enumerado para el tipo en el que queremos dibujar
	enum Tipo {SOLIDO, ALAMBRES, AJEDREZ, VERTICES};
	
	//Vectores para almacenar las coordenadas de los triangulos y de los vertices
	vector<float> vertices;
	vector<int> triangulos;
	
	Objeto3D();
	void Dibujar(Tipo tipo);
	void Dibujar2(Tipo tipo);
	void CambiarTipo(Tipo tipo);
};
#endif


