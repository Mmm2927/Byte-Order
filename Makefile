#Makefile
all: add-nbo

add-nbo: ordering.o
	g++ -o ordering ordering.o

ordering.o: ordering.cpp

clean:
	rm -f add-nbo
	rm -f *.o
