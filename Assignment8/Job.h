#ifndef Job_h
#define Job_h
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <time.h>



using namespace std;


class Job{
    
public:
    
    
    Job();
    // default constructor
    
    Job(int strTime, int pri, string ID, int execution);
    //constructor with values
    
    friend bool operator<(const Job & jobObject, const Job & jobObject2);
    // friend method

    friend ostream& operator<<(ostream & out, Job & job);
    // friend method for display

    
    string getID();
    // input is none
    // output is ID as a string
    
    int getStartTime();
    // it will return job start time
    // input is none
    
    int getPriorty();
    // it will return job priority
    // input is none
    
    void setExecutionTime(int value);
    // it will decrease job execution time
    // side effect is class variable is changing
    // input is value to decrease the class variable
    
    int getExecutionTime();
    // it will job execution time
    // input is none
    
    int getFinishTime();
    // it will return job finish time
    
    void setFinishTime(int time);
    // side effect it will change class variable
    // input is time to set job when it finished
    
    int getWait();
    // it will return how many times job waited in the current job box
    
    void setWait(int t);
    // side effect is it will decrease class variable
    // it will add moment when job waits in currentJob box.
    
  
    
private:
    int jobStartTime;
    int priorty;
    int executionTime;
    string jobNumber;
    int jobFinishTime;
    int waitTime;
    
};



#endif /* Job_h */

