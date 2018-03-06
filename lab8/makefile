runTest: Set.o testSet.o
	g++ Set.o testSet.o -o runTest
Set.o: Set.cpp Set.h
	g++ -c Set.cpp
testSet.o: testSet.cpp Set.h
	g++ -c testSet.cpp
clean:
	rm *.o runTest
