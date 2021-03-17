/*
Mary Price
Feb 12, 2020
Exercise 4.23: This checks to see if the SSN of the user is in the correct
format/valid.
*/
#include <iostream>
#include <cstring>
using namespace std;

int main(){
  //Declaring strings
  string ssn;

  //Prompting user
  cout << "Enter your SSN: ";
  cin >> ssn;

  //Checks to see if the length of the user string is 11, the length of a SSN
  if (ssn.length() != 11){
    cout << ssn << " is an invalid SSN" << endl;
    return 0;
  }

  //Checks to see if all '-' are in the right places of the user string
  for (int i = 0; i < ssn.length(); i++){
    if((i == 3 || i == 6) && ssn[i] != '-'){
      cout << ssn << " is an invalid SSN" << endl;
      return 0;
    }
  }

  //If user string is a valid SSN will display that it is valid
  cout << ssn << " is a valid SSN" << endl;
  return 0;
}
