libs:=       -lGL -lGLU -lglut

all:p1

cubo.o: src/cubo.cpp include/cubo.h
	g++ -c  src/cubo.cpp -o obj/cubo.o -Iinclude
tetra.o: src/tetra.cpp include/tetra.h
	g++ -c  src/tetra.cpp -o obj/tetra.o -Iinclude
objeto3D.o: src/objeto3D.cpp include/objeto3D.h
	g++ -c  src/objeto3D.cpp -o obj/objeto3D.o -Iinclude
ply.o: src/ply.cpp include/ply.h
	g++ -c src/ply.cpp -o obj/ply.o -Iinclude
RevolucionY.o: src/RevolucionY.cpp include/RevolucionY.h
	g++ -c src/RevolucionY.cpp -o obj/RevolucionY.o -Iinclude
file_ply_stl.o: src/file_ply_stl.cc include/file_ply_stl.h
	g++ -c src/file_ply_stl.cc -o obj/file_ply_stl.o -Iinclude
escena.o: src/escena.cpp include/escena.h
	g++ -c  src/escena.cpp -o obj/escena.o -Iinclude
practica1.o: src/practica1.cpp
	g++ -c  src/practica1.cpp -o obj/practica1.o -Iinclude
p1: cubo.o tetra.o objeto3D.o ply.o RevolucionY.o file_ply_stl.o escena.o practica1.o 
	g++ obj/cubo.o obj/tetra.o obj/escena.o obj/objeto3D.o obj/ply.o  obj/RevolucionY.o obj/file_ply_stl.o -o bin/p1 obj/practica1.o  $(libs)
	./bin/p1
clean:
	rm -rf obj/*.o bin/p1
