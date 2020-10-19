all: hello

hello: main.o test.o

main.o:
	g++ main.cpp -o prog

test.o:
	g++ ./tests/tests.cpp -o ./tests/tests
	
test:
	./tests/tests.exe
	
run:
	./prog.exe