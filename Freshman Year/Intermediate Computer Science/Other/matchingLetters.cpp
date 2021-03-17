#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main(){
  string user;
  int length;
  string first;
  string last;

  cout  << "Enter a string: ";
  cin >> user;

  length = user.length();
  first = tolower(user[0]);
  last = tolower(user[length-1]);

  if (first == last){
    cout << "first and last characters match" << endl;
  } else {
    cout << "first and last characters do not match" << endl;
  }

  return 0;
}
