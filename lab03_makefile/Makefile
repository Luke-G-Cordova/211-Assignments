
foobar: main.o foo.o bar.o
	g++ -Wall -pedantic -o foobar main.o foo.o bar.o
	
main.o: main.cpp
	g++ -Wall -pedantic -g -std=c++11 -c main.cpp

foo.o: foo.h foo.cpp 
	g++ -Wall -pedantic -g -std=c++11 -c foo.cpp

bar.o: bar.h bar.cpp 
	g++ -Wall -pedantic -g -std=c++11 -c bar.cpp
	
clean:
	rm -f foobar foobar.exe main.o foo.o bar.o



	