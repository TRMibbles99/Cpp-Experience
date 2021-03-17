/*
Mary Price
Feb 12, 2020
Exercise 4.1: This gets the length of a pentagon between the center and the
vertex to calculate the area of that pentagon.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
  //Declaring variables
  double length;
  double side;
  double area;

  //Prompting user
  cout << "Enter the length of pentagon between center and a vertex: ";
  cin >> length;

  //Calculating the side length and the area of the pentagon
  side = 2*length*sin(M_PI/5);
  area = (5*pow(side, 2))/(4*tan(M_PI/5));

  //Displaying the area
  cout << "The area of the pentagon is " << area << endl;

  return 0;
}
