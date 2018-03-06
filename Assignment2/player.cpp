
#include "player.h"
#include <iostream>
#include <cassert>
#include <string>
#include <cstdlib>

using namespace std;


TennisPlayer::TennisPlayer(){
    firstName = "Margaret";
    lastName = "Iwobi";
    country = "America";
    ranking = 5;
    pointTotal = 100;
}

TennisPlayer::TennisPlayer(string myfirstName, string mylastName, int myranking, int mypointTotal, string mycountry){
    firstName = myfirstName;
    lastName = mylastName;
    ranking = myranking;
    pointTotal = mypointTotal;
    country = mycountry;
}

string TennisPlayer::getFirstName(){
    return firstName;
    
}

string TennisPlayer::getLastName(){
    return lastName;
}

string TennisPlayer::getCountry(){
    return country;
}
int TennisPlayer::getRanking(){
    return ranking;
}
int TennisPlayer::getpointTotal(){
    return pointTotal;
}
void TennisPlayer::setRanking(int myranking){
    ranking = myranking;
}
void TennisPlayer::setPoint(int mypointTotal){
    pointTotal = mypointTotal;
}

ostream & operator<< (ostream & out, const TennisPlayer & t){
    out<< t.firstName << " "<< t.lastName <<" "<< t.country <<" "<< t.ranking <<" "<< t.pointTotal << endl;
    return out;
}



