CC = g++
all: test
test: test.o
	${CC} -o test test.o
test.o: test.cpp
	${CC} -c test.cpp -o test.o
clear:
	rm test.o test.cpp

