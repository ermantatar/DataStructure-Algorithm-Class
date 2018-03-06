testSL: tester.o SimpleListL.o 
	g++ tester.o SimpleListL.o -o testSL
	
tester.o: tester.cpp
	g++ -c -std=c++11 tester.cpp
	
SimpleListL.o: SimpleListL.cpp SimpleListL.h
	g++ -c -std=c++11 SimpleListL.cpp
		
clean: 
	rm *.o testSL
