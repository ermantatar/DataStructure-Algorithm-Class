test.exe: tester.o 
	g++ tester.o -o test.exe
	
tester.o: tester.cpp 
	g++ -c -std=c++11 tester.cpp 
	
clean: 
	rm *.o test.exe result.txt


