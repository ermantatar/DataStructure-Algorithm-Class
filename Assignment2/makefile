PlayerTester.exe: PlayerTester.o player.o SimpleList.o
	g++ PlayerTester.o player.o SimpleList.o -o program.exe
PlayerTester.o: PlayerTester.cpp player.h SimpleList.h players.txt
	g++ -c PlayerTester.cpp 
player.o: player.cpp player.h
	g++ -c player.cpp
SimpleList.o: SimpleList.cpp SimpleList.h
	g++ -c SimpleList.cpp
clean: 
	rm *.o PlayerTester.exe
