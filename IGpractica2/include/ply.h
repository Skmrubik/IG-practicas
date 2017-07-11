#ifndef _PLY
#define _PLY
#include "objeto3D.h"
#include "file_ply_stl.h"
class Ply : public Objeto3D{
public:
	Ply(char *file);
};
#endif
