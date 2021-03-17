/*
Mary Price
March 11, 2020
ATM Machine: creates an atm machine and uses account class and atm class to
have the atm machine run properly
*/
#include "ATM.h"
#include <iostream>
using namespace std;

int main(){
  //Declaring variables
  bool validID = false;
  int userID;
  int userInput;
  int withdraw;
  int deposit;

  //Creating atm object with ATM class
  ATM atm;

  //A while loop that runs until the userID is 0
  while(userID != 0){

    //A do while loop that continues to run until the userID entered is valid
    do{
      cout << "Enter an ID: ";
      cin >> userID;

      //Uses isValid in ATM class to determine if userID is valid
      validID = atm.isValid(userID);

      //Breaks from the loop if the userID is 0
      if (userID == 0){
        cout << "Out of Service! Please try later..." << endl;
        return 0;
      }

      if(!(validID)){
        cout << "Invalid id number! Please try again..." << endl;
      }
    }while(!(validID));

    //A do while loop that continues to run until the userInput is 4
    do{
      //Displays the main menu using the atm class
      atm.mainMenu();

      //gets the user input
      cin >> userInput;

      //Checks balance using atm class if user input is 1
      if (userInput == 1){
        atm.checkBalance(userID);
      //Withdraws using atm class if user input is 2
      }else if (userInput == 2){
        cout << "Enter an amount to withdraw: ";
        cin >> withdraw;
        atm.makeWithdraw(withdraw, userID);
      //Deposits using atm class if user input is 3
      }else if (userInput == 3){
        cout << "Enter an amount to deposit: ";
        cin >> deposit;
        atm.makeDeposit(deposit, userID);
      //Exits from while loop if user input is 4
      }else if (userInput == 4){
        cout << "Proess is completed! See you next time!" << endl;
      //shows that the user input is invalid if it is not between 1-4
      }else{
        cout << "Invalid choice..." << endl;
      }
    }while(userInput != 4);
  }

  return 0;
}
