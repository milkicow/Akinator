CC=g++ 

CFLAGS=-c 

all: tree

tree: main.o TreeFunctions.o
	$(CC) main.o TreeFunctions.o -o tree

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp  -o main.o

TreeFunctions.o: TreeFunctions.cpp
	$(CC) $(CFLAGS) TreeFunctions.cpp  -o TreeFunctions.o

clean: 
	rm -rf *.o tree