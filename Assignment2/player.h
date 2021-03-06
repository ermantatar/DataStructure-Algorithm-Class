#ifndef TENNISPLAYER
#define TENNISPLAYER

#include <iostream>
#include <string>
using namespace std;

class TennisPlayer{
    
public:
    TennisPlayer();
    TennisPlayer(string firstName, string lastName, int ranking, int pointTotal, string country);
				
    string getFirstName();
    string getLastName();
    string getCountry();
    int getRanking();
    int getpointTotal();
    void setRanking(int ranking);
    void setPoint(int point);
    
    friend ostream & operator<<(ostream & out, const TennisPlayer & t);
    
    
private:
    string firstName;
    string lastName;
    int ranking;
    int pointTotal;
    string country;
};


#endif


