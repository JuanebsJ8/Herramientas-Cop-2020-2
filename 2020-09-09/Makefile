all: datos.txt
sumas.x: Sumas.cpp
	g++ Sumas.cpp -o sumas.x
datos.txt: sumas.x
	./sumas.x > datos.txt
