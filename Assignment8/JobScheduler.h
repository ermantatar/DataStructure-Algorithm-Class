#ifndef JobScheduler_h
#define JobScheduler_h

#include "PQueue.h"
#include "Job.h"

#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

typedef Job* ItemType;

class JobScheduler{

public:
    JobScheduler();
    // constructor
    
    JobScheduler(int timeSlices, queue<ItemType>queue);
    // Job scheduler will start timeSlice option and queue that holds all job read from jobs.txt
    
    int getCurrentTime();
    // it will return current time of Job scheduler
    
    void setCurrentTime(int i);
    // it will change current time
    // side effect is it decrease class variable
    
    Job getCompletedJobs();
    // it will return completed job, s plural is wrong it will keep one job.
    void setCompletedJobs(Job & newJob);
    // it will assing a job to completedjobs box to show which job ended.
    // side effect is changing class variable.
    
    Job getCurrentJob();
    // it will return current job.
    
    void setCurrentJob(Job & curJob);
    // it will change currentJob box.
    // side effect is class variable is changing
    
    vector<Job>& workSystem(vector<Job>& completedJobsvector);
    // it is making all jobs of jobscheduler, It controls system mechanism.
    // input is vector to keep which jobs are ended.
    // sideeffect is printing on screen, changing class variables.
    
    ostream& display(ostream & out);
    // it is display method to show each time slot in a moment orderly
    // sideeffect is displaying on the screen
    
    friend ostream& operator<<(ostream & out, const JobScheduler & scheduler);
    // friend method to prinf class object on the screen
    // sideeffects are displaying monitor.
    
private:
    
    int timeSlice;
    int time;
    Job *completedJobs;
    Job *currentJob;
    PQueue waitingList;
    queue<ItemType> jobsQueue;

    
    



};




#endif /* JobScheduler_h */

