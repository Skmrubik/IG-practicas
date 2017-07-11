#ifndef _MATERIAL
#define _MATERIAL
#include <GL/gl.h>
#include <GL/glut.h>
using namespace std;

class Material{
public:
	float color[4];
	float difuso[4];
	float specular[4];
	float ambiente[4];

	Material();
	void  peonNegro();
};
#endif