#ifndef _CAMARA_H
#define _CAMARA_H
#include <iostream>

class Camara{
public:
	float eye[3];
	float up[3];
	float at[3];
	bool perspectiva;
	int idem;
	bool examinar;
	int pixel;

	Camara(float e[], float u[], float a[], bool p, int id);
	void Mover1Persona(char letra);
	void girar(char giro, float angulo);
	void sumarAt(float a, float b, float c);
	void sumarEye(float a, float b, float c);
};
#endif