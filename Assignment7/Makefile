program.exe: ApplicationProgram.o MapHT.o BankAccount.o
	g++ ApplicationProgram.o MapHT.o BankAccount.o -o program.exe

ApplicationProgram.o: ApplicationProgram.cpp
	g++ -g -Wall -c -std=c++11 ApplicationProgram.cpp

MapHT.o: MapHT.cpp MapHT.h
	g++ -g -Wall -c -std=c++11 MapHT.cpp

BankAccount.o: BankAccount.cpp BankAccount.h
	g++ -g -Wall -c -std=c++11 BankAccount.cpp

clean: 
	rm *.o program.exe 


