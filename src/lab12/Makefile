SOURCE = source/*.cpp
HEASERS = headers/*.h

all: lab_test
	./test

lab_test:
	g++ test.cpp $(SOURCE) -o test

leak:
	leaks -atExit -- ./test
#valgrind --tool=memcheck --leak-check=yes  ./test

clang:
	clang-format -i *.cpp $(SOURCE) $(HEASERS) 
#alt shift fs
clean:
	rm test
	rm test.bin test.txt
	clear
