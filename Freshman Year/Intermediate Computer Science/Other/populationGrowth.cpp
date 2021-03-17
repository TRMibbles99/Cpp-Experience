#include <iostream>
using namespace std;

int main(){
    int currentPop = 312032486;
    int seconds = 365 * 34 * 60 * 60;
    int birthsPerYear = seconds / 7.0;
    int deathsPerYear = seconds / 13.0;
    int immigrantsPerYear = seconds / 45.0;
    int peoplePerYear = birthsPerYear + immigrantsPerYear - deathsPerYear;
    int firstYear = currentPop + peoplePerYear;
    int secondYear = firstYear + peoplePerYear;
    int thirdYear = secondYear + peoplePerYear;
    int fourthYear = thirdYear + peoplePerYear;
    int fifthYear = fourthYear + peoplePerYear;

    cout<<seconds<<endl;
    cout<<birthsPerYear<<endl;
    cout<<deathsPerYear<<endl;
    cout<<immigrantsPerYear<<endl;
    cout<<firstYear<<endl;

    return 0;
}
