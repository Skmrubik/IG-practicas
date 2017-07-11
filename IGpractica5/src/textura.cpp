#include "textura.h"
Textura::Textura(unsigned long tx, unsigned long ty, unsigned char *t, bool au){
glGenTextures(1, &id);
tamx = tx;
tamy = ty;
texels = t;
automatico=au;
}
void Textura::Activar(GLuint id){
	if(automatico){
	glEnable( GL_TEXTURE_2D);
	glEnable( GL_TEXTURE_GEN_S ); // desactivado inicialmente
	glEnable( GL_TEXTURE_GEN_T );
	glTexGeni( GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR ) ;
	glTexGeni( GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR ) ;

	//glGenTextures(1, &idTexMadera);
	//glBindTexture(GL_TEXTURE_2D,idTexMadera); 
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tamx, tamy, 0, GL_RGB, GL_UNSIGNED_BYTE, texels);
	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tamx, tamy, 0, GL_RGB, GL_UNSIGNED_BYTE, texels);


	}
	else{
	glEnable( GL_TEXTURE_2D);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tamx, tamy, 0, GL_RGB, GL_UNSIGNED_BYTE, texels);
	}
}
