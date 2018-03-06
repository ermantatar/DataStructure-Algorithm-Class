program.exe: tester.o Stack.o Queue.o
	g++ tester.o Stack.o Queue.o -o program.exe

tester.o: tester.cpp
	g++ -c -std=c++11 tester.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c -std=c++11 Stack.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c -std=c++11 Queue.cpp

clean: 
	rm *.o program.exe Result.txt


