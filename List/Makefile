CC=g++ 

CFLAGS=-c 

all: list

list: main.o ListCircFunctions.o
	$(CC) main.o ListCircFunctions.o -o list

main.o: main.cpp 
	$(CC) $(CFLAGS) main.cpp  -o main.o

ListCircFunctions.o: ListCircFunctions.cpp
	$(CC) $(CFLAGS) ListCircFunctions.cpp  -o ListCircFunctions.o

clean: 
	rm -rf *.o list