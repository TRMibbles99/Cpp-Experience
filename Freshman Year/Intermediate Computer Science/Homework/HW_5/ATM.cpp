#include "Account.h"
#include "ATM.h"
#include <iostream>

ATM::ATM(){
  int counter = 1;
  for (int i = 1; i <= 10; i++){
    Account counter;
    counter.setID(i);
    counter.setBalance(100.00);
    accountList[i] = counter;
    counter++;
  }
}

bool ATM::isValid(int userID){
  if (userID >= 1 && userID <= 10){
    return true;
  }
  return false;
}

void ATM::mainMenu(){
  cout << "Main Menu" << endl;
  cout << "1. Check Balance" << endl;
  cout << "2. Withdraw" << endl;
  cout << "3. Deposit" << endl;
  cout << "4. Exit" << endl;
  cout << "Enter a choice: ";
}

void ATM::checkBalance(int userID){
  cout << "The balance is: " << accountList[userID-1].getBalance();
}

void ATM::makeWithdraw(int withdraw, int userID){
  int balance = accountList[userID-1].getBalance();
  accountList[userID-1].withdraw(withdraw);
  if (balance == accountList[userID-1].getBalance()){
    cout << "Invalid amount to withdraw, ignored" << endl;
  }else{
    cout << "Process is completed!" << endl;
  }
}

void ATM::makeDeposit(int deposit, int userID){
  accountList.[userID-1].deposit(deposit);
  cout << "Process is completed!"
}
