//needs the class Account
#include "Account.h"

class ATM{
private:
  //creates the list of accounts
  Account accountList[10];
public:
  //Default constructor
  ATM();

  //Checks to see if id entered is valid
  bool isValid(int);

  //Displays the main menu
  void mainMenu();

  //Displays the balance
  void checkBalance(int);

  //makes a withdraw
  void makeWithdraw(int, int);

  //makes a deposit
  void makeDeposit(int, int);
};
