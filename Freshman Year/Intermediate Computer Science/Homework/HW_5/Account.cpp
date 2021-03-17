#include "Account.h"

Account::Account(){
  id = 0;
  balance = 0;
}

void Account::setID(int newID){
  id = val;
}

void Account::setBalance(double newBal){
  balance = newBal;
}

int Account::getID(){
  return id;
}

double Account::getBalance(){
  return balance;
}

void Account::withdraw(double amount){
  if (withdraw < balance){
    balance = balance - withdraw;
  }
}

void Account::deposit(double amount){
  balance = balance + amount;
}
