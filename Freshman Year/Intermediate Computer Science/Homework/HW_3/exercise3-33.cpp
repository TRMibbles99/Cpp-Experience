/*
Mary Price
Feb 11, 2020
Exercise 3.33: Tells the user the day of the week from either a date entered
by the user or a random date.
*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

//Declaring variables
int user;
int dayMonth;
int month;
int year;
int j;
int k;

//With the input of a weekday it will display the day of the week.
int dayWeek(int weekday){
  switch(weekday){
    case 1: cout << "Day of the week is Sunday" << endl;
      break;
    case 2: cout << "Day of the week is Monday" << endl;
      break;
    case 3: cout << "Day of the week is Tuesday" << endl;
      break;
    case 4: cout << "Day of the week is Wednesday" << endl;
      break;
    case 5: cout << "Day of the week is Thursday" << endl;
      break;
    case 6: cout << "Day of the week is Friday" << endl;
      break;
    case 0: cout << "Day of the week is Satuday" << endl;
      break;
    default: cout << "Invalid Date" << endl;
      break;
  }
}

//Checks to see if the date that was entered is valid
int checkDate(int year, int month, int dayMonth){
  //Uses the month (for Feb also uses the year) to figure out how many days
  //there should be in the month and if they days entered fits
  switch(month){
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      if (!(dayMonth < 32)){
        cout << "Invalid Date" << endl;
        return false;
      } else {
        return true;
      }
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      if (!(dayMonth < 31)){
        cout << "Invalid Date" << endl;
        return false;
      } else {
        return true;
      }
      break;
    case 2:
      if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        if (!(dayMonth < 30)) {
          cout << "Invalid Date" << endl;
          return false;
        } else {
          return true;
        }
      } else {
        if (!(dayMonth < 29)){
          cout << "Invalid Date" << endl;
          return false;
        } else {
          return true;
        }
      }
      break;
    default:
      cout << "Invalid Date" << endl;
      return false;
      break;
  }
}

/*
Uses Christian Zeller equation to determine the day of the week, need a day
month, the month, and the year to determine that.
*/
int cZeller(int year, int month, int dayMonth){
  if (month == 1){
    month = 13;
    year--;
  } else if (month == 2){
    month = 14;
    year--;
  }

  k = year % 100;
  j = year / 100;
  return (dayMonth + 26*(month+1)/10 + k + k/4 + j/4 + 5*j) % 7;
}

//When the user enters 1, this will prompt user to enter year, month, and day
int userDate(){
  cout << "Enter a date (YYYY MM DD): ";
  cin >> year >> month >> dayMonth;

  if (!(checkDate(year, month, dayMonth))){
    return 0;
  }

  dayWeek(cZeller(year, month, dayMonth));
}

//When user enters 2 this will generate a random date
int randomDate(){
  srand(time(0));
  cout << "Generating a Random Date..." << endl;

  year = 2010 + rand() % (2022 - 2010);
  month = 1 + rand() % (13 - 1);
  dayMonth = 1 + rand() % (32 - 1);

  cout << "Date: " << year << " " << month << " " << dayMonth << endl;

  if(!(checkDate(year, month, dayMonth))){
    return 0;
  }

  dayWeek(cZeller(year, month, dayMonth));
}

int main(){
  /*
  A do-while loop that prompts the user to enter a number corresponding to
  what they want the program to do.
  */
  do{
    cout << "Either enter 1, 2, or 3" << endl;
    cout << "1. Enter a date (YYYY MM DD)" << endl;
    cout << "2. Generate a Random Date" << endl;
    cout << "3. Exit" << endl;
    cout << "Choice: ";
    cin >> user;
    cout << endl;

    if (user == 1){
      userDate();
    } else if (user == 2){
      randomDate();
    } else if (user == 3){
      return 0;
    } else {
      cout << "Invalid Number" << endl;
    }
  } while(user > 3 || user < 1);

  return 0;
}
