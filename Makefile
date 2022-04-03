CC=g++ 

CFLAGS=-c 

all: tree

tree: main.o AkinatorFunctions.o
	$(CC) main.o AkinatorFunctions.o -o tree

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp  -o main.o

AkinatorFunctions.o: AkinatorFunctions.cpp
	$(CC) $(CFLAGS) AkinatorFunctions.cpp  -o AkinatorFunctions.o

clean: 
	rm -rf *.o tree