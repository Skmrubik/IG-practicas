#include <material.h>
Material::Material(){
}
void Material::peonNegro(){
color[0]=1;
color[1]=0;
color[2]=0;
color[3]=1;

ambiente[0]=1;
ambiente[1]=0;
ambiente[2]=0;
ambiente[3]=1;

difuso[0]=0.8;
difuso[1]=0.8;
difuso[2]=0.8;
difuso[3]=1;

specular[0]=0.5;
specular[1]=0.5;
specular[2]=0.5;
specular[3]=0.5;


//glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION, color) ;
 glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT, ambiente ) ;
// glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE, difuso ) ;
// glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR, specular ) ;
// glMaterialf( GL_FRONT_AND_BACK, GL_SHININESS, 0 ) ;

}