#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

// check why it's printing the case number too. perhaps cause it's an integer?

int main(){

int getDayOfTheWeek = 0;

srand(time(0));
getDayOfTheWeek = (rand()%7) + 1; {

cout <<" what day does today feel like? Today feels like " << getDayOfTheWeek;

switch(getDayOfTheWeek) {
case 1:
  cout << "Sunday \n";
    break;
case 2:
  cout << "Monday \n";
    break;
case 3:
  cout << "Tuesday \n";
    break;
case 4:
  cout << "Wednesday \n";
    break;
case 5:
  cout << "Thursday \n";
    break;
case 6:
  cout << "Friday \n";
    break;
case 7:
  cout << "Saturday \n";
    break;
default: 
cout << "Invalid day \n";
 }
}
    return 0;
}