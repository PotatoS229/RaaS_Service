CC = g++
all: ./src/main

./src/main: ./src/main.o
	${CC} -o ./src/main ./src/main.o

./src/main.o: ./src/main.cpp
	${CC} -c ./src/main.cpp -o ./src/main.o

clean:
	rm -f ./src/main ./src/main.o

.PHONY: all clean