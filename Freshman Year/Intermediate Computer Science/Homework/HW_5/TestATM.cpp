#include "Account.h"
#include "ATM.h"
#include <iostream>
using namespace std;

int main(){
  bool validID = false;
  int userID;
  int userInput;
  int withdraw;
  int deposit;

  ATM atm();

  while(userID != 0){

    do{
      cout << "Enter an ID: ";
      cin >> userID;

      validID = atm.isValid(userID);

      if (userID == 0){
        cout << "Out of Service! Please try later..." << endl;
        return 0;
      }

      if(!(invalidID)){
        cout << "Invalid id number! Please try again..." << endl;
      }
    }while(!(validID));

    do{
      atm.mainMenu();
      cin >> userInput;
      if (userInput == 1){
        atm.checkBalance(userID);
      }else if (userInput == 2){
        cout << "Enter an amount to withdraw: ";
        cin >> withdraw;
        atm.makeWithdraw(withdraw, userID);
      }else if (uesrInput == 3){
        cout << "Enter an amount to deposit: ";
        cin >> deposit;
        atm.makeDeposit(deposit, userID);
      }else if (userInput == 4){
        cout << "Proess is completed! See you next time!" << endl;
      }else{
        cout << "Invalid choice..." << endl;
      }
    }while(userInput != 4);
  }

  return 0;
}
