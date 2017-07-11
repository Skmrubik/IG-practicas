#include <iostream>
#include <camara.h>
#include <math.h>

	Camara::Camara(float e[], float u[], float a[], bool p, int id){
		eye[0]=e[0];
		eye[1]=e[1];
		eye[2]=e[2];
		up[0]=u[0];
		up[1]=u[1];
		up[2]=u[2];
		at[0]=a[0];
		at[1]=a[1];
		at[2]=a[2];
		perspectiva=p;
		idem=id;
		examinar=false;
	}
	void Camara::Mover1Persona(char letra){
		if(examinar==false){
		if(idem==0){
			if(letra=='a'){
				eye[0]-=10; 
				at[0]-=10;
			}	
			if(letra=='d'){
				eye[0]+=10;	
				at[0]+=10;
			}
			if(letra=='w'){
				eye[2]-=10; 
				at[2]-=10;
			}
			if(letra=='s'){	
				eye[2]+=10;	
				at[2]+=10;
			}
		}
		if(idem==1){
			if(letra=='a'){
				eye[0]-=10; 
				at[0]-=10;
			}	
			if(letra=='d'){
				eye[0]+=10;	
				at[0]+=10;
			}
			if(letra=='w'){
				eye[1]-=10; 
				at[1]-=10;
			}
			if(letra=='s'){	
				eye[1]+=10;	
				at[1]+=10;
			}
		}
		if(idem==2){
			if(letra=='a'){
				eye[2]+=10; 
				at[2]+=10;
			}	
			if(letra=='d'){
				eye[2]-=10;	
				at[2]-=10;
			}
			if(letra=='w'){
				eye[0]-=10; 
				at[0]-=10;
			}
			if(letra=='s'){	
				eye[0]+=10;	
				at[0]+=10;
			}
		}
	}

	}
	void Camara::sumarAt(float a, float b, float c){
		at[0]+=a;
		at[1]+=b;
		at[2]+=c;
	}
	void Camara::sumarEye(float a, float b, float c){
		eye[0]+=a;
		eye[1]+=b;
		eye[2]+=c;
	}
	void Camara::girar(char giro, float ang){
	if (examinar==false){
		float rot= 2*3.1416;
		if(idem==0){
			if(giro=='a'){
				//posicionar at en (0,0,0)
				sumarAt(-eye[0],-eye[1],-eye[2]);
				//rotarlo hacia la izq 
				at[0]=at[0]*(cos(ang)) + at[2]*(sin(ang));
				at[2]=at[0]*(-sin(ang)) + at[2]*(cos(ang));
				//devolverlo
				sumarAt(eye[0],eye[1],eye[2]);
			}
			if(giro=='d'){
				//posicionar at en (0,0,0)
				sumarAt(-eye[0],-eye[1],-eye[2]);
				//rotarlo hacia la der 
				at[0]=at[0]*(cos(rot-ang)) + at[2]*(sin(rot-ang));
				at[2]=at[0]*(-sin(rot-ang)) + at[2]*(cos(rot-ang));
				//devolverlo
				sumarAt(eye[0],eye[1],eye[2]);
			}
			if(giro=='w'){
				//posicionar at en (0,0,0)
				sumarAt(-eye[0],-eye[1],-eye[2]);
				//rotarlo hacia arriba 
				at[1]=at[1]*(cos(ang)) + at[2]*(-sin(ang));
				at[2]=at[1]*(sin(ang)) + at[2]*(cos(ang));
				//devolverlo
				sumarAt(eye[0],eye[1],eye[2]);
			}
			if(giro=='s'){
				//posicionar at en (0,0,0)
				sumarAt(-eye[0],-eye[1],-eye[2]);
				//rotarlo hacia abajo 
				at[1]=at[1]*(cos(rot-ang)) + at[2]*(-sin(rot-ang));
				at[2]=at[1]*(sin(rot-ang)) + at[2]*(cos(rot-ang));
				//devolverlo 
				sumarAt(eye[0],eye[1],eye[2]);
			}
		}
		if(idem==1){
			if(giro=='a'){
				//posicionar at en (0,0,0)
				sumarAt(-eye[0],-eye[1],-eye[2]);
				//rotarlo hacia la izq 
				at[0]=at[0]*(cos(rot-ang)) + at[1]*(-sin(rot-ang));
				at[1]=at[0]*(sin(rot-ang)) + at[1]*(cos(rot-ang));
				
				//devolverlo
				sumarAt(eye[0],eye[1],eye[2]);
			}
			if(giro=='d'){
				//posicionar at en (0,0,0)
				sumarAt(-eye[0],-eye[1],-eye[2]);
				//rotarlo hacia la der 
				at[0]=at[0]*(cos(ang)) + at[1]*(-sin(ang));
				at[1]=at[0]*(sin(ang)) + at[1]*(cos(ang));
				//devolverlo
				sumarAt(eye[0],eye[1],eye[2]);
			}
			if(giro=='w'){
				//posicionar at en (0,0,0)
				sumarAt(-eye[0],-eye[1],-eye[2]);
				//rotarlo hacia arriba 
				at[1]=at[1]*(cos(ang)) + at[2]*(-sin(ang));
				at[2]=at[1]*(sin(ang)) + at[2]*(cos(ang));
				//devolverlo
				sumarAt(eye[0],eye[1],eye[2]);
			}
			if(giro=='s'){
				//posicionar at en (0,0,0)
				sumarAt(-eye[0],-eye[1],-eye[2]);
				//rotarlo hacia abajo 
				at[1]=at[1]*(cos(rot-ang)) + at[2]*(-sin(rot-ang));
				at[2]=at[1]*(sin(rot-ang)) + at[2]*(cos(rot-ang));
				 //devolverlo
				sumarAt(eye[0],eye[1],eye[2]);
			}
		}
		if(idem==2){
			if(giro=='a'){
				//posicionar at en (0,0,0)
				sumarAt(-eye[0],-eye[1],-eye[2]);
				//rotarlo hacia la izq 
				at[0]=at[0]*(cos(ang)) + at[2]*(sin(ang));
				at[2]=at[0]*(-sin(ang)) + at[2]*(cos(ang));
				//devolverlo
				sumarAt(eye[0],eye[1],eye[2]);
			}
			if(giro=='d'){
				//posicionar at en (0,0,0)
				sumarAt(-eye[0],-eye[1],-eye[2]);
				//rotarlo hacia la der 
				at[0]=at[0]*(cos(rot-ang)) + at[2]*(sin(rot-ang));
				at[2]=at[0]*(-sin(rot-ang)) + at[2]*(cos(rot-ang));
				//devolverlo
				sumarAt(eye[0],eye[1],eye[2]);
			}
			if(giro=='w'){
				//posicionar at en (0,0,0)
				sumarAt(-eye[0],-eye[1],-eye[2]);
				//rotarlo hacia arriba 				
				at[0]=at[0]*(cos(rot-ang)) + at[1]*(-sin(rot-ang));
				at[1]=at[0]*(sin(rot-ang)) + at[1]*(cos(rot-ang));
				//devolverlo
				sumarAt(eye[0],eye[1],eye[2]);
			}
			if(giro=='s'){
				//posicionar at en (0,0,0)
				sumarAt(-eye[0],-eye[1],-eye[2]);
				//rotarlo hacia abajo 
				at[0]=at[0]*(cos(ang)) + at[1]*(-sin(ang));
				at[1]=at[0]*(sin(ang)) + at[1]*(cos(ang));
				 //devolverlo
				sumarAt(eye[0],eye[1],eye[2]);
			}
		}
	}
	else{
		float rot= 2*3.1416;
		if(idem==0){
			if(giro=='a'){
				//posicionar at en (0,0,0)
				sumarEye(-at[0],-at[1],-at[2]);
				//rotarlo hacia la izq 
				eye[0]=eye[0]*(cos(rot-ang)) + eye[2]*(sin(rot-ang));
				eye[2]=eye[0]*(-sin(rot-ang)) + eye[2]*(cos(rot-ang));
				//devolverlo
				sumarEye(at[0],at[1],at[2]);
			}
			if(giro=='d'){
				//posicionar at en (0,0,0)
				sumarEye(-at[0],-at[1],-at[2]);
				//rotarlo hacia la der 
				eye[0]=eye[0]*(cos(ang)) + eye[2]*(sin(ang));
				eye[2]=eye[0]*(-sin(ang)) + eye[2]*(cos(ang));
				//devolverlo
				sumarEye(at[0],at[1],at[2]);
			}
			if(giro=='w'){
				//posicionar at en (0,0,0)
				sumarEye(-at[0],-at[1],-at[2]);
				//rotarlo hacia arriba 				
				eye[1]=eye[1]*(cos(rot-ang)) + eye[2]*(-sin(rot-ang));
				eye[2]=eye[1]*(sin(rot-ang)) + eye[2]*(cos(rot-ang));
				//devolverlo
				sumarEye(at[0],at[1],at[2]);
			}
			if(giro=='s'){
				//posicionar at en (0,0,0)
				sumarEye(-at[0],-at[1],-at[2]);
				//rotarlo hacia abajo 
				eye[1]=eye[1]*(cos(ang)) + eye[2]*(-sin(ang));
				eye[2]=eye[1]*(sin(ang)) + eye[2]*(cos(ang));
				//devolverlo 
				sumarEye(at[0],at[1],at[2]);
			}
		}
		if(idem==1){
			if(giro=='a'){
				//posicionar at en (0,0,0)
				sumarEye(-at[0],-at[1],-at[2]);
				//rotarlo hacia la izq 
				eye[0]=eye[0]*(cos(ang)) + eye[1]*(-sin(ang));
				eye[1]=eye[0]*(sin(ang)) + eye[1]*(cos(ang));
				
				
				//devolverlo
				sumarEye(at[0],at[1],at[2]);
			}
			if(giro=='d'){
				//posicionar at en (0,0,0)
				sumarEye(-at[0],-at[1],-at[2]);
				//rotarlo hacia la der 
				eye[0]=eye[0]*(cos(rot-ang)) + eye[1]*(-sin(rot-ang));
				eye[1]=eye[0]*(sin(rot-ang)) + eye[1]*(cos(rot-ang));
				//devolverlo
				sumarEye(at[0],at[1],at[2]);
			}
			if(giro=='w'){
				//posicionar at en (0,0,0)
				sumarEye(-at[0],-at[1],-at[2]);
				//rotarlo hacia arriba 
				eye[1]=eye[1]*(cos(ang)) + eye[2]*(-sin(ang));
				eye[2]=eye[1]*(sin(ang)) + eye[2]*(cos(ang));
				//devolverlo
				sumarEye(at[0],at[1],at[2]);
			}
			if(giro=='s'){
				//posicionar at en (0,0,0)
				sumarEye(-at[0],-at[1],-at[2]);
				//rotarlo hacia abajo 
				eye[1]=eye[1]*(cos(rot-ang)) + eye[2]*(-sin(rot-ang));
				eye[2]=eye[1]*(sin(rot-ang)) + eye[2]*(cos(rot-ang));
				 //devolverlo
				sumarEye(at[0],at[1],at[2]);
			}
		}
		if(idem==2){
			if(giro=='a'){
				//posicionar at en (0,0,0)
				sumarEye(-at[0],-at[1],-at[2]);
				//rotarlo hacia la izq 
				eye[0]=eye[0]*(cos(ang)) + eye[2]*(sin(ang));
				eye[2]=eye[0]*(-sin(ang)) + eye[2]*(cos(ang));
				//devolverlo
				sumarEye(at[0],at[1],at[2]);
			}
			if(giro=='d'){
				//posicionar at en (0,0,0)
				sumarEye(-at[0],-at[1],-at[2]);
				//rotarlo hacia la der 
				eye[0]=eye[0]*(cos(rot-ang)) + eye[2]*(sin(rot-ang));
				eye[2]=eye[0]*(-sin(rot-ang)) + eye[2]*(cos(rot-ang));
				//devolverlo
				sumarEye(at[0],at[1],at[2]);
			}
			if(giro=='w'){
				//posicionar at en (0,0,0)
				sumarEye(-at[0],-at[1],-at[2]);
				//rotarlo hacia arriba 				
				eye[0]=eye[0]*(cos(rot-ang)) + eye[1]*(-sin(rot-ang));
				eye[1]=eye[0]*(sin(rot-ang)) + eye[1]*(cos(rot-ang));
				//devolverlo
				sumarEye(at[0],at[1],at[2]);
			}
			if(giro=='s'){
				//posicionar at en (0,0,0)
				sumarEye(-at[0],-at[1],-at[2]);
				//rotarlo hacia abajo 
				eye[0]=eye[0]*(cos(ang)) + eye[1]*(-sin(ang));
				eye[1]=eye[0]*(sin(ang)) + eye[1]*(cos(ang));
				 //devolverlo
				sumarEye(at[0],at[1],at[2]);
			}
		}
	}
	}

