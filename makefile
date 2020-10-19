all: hello

hello: main.o test.o

main.o:
	g++ main.cpp -o prog

test.o:
	g++ ./test/test.cpp -o ./test/test