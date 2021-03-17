/*
Mary Price
Feb 5th, 2020
Exercise 2.13
*/
#include <iostream>
using namespace std;

int main(){
  //Declaring variables
  double monthlySavings;
  double currentSavings = 0;
  const double INTEREST_RATE = 0.00417;

  //Prompting user
  cout << "Enter monthly saving amount: ";
  cin >> monthlySavings;

  //Accumulating savings after 6 months
  for (int months = 1 ; months <= 6 ; months++){
    currentSavings = (monthlySavings + currentSavings) * (1 + INTEREST_RATE);
    cout << currentSavings << endl;
  }

  //Outputting savings
  cout << "Savings after 6 months: " << currentSavings << endl;

  return 0;
}
