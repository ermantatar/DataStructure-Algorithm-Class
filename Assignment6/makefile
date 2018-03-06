runTest: Set.o tester.o
	g++ Set.o tester.o -o runTest
Set.o: Set.cpp Set.h
	g++ -c Set.cpp
tester.o: tester.cpp Set.h
	g++ -c tester.cpp
clean:
	rm *.o runTest

