#ifndef LUZ_H
#define LUZ_H
#include <GL/gl.h>
#include <GL/glut.h>
//#include <iostream>
//using namespace std;

class Luz{
public:
	float color0[3];
	float color1[3];
	bool direccional0;
	bool direccional1;
	float posicion0[4];
	float posicion1[4];
	float direccion0[3];
	float direccion1[3];
	float ambiente0[4];
	float difusa0[4];
	float ambiente1[4];
	float difusa1[4];
	float especular0[4];
	float especular1[4];

	void activarLuz0();
	void activarLuz1();
};
#endif