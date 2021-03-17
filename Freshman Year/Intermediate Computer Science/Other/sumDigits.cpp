/*
Mary Price
Jan 23rd
Adding the digits of a number between 0-1000
*/
#include <iostream>
using namespace std;

int main(){
  //Declaring Variables
  int number;

  //Getting number from user
  cout<<"Enter a number: ";
  cin>>number;

  //Adding the digits
  int thousands = number/1000;
  int hundreds = (number - (thousands*1000))/100;
  int tens = (number - ((thousands*1000)+(hundreds*100)))/10;
  int ones = (number - ((thousands*1000)+(hundreds*100)+(tens*10)));
  int adding = thousands+hundreds+tens+ones;

  //Displaying the sum of the digits
  cout<<"The sum is: "<<adding<<endl;
  return 0;
}
