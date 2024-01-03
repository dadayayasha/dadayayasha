SOURCE = *.cpp
HEASERS = *.h

all: lab_test
	./kursach

lab_test:
	g++ $(SOURCE) -o kursach

leak:
	leaks -atExit -- ./kursach
#valgrind --tool=memcheck --leak-check=yes  ./test

clang:
	clang-format -i $(SOURCE) $(HEASERS) 
#alt shift fs
clean:
	rm kursach
	rm kursach.bin
	clear
