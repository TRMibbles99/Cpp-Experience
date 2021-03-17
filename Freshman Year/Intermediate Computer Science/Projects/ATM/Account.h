//Allows the Account class to be used in other classes
#pragma once

class Account{
private:
  //Declaring variables
  int id;
  double balance;
public:
  //Default constructor
  Account();

  //these set the id or balance for the account
  void setID(int);
  void setBalance(double);

  //these return the id or the balance
  int getID();
  double getBalance();

  //these withdraw or deposit an amount given into an account
  void withdraw(double);
  void deposit(double);
};
