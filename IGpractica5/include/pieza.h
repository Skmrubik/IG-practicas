#ifndef _PIEZA_H
#define _PIEZA_H

#include <vector>
using namespace std;

class Pieza{
public:
	float centro[3];
	int id;
	int color;

	Pieza(int iden, int col);
	void calcularCentro(vector<float> ver);
	void trasladar(float a, float b, float c);
};
#endif