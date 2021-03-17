#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
  // Copy Grades.txt file in reverse order with first two colums: course name and grades
  // you can use two vectors to store course name and grades
  ifstream input("Grades.txt");
  ofstream output("ReverseGrades.txt");

  if(input.fail()){
    cout << "Grades.txt does not exist" << endl;
    cout << "Exit program" << endl;
    return 0;
  }

  vector <string> grades;
  vector <string> name;
  string num;
  string gra;
  string course;

  while(!input.eof()){
    getline(input, course, ' ');
    getline(input, gra, ' ');
    getline(input, num, '\n');
    grades.push_back(gra);
    name.push_back(course);
  }

  for(int i = name.size() - 2; i >= 0; i--){
    output << name[i] << " " << grades[i] << "\n";
  }

  input.close();
  output.close();

  cout << "\nCopy Done" << endl;


  return 0;
}
