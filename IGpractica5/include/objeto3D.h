#ifndef OBJETO3D
#define OBJETO3D
#include <vector>
#include <math.h>
#include <textura.h>
using namespace std;

class Objeto3D{
public:
	//Enumerado para el tipo en el que queremos dibujar
	enum Tipo {SOLIDO, ALAMBRES, AJEDREZ, VERTICES, SUAVE, PLANO};
	
	//Vectores para almacenar las coordenadas de los triangulos y de los vertices
	vector<float> vertices;
	vector<int> triangulos;
	vector<float> normalVer;
	vector<float> normalCara;
	vector<float> aux;
	vector<float> textura;
	Textura *madera,*lata;
	
	Objeto3D();
	void Dibujar(Tipo tipo);
	void Dibujar2(Tipo tipo);
	void AsignarNormales();
	void CambiarTipo(Tipo tipo);
};
#endif


