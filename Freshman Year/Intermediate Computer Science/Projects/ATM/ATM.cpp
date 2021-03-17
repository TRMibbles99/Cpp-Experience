#include "Account.h"
#include "ATM.h"
#include <iostream>
using namespace std;

//Default constructor
ATM::ATM(){
  //Creates all the account objects in the list
  for (int i = 0; i < 10; i++){
    Account acc;
    accountList[i] = acc;
    accountList[i].setID(i+1);
    accountList[i].setBalance(100.00);
  }
}

//Checks if user id entered is between 1 and 10 and returns true, if not returns
//false
bool ATM::isValid(int userID){
  if (userID >= 1 && userID <= 10){
    return true;
  }
  return false;
}

//Displays the main  menu
void ATM::mainMenu(){
  cout << endl;
  cout << "Main Menu" << endl;
  cout << "1. Check Balance" << endl;
  cout << "2. Withdraw" << endl;
  cout << "3. Deposit" << endl;
  cout << "4. Exit" << endl;
  cout << "Enter a choice: ";
}

//Displays the current balance of a certain account
void ATM::checkBalance(int userID){
  cout << "The balance is: " << accountList[userID-1].getBalance() << endl;
}

//Makes a withdraw to a certain account, unless the withdraw is too high or
//below 0
void ATM::makeWithdraw(int withdraw, int userID){
  int balance = accountList[userID-1].getBalance();
  accountList[userID-1].withdraw(withdraw);
  if (balance == accountList[userID-1].getBalance()){
    cout << "Invalid amount to withdraw, ignored" << endl;
  }else{
    cout << "Process is completed!" << endl;
  }
}

//makes a deposit if the number is not negative
void ATM::makeDeposit(int deposit, int userID){
  int balance = accountList[userID-1].getBalance();
  accountList[userID-1].deposit(deposit);
  if (balance == accountList[userID-1].getBalance()){
    cout << "Invalid amount to deposit, ignored" << endl;
  } else {
    cout << "Process is completed!" << endl;
  }
}
