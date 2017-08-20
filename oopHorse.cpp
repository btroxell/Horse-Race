#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
using namespace std;

// you create a horse class, which
class Horse{
private:
    int position;
public:
    Horse();
    void advance();
    int getPosition();


};//end horse class

Horse::Horse(){
    srand(time(NULL));
    position = 0;
}//end horse constructor

// give horse a 50 50 chance to advance
void Horse::advance(){
    int advanceChance = rand() % 2;
    if (advanceChance == 1){
        position++;
    }//end if
}//end advance prototype

int Horse::getPosition(){
    return position;
}//end get position prototype


class Race{
private:
//you are creating 5 instances of the horse class
//the horses are the objects in the arrays
   Horse horse[5];
public:
    Race();
    Race(int);
    int length;
    void printLane(int);
    void start();

}; //end class Race

//initialize default value for length
Race::Race(){
    length = 25;
} //end constructor


Race::Race(int length){
    Race::length = length;
}//end overloaded constructor

//create a lane for each horse
//horsenum is what is being passed into the printlane function
//the horses are the horsenum
void Race::printLane(int horseNum){
    //counter variable i
    int i;
    //counts through the length of 25
    for (i=0; i<length; i++){
        //each horse gets a position
        //comparing the position to the length, whatever the position is
        if (horse[horseNum].getPosition() == i){
        //print the horse if the position is equal to the counter i
            cout << horseNum;
        }//end if statement
        //if not print a . to make the track
        else{
            cout << ".";
        }//end else
    }//end for loop
    cout << endl;
}//end print lane

void Race::start(){
    bool keepgoing = true;
    int j;
    int horseWin;
    int a;
    cout << "Welcome to the Horse Race" << endl;
    //shows the horses advancing and when a horse wins

    //while keepgoing
    //passes keepgoing as an argument to be used to determine when the race ends
    while(keepgoing){
        cout << "Press Enter for another turn" << endl;
        cin.ignore();
        //make a lane for each horse, and get show its advances
        for (j=0; j<5; j++){
            printLane(j);
            if (horse[j].getPosition() == length - 1){
                horseWin = j;
                keepgoing = false;
            }//end if
        }//end for lane for loop
            //
            for (a=0; a<5; a++){
                horse[a].advance();

            }//end advance for loop
    }//end while loop
        cout << "The winning horse is: " << horseWin << "!";
}//end race start method

int main(){
    Race race;
    race.length = 30;
    race.start();
}
