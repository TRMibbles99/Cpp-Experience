/*
Mary Price
April 13, 2020
Baby Name Ranking: This program lets the user choose between two options of
figuring out how common a certain baby name is between an interval of years
while the second option lets the user figure out the most common boy and girl
names during a certain year that start with a certain letter.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void optionOne();
void optionTwo();

int main(){
  //declaring variables
  int userOption = 0;
  do{
    //prompting user to enter in eitehr 1, 2, or 3 depending on what they want
    //the code to do
    cout << "Choose one of the options..." << endl;
    cout << "1. Ranking of the name for the year" << endl;
    cout << "2. Display the most popular three names starting with a letter" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter an option: ";
    cin >> userOption;

    //if the user does not enter any of those numbers then it will make them
    //enter again
    if (userOption < 1 || userOption > 3){
      cout << "Invalid option..." << endl;
    }

    //if the number was 1 or 2 then it will run either the functions optionOne
    //or optionTwo
    if (userOption == 1){
      optionOne();
    } else if(userOption == 2){
      optionTwo();
    }

  }while(userOption != 3);
  //while loop stops running when the option is 3 and the program ends

  return 0;
}

void optionOne(){
  //delcaring variables
  string userName;
  string userGender;

  string fileName;
  string rank;
  string mName;
  string fName;
  int mAmount;
  int fAmount;

  int userFirstYear;
  int userSecondYear;
  int total = 0;
  bool valid = false;

  //prompts the user to eter a name, gender, and year interval and if they enter
  //and invalid response then they will be prompted to enter it in again
  while(!valid){
    cout << "Enter a name: ";
    cin >> userName;
    cout << "Enter a gender: ";
    cin >> userGender;
    cout << "Enter a year-interval from: ";
    cin >> userFirstYear;
    cout << "to: ";
    cin >> userSecondYear;

    userGender = toupper(userGender[0]);
    userName[0] = toupper(userName[0]);

    if((userGender != "M" && userGender != "F") || userFirstYear >= userSecondYear || userFirstYear < 2001 || userSecondYear > 2010){
      cout << "Invalid input" << endl;
      valid = false;
    } else {
      valid = true;
    }

  }
  cout << "****************************" << endl;
  cout << "Ranking result for " << userName << " between " << userFirstYear << " and " << userSecondYear << endl;

  //this runs while the first year is less than or equal to the second year in
  //the interval
  while(userFirstYear <= userSecondYear){
    //figures out the filename needed using the current year it is investigating
    fileName = "babynamesranking";
    fileName.append(to_string(userFirstYear));
    fileName.append(".txt");
    ifstream input(fileName);

    //if the year is invalid it will tell the user that and quit trying to find
    //baby name data
    if(input.fail()){
      cout << "Invalid year" << endl;
      return;
    }

    //runs until the end of the input file or until it finds the baby name
    while(!input.eof()){
      input >> rank >> mName >> mAmount >> fName >> fAmount;

      //once it finds the baby name of the correct gender it displays its
      //rank for that year and the amount of times it is used
      if(userGender == "M" && userName == mName){
        cout << userFirstYear << ": #" << rank << ". " << mAmount << endl;
        total = total + mAmount;
        break;
      } else if (userGender == "F" && userName == fName){
        cout << userFirstYear << ": #" << rank << ". " << fAmount << endl;
        total = total + fAmount;
        break;
      }
    }
    input.close();

    //adds one to the first year each time
    userFirstYear++;
  }
  cout << "Total: " << total << " people have " << userName << " name." << endl;
  cout << endl;
}

void optionTwo(){
  //declaring variables
  char userLetter;
  int userYear;

  string fileName;
  string rank;
  string mName;
  string fName;
  string mAmount;
  string fAmount;

  //making two vectors to store the girl and boy baby name data
  vector <string> g;
  vector <string> b;

  //prompts the user
  cout << "Enter a letter to see most popular three names starts with: ";
  cin >> userLetter;
  cout << "Enter a year: ";
  cin >> userYear;
  cout << endl;

  //changes the letter ther user entered a capital letter and makes the file
  //name using the year
  userLetter = toupper(userLetter);
  fileName = "babynamesranking";
  fileName.append(to_string(userYear));
  fileName.append(".txt");
  ifstream input(fileName);

  //if the year is invalid then the code will go back to the menu
  if(input.fail()){
    cout << "Invalid year" << endl;
    return;
  }

  //while loop runs until either the end of the file or the size of both the
  //girl and boy vector are at 3
  while(!input.eof() && (g.size() < 3 || b.size() < 3)){
    input >> rank >> mName >> mAmount >> fName >> fAmount;

    //if it finds a name starting with the letter then if figures out if it is
    //a boy or girl name and puts it in the correct vector
    if ((mName[0] == userLetter) && (b.size() < 3)){
      b.push_back(mName);
    }else if((fName[0] == userLetter) && (g.size() < 3)){
      g.push_back(fName);
    }
  }

  //reads off both of the vectors
  cout << "Girls: " << endl;
  for(int i = 0; i < 3; i++){
    cout << "#" << i << " " << g[i] << endl;
  }
  cout << endl;
  cout << "Boys: " << endl;
  for(int i = 0; i < 3; i++){
    cout << "#" << i << " " << b[i] << endl;
  }

  cout << endl;
}
