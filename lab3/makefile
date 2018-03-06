testSLD.exe: tester.o SimpleListD.o
	g++ tester.o SimpleListD.o -o testSLD.exe
	
tester.o: tester.cpp
	g++ -c -std=c++11 tester.cpp
	
SimpleList.o: SimpleListD.cpp SimpleListD.h
	g++ -c -std=c++11 SimpleListD.cpp
	
clean: 
	rm *.o testSLD.exe

