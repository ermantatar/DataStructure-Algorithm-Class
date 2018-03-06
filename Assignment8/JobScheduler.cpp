#include "Job.h"
#include "JobScheduler.h"
#include "PQueue.h"
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <algorithm>



using namespace std;


JobScheduler::JobScheduler(){
    
    timeSlice = 2;              // prof. gave 2 as a default value.
    time = 0;
    completedJobs=NULL;
    currentJob = NULL;
}

JobScheduler::JobScheduler(int timeSlices, queue<ItemType>queue){

    timeSlice = timeSlices;
    jobsQueue = queue;
    completedJobs=NULL;
    currentJob = NULL;
    time = 0;
    
}


void JobScheduler::setCurrentJob(Job& curJob){
    currentJob = &curJob;
}

Job JobScheduler::getCurrentJob(){
    return *currentJob;
}

Job JobScheduler::getCompletedJobs(){
    return *completedJobs;
}

void JobScheduler::setCompletedJobs(Job & newJob){
    completedJobs = &newJob;
}



vector<Job>& JobScheduler::workSystem(vector<Job> & completedJobsvector){
    

    int currentJobCounter = 0;
    
    
    int systemLimit = jobsQueue.size();
    
        
   
    
    
    


    while(completedJobsvector.size() != systemLimit && time != 30){
    
        if(jobsQueue.size() != 0){
            
            if(time == jobsQueue.front()->getStartTime()){
            
                if( currentJobCounter == 0 && currentJob ==NULL){
                
                    currentJob = jobsQueue.front();
                    jobsQueue.pop();
                    
                    display(cout);
                    completedJobs = NULL;
                    
                    currentJob->setExecutionTime(-1);
                    currentJob->setWait(+1);
                    currentJobCounter++;
                    
                    if(currentJob->getExecutionTime() == 0){
    
                        currentJob->setFinishTime(time);
                        completedJobsvector.push_back(*currentJob);
                        completedJobs = currentJob;
                        currentJob = NULL;
                        currentJobCounter=0;
                    
                    }
                
                }
                else if(currentJobCounter < timeSlice && currentJob != NULL){
                
                    waitingList.enqueue(jobsQueue.front());
                    jobsQueue.pop();
                    
                    display(cout);
                    completedJobs = NULL;
                    
                    currentJob->setExecutionTime(-1);
                    currentJob->setWait(+1);
                    currentJobCounter++;
                    
                    if(currentJob->getExecutionTime() == 0){
                        
                        currentJob->setFinishTime(time);
                        completedJobsvector.push_back(*currentJob);
                        completedJobs = currentJob;
                        currentJob = NULL;
                        currentJobCounter=0;
                        
                    }

                    
                
                }
                else if(currentJobCounter == timeSlice){
                
                    waitingList.enqueue(currentJob);
                    currentJobCounter = 0;
                    
                    currentJob = jobsQueue.front();
                    jobsQueue.pop();
                    
                    display(cout);
                    completedJobs = NULL;
                    
                    currentJob->setExecutionTime(-1);
                    currentJob->setWait(+1);
                    currentJobCounter++;
                    
                    if(currentJob->getExecutionTime() == 0){
                        
                        currentJob->setFinishTime(time);
                        completedJobsvector.push_back(*currentJob);
                        completedJobs = currentJob;
                        currentJob = NULL;
                        currentJobCounter=0;
                        
                    }
                
                
                }
            
                
                
            }
            //////////////// time match yok
            else{
            
                if(currentJobCounter == 0 && currentJob == NULL && waitingList.size() == 0){
                    
                    display(cout);
                    completedJobs = NULL;
                }
                else if(currentJobCounter ==0 && currentJob == NULL && waitingList.size() != 0){
                
                    currentJob = waitingList.front();
                    waitingList.dequeue();
                    
                    display(cout);
                    completedJobs = NULL;
                    
                    currentJob->setExecutionTime(-1);
                    currentJob->setWait(+1);
                    currentJobCounter++;
                    
                    if(currentJob->getExecutionTime() == 0){
                        
                        currentJob->setFinishTime(time);
                        completedJobsvector.push_back(*currentJob);
                        completedJobs = currentJob;
                        currentJob = NULL;
                        currentJobCounter=0;
                        
                    }

                
                }else if(currentJobCounter < timeSlice && currentJob != NULL){
                
                    display(cout);
                    completedJobs = NULL;
                    
                    currentJob->setExecutionTime(-1);
                    currentJob->setWait(+1);
                    currentJobCounter++;
                    
                    if(currentJob->getExecutionTime() == 0){
                        
                        currentJob->setFinishTime(time);
                        completedJobsvector.push_back(*currentJob);
                        completedJobs = currentJob;
                        currentJob = NULL;
                        currentJobCounter=0;
                        
                    }

                
                
                }else if( currentJobCounter == timeSlice && waitingList.size() == 0){    //// ****** /////
                    
                    if(currentJob->getExecutionTime() <= 0){
                        
                        currentJob->setFinishTime(time);
                        completedJobsvector.push_back(*currentJob);
                        completedJobs = currentJob;
                        currentJob = NULL;
                        currentJobCounter=0;
                    }
                    
                    
                    
                    currentJob->setExecutionTime(-1);
                    currentJob->setWait(+1);
                    currentJobCounter=timeSlice;
                    
                    if(currentJob->getExecutionTime() <= 0){
                        
                        currentJob->setFinishTime(time);
                        completedJobsvector.push_back(*currentJob);
                        completedJobs = currentJob;
                        currentJob = NULL;
                        currentJobCounter=0;
                    }

                    
                    display(cout);
                    completedJobs = NULL;
                    
                    
                    
                    
                    
                }
                
                
                else if(currentJobCounter == timeSlice){
                
                    if(currentJob->getExecutionTime() == 0){
                        
                        currentJob->setFinishTime(time);
                        completedJobsvector.push_back(*currentJob);
                        completedJobs = currentJob;
                        currentJob = NULL;
                        currentJobCounter=0;
                        display(cout);
                        
                    }else{
                    
                        if(currentJob->getPriorty() <= waitingList.front()->getPriorty()){
                            
                            
                            swap(waitingList.front(), currentJob);
                            currentJobCounter = 0;
                            
                            
                        }else{
                            
                            waitingList.enqueue(currentJob);
                            currentJob =NULL;
                            currentJobCounter=0;
                        
                            currentJob = waitingList.front();
                            waitingList.dequeue();
                        
                        }
                        
                        display(cout);
                        completedJobs = NULL;
                        
                        currentJob->setExecutionTime(-1);
                        currentJob->setWait(+1);
                        currentJobCounter++;
                        
                        if(currentJob->getExecutionTime() == 0){
                            
                            currentJob->setFinishTime(time);
                            completedJobsvector.push_back(*currentJob);
                            completedJobs = currentJob;
                            currentJob = NULL;
                            currentJobCounter=0;
                            
                        }

                        
                        
                    
                    }
                    
                    

                    
                
                
                }
            
            
            
            
            
            
            
            
            
            }
            
        
        
        
        }
        
        // jobQueue icindeki joblar bitti //////////////////
        
        else{
        
            
            if(currentJobCounter == 0 && currentJob == NULL && waitingList.size() == 0){
                
                display(cout);
                completedJobs = NULL;
            }
            
            else if(currentJobCounter ==0 && currentJob == NULL && waitingList.size() != 0){
                
                currentJob = waitingList.front();
                waitingList.dequeue();
                
                display(cout);
                completedJobs = NULL;
                
                currentJob->setExecutionTime(-1);
                currentJob->setWait(+1);
                currentJobCounter++;
                
                if(currentJob->getExecutionTime() == 0){
                    
                    currentJob->setFinishTime(time);
                    completedJobsvector.push_back(*currentJob);
                    completedJobs = currentJob;
                    currentJob = NULL;
                    currentJobCounter=0;
                    
                }
                
                
            }
            else if(currentJobCounter < timeSlice && currentJob != NULL){
                
                display(cout);
                completedJobs = NULL;
                
                currentJob->setExecutionTime(-1);
                currentJob->setWait(+1);
                currentJobCounter++;
                
                if(currentJob->getExecutionTime() == 0){
                    
                    currentJob->setFinishTime(time);
                    completedJobsvector.push_back(*currentJob);
                    completedJobs = currentJob;
                    currentJob = NULL;
                    currentJobCounter=0;
                    
                }
                
                
                
            }
            else if(currentJobCounter == timeSlice && waitingList.size() != 0){
                
                if(currentJob->getExecutionTime() == 0){
                    
                    currentJob->setFinishTime(time);
                    completedJobsvector.push_back(*currentJob);
                    completedJobs = currentJob;
                    currentJob = NULL;
                    currentJobCounter=0;
                    display(cout);
                    
                }else{
                    
                    if(currentJob->getPriorty() <= waitingList.front()->getPriorty()){
                        
                        swap(currentJob, waitingList.front());
                        currentJobCounter = 0;
                        
                        
                    }else{
                        waitingList.enqueue(currentJob);
                        currentJobCounter=0;
                        
                        currentJob = waitingList.front();
                        waitingList.dequeue();
                        
                    }
                    
                    display(cout);
                    completedJobs = NULL;
                    
                    currentJob->setExecutionTime(-1);
                    currentJob->setWait(+1);
                    currentJobCounter++;
                    
                    if(currentJob->getExecutionTime() == 0){
                        
                        currentJob->setFinishTime(time);
                        completedJobsvector.push_back(*currentJob);
                        completedJobs = currentJob;
                        currentJob = NULL;
                        currentJobCounter=0;
                        
                    }
                    
                    
                    
                    
                }
                
                
                
                
                
                
            }
            else if(time >= timeSlice && waitingList.size() ==0 ){
            
                if(currentJob->getExecutionTime() == 0){
                    
                    currentJob->setFinishTime(time);
                    completedJobsvector.push_back(*currentJob);
                    completedJobs = currentJob;
                    currentJob = NULL;
                    
                    
                }else{
                    
                    currentJob->setExecutionTime(-1);
                    currentJob->setWait(1);
                    currentJobCounter = timeSlice;
                    
                    if(currentJob->getExecutionTime() == 0){
                        
                        currentJob->setFinishTime(time);
                        completedJobsvector.push_back(*currentJob);
                        completedJobs = currentJob;
                        currentJob = NULL;
                        currentJobCounter=0;
                        
                    }

                    
                    
                    display(cout);
                    completedJobs = NULL;
                    
                   
                    
                    
                
                }
            
            
            
            
            }
            
            
            
        
        
        
        }
    
    
    
    
    
        time++;
    }
    
    
    
    
    return completedJobsvector;
    
    

}

ostream& JobScheduler::display(ostream & out){
    if (completedJobs==NULL && currentJob != NULL) {
        out << time <<"         "<<" "<<"           "<< currentJob->getID()<<"           "<< waitingList.size() << endl;
        return out;
        
    }else if (completedJobs != NULL && currentJob == NULL){
    
        out << time <<"         "<<completedJobs->getID()<<"           "<< " "<<"           "<< waitingList.size() << endl;
        return out;
    }
    else if(completedJobs == NULL && currentJob == NULL){
    
        out << time <<"         "<<"           "<<"           "<< "            "<<"           "<< waitingList.size() << endl;
        return out;
    }else{
        out << time <<"         "<<completedJobs->getID()<<"           "<< currentJob->getID()<<"           "<< waitingList.size()<<endl;
        return out;
    }
}



ostream& operator<<(ostream & out, const JobScheduler & scheduler){
    out <<"  "<< scheduler.time <<"            " << *scheduler.completedJobs <<"                "<< *scheduler.currentJob<<"         "<< scheduler.waitingList.size() <<endl;
    return out;
    
}



