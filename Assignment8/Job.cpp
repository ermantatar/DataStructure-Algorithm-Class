#include "Job.h"
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <time.h>



using namespace std;


Job::Job(){
    
    jobStartTime = 0;
    priorty = 0;
    executionTime = 0;
    jobNumber = " ";
    jobFinishTime = 0;
    waitTime =0;
    


}

Job::Job(int strTime, int pri, string ID, int execution){
    
    jobStartTime= strTime;
    priorty=pri;
    executionTime= execution;
    jobNumber= ID;
    jobFinishTime = 0;
    waitTime = 0;
    
}

int Job::getWait(){
    return waitTime;
}
void Job::setWait(int t){
    waitTime += t;
}

string Job::getID(){
    return jobNumber;
}

int Job::getPriorty(){
    return priorty;
};

int Job::getStartTime(){
    return jobStartTime;
}

int Job::getExecutionTime(){
    return executionTime;
}

void Job::setExecutionTime(int value){
    executionTime += value;
}


int Job::getFinishTime(){
    return jobFinishTime;
}

void Job::setFinishTime(int time){
    jobFinishTime = time;
}




bool operator<(const Job & jobObject, const Job & jobObject2){
    
    if(jobObject.priorty < jobObject2.priorty){
        return true;
    }else
        return false;
}

ostream& operator<<(ostream & out, Job & job){
    out << "starttime : " << job.jobStartTime <<"   " << "priority : "<< job.priorty <<"        "<<"ID : "<<job.jobNumber <<"      "<<"Execution : " << job.executionTime <<endl;
    return out;
    
}

