#ifndef _TEXTURAS_H
#define _TEXTURAS_H
#include <GL/gl.h>
#include <GL/glut.h>
#include "jpg_imagen.hpp"
#include "jpg_jinclude.h"
using namespace std;
class Textura{
public:
GLuint id;
unsigned long tamx, tamy;
unsigned char *texels;
bool automatico;
jpg::Imagen *pimg = NULL;


Textura(unsigned long tx, unsigned long ty, unsigned char *t, bool automatico);
void Activar(GLuint id);

};
#endif
