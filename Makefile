EXE	= main

all: project3

project3: project3.o GraphGenerator.o
	g++ -std=c++11 $^ -o $@

clean:
	rm -rf ${EXE}
	rm *.o
