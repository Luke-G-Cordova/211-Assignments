hello: hello.o
	g++ -Wall -pedantic -g -o hello hello.o
hello.o:hello.cpp
	g++ -Wall -pedantic -g -std=c++11 -c hello.cpp
clean:
	rm -f hello hello.o