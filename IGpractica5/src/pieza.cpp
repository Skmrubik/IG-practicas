#include "pieza.h"
Pieza::Pieza(int iden, int col){
	id=iden;
	color=col;
}
void Pieza::calcularCentro(vector<float> ver){
	float xmax, xmin, ymax, ymin, zmax, zmin;
	xmax=-100000;
	xmin=100000;
	ymax=-100000;
	ymin=100000;
	zmax=-100000;
	zmin=100000;
	//recorremos las x
	for(int i=0; i<ver.size();i+=3){
		if(ver[i]<xmin)
			xmin=ver[i];
		if(ver[i]>xmax)
			xmax=ver[i];
	}
	//recorremos las y
	for(int i=1; i<ver.size();i+=3){
		if(ver[i]<ymin)
			ymin=ver[i];
		if(ver[i]>ymax)
			ymax=ver[i];
	}
	//recorremos las z
	for(int i=2; i<ver.size();i+=3){
		if(ver[i]<zmin)
			zmin=ver[i];
		if(ver[i]>zmax)
			zmax=ver[i];
	}
	float a,b,c;
	a=(xmax+xmin)/2;
	b=(ymax+ymin)/2;
	c=(zmax+zmin)/2;
	centro[0]=a;
	centro[1]=b;
	centro[2]=c;
}
void Pieza::trasladar(float a, float b, float c){
	centro[0]+=a;
	centro[1]+=b;
	centro[2]+=c;
}