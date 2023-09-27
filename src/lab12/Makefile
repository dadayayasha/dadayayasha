SOURCE = source/*.cpp
HEASERS = headers/*.h

all: lab_test
	./test

lab_test:
	g++ test.cpp $(SOURCE) -o test

leak:
	valgrind --tool=memcheck --leak-check=yes  ./test

clang:
	clang-format -i *.cpp $(SOURCE) $(HEASERS) 

clean:
	rm test
	clear
