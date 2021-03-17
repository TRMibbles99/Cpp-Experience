#include "Account.h"

//Default constructor that sets the id to 0 and balance to 0
Account::Account(){
  id = 0;
  balance = 0;
}

//changes the id to a given one
void Account::setID(int newID){
  id = newID;
}

//changes the balance to a given one
void Account::setBalance(double newBal){
  balance = newBal;
}

//returns the id of an account
int Account::getID(){
  return id;
}

//returns the balance of an account
double Account::getBalance(){
  return balance;
}

//withdraws a given amount if the amount is less than or equal to the balance
//does not withdraw if the amount is below 0
void Account::withdraw(double amount){
  if (amount <= balance && amount > 0){
    balance = balance - amount;
  }
}

//deposits a given amount if it is larger than 0
void Account::deposit(double amount){
  if (amount > 0){
    balance = balance + amount;
  }
}
