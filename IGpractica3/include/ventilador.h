#ifndef _VENTILADOR_H
#define _VENTILADOR_H
#include "cubo.h"
#include "tetra.h"
#include "ply.h"
#include "RevolucionY.h"
#include "objeto3D.h"

class Ventilador {
public:
	RevolucionY *cilindro;
	RevolucionY *glo;
	Objeto3D::Tipo tipo; 
	Tetra *tetra;
	Cubo *cubo;

	Ventilador();
	void base(Objeto3D::Tipo tipo);
	void cuerpo(Objeto3D::Tipo tipo, float movGlobo);
	void ala(Objeto3D::Tipo tipo);
	void globo(Objeto3D::Tipo tipo);
	void alas(Objeto3D::Tipo tipo);
	void draw(int alt, int gra, float gra2, float movGlobo, Objeto3D::Tipo tipo);
};
#endif
