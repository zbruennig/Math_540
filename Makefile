Gauss: main.o GaussianInteger.o
	g++ -std=c++11 -g -Wall main.o GaussianInteger.o -o Gauss
	
main.o: main.cpp GaussianInteger.h
	g++ -std=c++11 -g -Wall -c main.cpp
	
GaussianInteger.o: GaussianInteger.h GaussianInteger.cpp
	g++ -std=c++11 -g -Wall -c GaussianInteger.cpp
	
clean:
	rm *.o Gauss
