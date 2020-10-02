all: fig.pdf

sumas.x: Sumas.cpp
	g++ Sumas.cpp -o sumas.x

datos.txt: sumas.x
	./sumas.x > datos.txt

fig.pdf: plot.py datos.txt
	python3 plot.py
clean:
	rm -f a.out sumas.x datos.txt
