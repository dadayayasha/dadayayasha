SOURCE = main.cpp
HEASERS = ../lab12/headers/*.h *.h

all: lab_test
	./main

lab_test:
	g++ $(SOURCE) -o main

leak:
	leaks -atExit -- ./main
#valgrind --tool=memcheck --leak-check=yes  ./test

clang:
	clang-format -i *.cpp $(SOURCE) $(HEASERS) 
#alt shift fs
clean:
	rm main
	rm test.bin test.txt
	clear
