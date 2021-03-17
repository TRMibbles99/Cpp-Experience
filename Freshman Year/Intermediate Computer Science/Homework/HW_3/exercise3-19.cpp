/*
Mary Price
Feb 5th, 2020
Exercise 3.19: Figures out if a user entered coordinate is inside of a circle
that has a radius of 10.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
  //Declaring variables
  double x;
  double y;
  double distance;

  //Prompting user
  cout << "Enter a point with two coordinates: ";
  cin >> x >> y;

  //Calculating the distance of the point from the origin
  distance = sqrt(pow(x, 2) + pow(y, 2));

  //Determines if distance is under 10
  if (distance <= 10.0){
    cout << "Point (" << x << ", " << y << ") is in the circle" << endl;
  } else {
    cout << "Point (" << x << ", " << y << ") is not in the circle" << endl;
  }

  return 0;
}
