/*
Mary Price
Feb 5th, 2020
Exercise 3.14: taking user ented lottery number and showing how much money they
would have earned from random lottery number.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
  //This will make random work
  srand(time(0));

  //Declaring variables
  int userNum;
  int userDig1;
  int userDig2;
  int userDig3;
  int lotNum1;
  int lotNum2;
  int lotNum3;
  int fullLot;
  int counter = 0;
  int testNum1 = 0;
  int testNum2 = 0;
  int testNum3 = 0;

  //Promping user
  cout << "Enter your lottery pick (three digits): ";
  cin >> userNum;

  //Getting random lottery numbers
  lotNum1 = rand() % 10;
  lotNum2 = rand() % 10;
  lotNum3 = rand() % 10;

  //Testing if user number is exact as lottery number, will end program if true
  fullLot = (lotNum1 * 100) + (lotNum2 * 10) + lotNum3;
  if (userNum == fullLot){
    cout << "Match three digits in order: you win $10,000" << endl;
    return 0;
  }

  //Getting the individual digits of user number entered
  userDig1 = userNum / 100;
  userDig2 = (userNum - (userDig1*100)) / 10;
  userDig3 = userNum - ((userDig1*100) + (userDig2*10));

  //Comparing digits of user number to digits in lottery number
  if (userDig1 == lotNum1){
    testNum1 = 1;
    counter++;
  } else if (userDig2 == lotNum1){
    testNum2 = 1;
    counter++;
  } else if (userDig3 == lotNum1){
    testNum2 = 1;
    counter++;
  }

  if (userDig1 == lotNum2 && testNum1 == 0) {
    testNum1 = 1;
    counter++;
  } else if (userDig2 == lotNum2 && testNum2 == 0){
    testNum2 = 1;
    counter++;
  } else if (userDig3 == lotNum2 && testNum3 == 0){
    testNum3 = 1;
    counter++;
  }

  if (userDig1 == lotNum3 && testNum1 == 0){
    counter++;
  } else if (userDig2 == lotNum3 && testNum2 == 0){
    counter++;
  } else if (userDig1 == lotNum3 && testNum3 == 0){
    counter++;
  }

  //Displaying what user got based on how many of user number digits matched
  if (counter == 1){
    cout << "Match one digit: you win $1,000" << endl;
  } else if (counter == 3){
    cout << "Match three digits: you win $3,000" << endl;
  } else {
    cout << "Sorry, you did not win anything" << endl;
  }

  return 0;
}
