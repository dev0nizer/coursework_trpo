all: hello

hello: main.o test.o

main.o:
	g++ -std=c++11 main.cpp -o prog

test.o:
	g++ -std=c++11 ./tests/tests.cpp -o ./tests/tests
	
test:
	./tests/tests.exe
	
run:
	./prog.exe