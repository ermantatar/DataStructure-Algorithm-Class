#include "JobScheduler.h"
#include "Job.h"
#include "PQueue.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <queue>

void readFile(queue<ItemType> & jTable);
//it will read the file that includes all jobs and installing them into a standart library queue.
// sideeffect is changing amount of vecor and changing class variable, creating class object.


void displayBeforeSystem();
// it is for first line of program. time completed job , current job and queue size
// sideeffect is printing on the screen

void displayInfo(vector<Job> completedJobsTable);
// it will display all information about the jobscheduler object
// sideeffect is printing on the screen
void cleanLeaks(queue<ItemType> jobsQueue);
// it will clean queue items because they are staying in heap memory.

int main(){

    
    queue<ItemType> jobsQueue; // all jobs are in this job table.
    
    
    readFile(jobsQueue);
    
    JobScheduler scheduler(2,jobsQueue); //new JobScheduler(0, NULL, NULL, )
    
    
    displayBeforeSystem();
    
    vector<Job> completedJobsvector;
    
    vector<Job> completedJobsTable = scheduler.workSystem(completedJobsvector);
    
    displayInfo(completedJobsTable);
    
    cleanLeaks(jobsQueue);
   
    
}

void readFile(queue<ItemType> & jTable){

    
    string filename;
    string line;
   

    
    cout<< " Please give me your job list file " << endl;
    cin >> filename;
    
    
    ifstream myfile;
    
    myfile.open(filename.c_str());
    
    if(myfile.is_open()){
        
        
        string jStr;
        string jPri;
        string jnumber;
    
        while(getline(myfile,line)){
        
            istringstream iss(line);
                       do{
                iss>>jStr;
                iss>>jPri;
                iss>>jnumber;
            
            }while(iss);
            
            int js = atoi(jStr.c_str());
            int jp = atoi(jPri.c_str());
            
            
            jTable.push(new Job(js, jp, jnumber, (rand()%5 + 1) ));
            
        
        }
    
    
    
    
    
    }else{
        cout<< "Computer cannot find the file ! " << endl;
    }
    
}



void displayBeforeSystem(){

    cout<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"TIME_"<<"_COMPLETED JOBS_"<<"_CURRENT JOB_"<<"_WAITING JOBS"<<endl;

}


void displayInfo(vector<Job> completedJobsTable){

    cout<<endl;
    cout<< "Number of Jobs to be end : " << completedJobsTable.size() << endl;
    
    double AverageSpendingTime= 0;
    int longestTime = 0;
    
    for(int i = 0; i< completedJobsTable.size(); i++){
    
        AverageSpendingTime +=  completedJobsTable[i].getWait();
    
    }
    
    AverageSpendingTime = AverageSpendingTime / (double)completedJobsTable.size();
    
    longestTime = completedJobsTable[0].getWait();
    
    for (int i = 1; i< completedJobsTable.size(); i++) {
        
        if(completedJobsTable[i].getWait() >= longestTime ){
            longestTime = completedJobsTable[i].getWait();
        }
        
    }
    
    cout<< "Average Time Waiting is " << AverageSpendingTime << endl;
    cout<< "Longest Time Waiting is " << longestTime << endl;
    
    
    
    
    


}

void cleanLeaks(queue<ItemType>jobsQueue){
	while(jobsQueue.size() != 0){
		delete jobsQueue.front();
		jobsQueue.pop();
	}

}
