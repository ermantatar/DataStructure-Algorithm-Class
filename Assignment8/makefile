program.exe: Program.o JobScheduler.o Job.o PQueue.o
	g++ Program.o JobScheduler.o Job.o PQueue.o -o program.exe

Program.o: Program.cpp
	g++ -g -c -std=c++11 Program.cpp

JobScheduler.o: JobScheduler.cpp JobScheduler.h
	g++ -g -c -std=c++11 JobScheduler.cpp

PQueue.o: PQueue.cpp PQueue.h
	g++ -g -c -std=c++11 PQueue.cpp

Job.o: Job.cpp Job.h
	g++ -g -c -std=c++11 Job.cpp

clean: 
	rm *.o program.exe 




