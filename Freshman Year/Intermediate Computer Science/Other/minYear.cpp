#include <iostream>
using namespace std;

int main(){
  int min;
  int day;
  int year;

  cout<<"Enter minutes: ";
  cin>>min;

  day = min/1440;
  year = day/365;
  day = day - (year*365);

  cout<<day<<" "<<year<<endl;
  return 0;
}
