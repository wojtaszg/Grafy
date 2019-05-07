__start__: a.out
	./a.out

a.out: main.o grafy.o
	g++ main.o grafy.o

main.o: main.cpp grafy.hh
	g++ -c -Wall -pedantic main.cpp

grafy.o: grafy.hh grafy.cpp
	g++ -c -Wall -pedantic grafy.cpp

