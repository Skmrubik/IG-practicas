libs:=   -L/usr/lib/x86_64-linux-gnu    -lGL -lGLU -lglut -ljpeg

all:p1

cubo.o: src/cubo.cpp include/cubo.h
	g++ -c src/cubo.cpp -o obj/cubo.o -Iinclude
tetra.o: src/tetra.cpp include/tetra.h
	g++ -c src/tetra.cpp -o obj/tetra.o -Iinclude
objeto3D.o: src/objeto3D.cpp include/objeto3D.h
	g++ -c src/objeto3D.cpp -o obj/objeto3D.o -Iinclude
ply.o: src/ply.cpp include/ply.h
	g++ -c src/ply.cpp -o obj/ply.o -Iinclude
luz.o: src/luz.cpp include/luz.h
	g++ -c src/luz.cpp -o obj/luz.o -Iinclude
pieza.o: src/pieza.cpp include/pieza.h
	g++ -c src/pieza.cpp -o obj/pieza.o -Iinclude
camara.o: src/camara.cpp include/camara.h
	g++ -c src/camara.cpp -o obj/camara.o -Iinclude
textura.o: src/textura.cpp include/textura.h
	g++ -c src/textura.cpp -o obj/textura.o -Iinclude
material.o: src/material.cpp include/material.h
	g++ -c src/material.cpp -o obj/material.o -Iinclude
RevolucionY.o: src/RevolucionY.cpp include/RevolucionY.h
	g++ -c src/RevolucionY.cpp -o obj/RevolucionY.o -Iinclude
file_ply_stl.o: src/file_ply_stl.cc include/file_ply_stl.h
	g++ -c src/file_ply_stl.cc -o obj/file_ply_stl.o -Iinclude
escena.o: src/escena.cpp include/escena.h
	g++ -c src/escena.cpp -o obj/escena.o -Iinclude
practica1.o: src/practica1.cpp
	g++ -c src/practica1.cpp -o obj/practica1.o -Iinclude
jpg_imagen.o: src/jpg_imagen.cpp include/jpg_imagen.hpp
	g++ -c src/jpg_imagen.cpp -o obj/jpg_imagen.o -Iinclude
jpg_readwrite.o: src/jpg_readwrite.cpp include/jpg_readwrite.hpp
	g++ -c src/jpg_readwrite.cpp -o obj/jpg_readwrite.o -Iinclude
jpg_memsrc.o: src/jpg_memsrc.cpp include/jpg_memsrc.hpp
	g++ -c src/jpg_memsrc.cpp -o obj/jpg_memsrc.o -Iinclude
p1: cubo.o tetra.o practica1.o luz.o material.o objeto3D.o textura.o pieza.o camara.o ply.o RevolucionY.o file_ply_stl.o  jpg_imagen.o jpg_readwrite.o jpg_memsrc.o  escena.o
	g++ obj/cubo.o obj/tetra.o obj/escena.o obj/material.o obj/textura.o obj/pieza.o obj/camara.o obj/objeto3D.o obj/ply.o obj/luz.o  obj/RevolucionY.o obj/file_ply_stl.o obj/jpg_imagen.o obj/jpg_readwrite.o  obj/jpg_memsrc.o -o bin/p1 obj/practica1.o  $(libs)
	./bin/p1
clean:	
	rm -rf obj/*.o bin/p1