main: main.o maquina.o
	g++ main.o maquina.o -o main

teste: maquina.o maquina_teste.o
	g++ maquina.o maquina_teste.o -o teste

main.o: main.cpp
	g++ -c main.cpp

maquina.o: maquina.h maquina.cpp
	g++ -std=c++17 -c maquina.cpp

maquina_teste.o: maquina_teste.cpp doctest.h
	g++ -c maquina_teste.cpp

clean:
	rm *.o main