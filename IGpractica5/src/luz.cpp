#include <luz.h>

void Luz::activarLuz0(){
	posicion0[0]=100000;
	posicion0[1]=-1000;
	posicion0[2]=-10000;
	posicion0[3]=0;

	ambiente0[0]=0;
	ambiente0[1]=0;
	ambiente0[2]=1;
	ambiente0[3]=1;

	difusa0[0]=0.5;
	difusa0[1]=0.5;
	difusa0[2]=0.5;
	difusa0[3]=0.5;

	especular0[0]=1 ;
	especular0[1]= 1;
	especular0[2]= 1;
	especular0[3]= 1;
	glLightfv (GL_LIGHT0, GL_AMBIENT, ambiente0);
	glLightfv( GL_LIGHT0, GL_POSITION, posicion0 );
	glLightfv (GL_LIGHT0, GL_DIFFUSE, difusa0);

	glEnable (GL_LIGHTING);
	glEnable(GL_LIGHT0);
}
void Luz::activarLuz1(){
	posicion1[0]=10000;
	posicion1[1]=10000;
	posicion1[2]=100;
	posicion1[3]=0;

	ambiente1[0]=0;
	ambiente1[1]=1;
	ambiente1[2]=0;
	ambiente1[3]=1;

	difusa1[0]=0.5;
	difusa1[1]=0.5;
	difusa1[2]=0.5;
	difusa1[3]=0.5;

	especular1[0]=1 ;
	especular1[1]= 1;
	especular1[2]= 1;
	especular1[3]= 1;
	glLightfv (GL_LIGHT1, GL_AMBIENT, ambiente1);
	glLightfv( GL_LIGHT1, GL_POSITION, posicion1 );
	glLightfv (GL_LIGHT1, GL_DIFFUSE, difusa1);

	glEnable (GL_LIGHTING);
	glEnable(GL_LIGHT1);
}
