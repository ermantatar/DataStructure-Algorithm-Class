lab7.exe: tester.o BankAccount.o
	g++ tester.o BankAccount.o -o lab7.exe
	
tester.o: tester.cpp BankAccount.h
	g++ -c -std=c++11 tester.cpp 
	
BankAccount.o: BankAccount.cpp BankAccount.h
	g++ -c -std=c++11 BankAccount.cpp
	
clean: 
	rm *.o lab7.exe

