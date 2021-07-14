#Makefile
all: Byte-Order

Byte-Order: ordering.o
	g++ -o ordering ordering.o

ordering.o: ordering.cpp

clean:
	rm -f Byte-Order
	rm -f *.o
