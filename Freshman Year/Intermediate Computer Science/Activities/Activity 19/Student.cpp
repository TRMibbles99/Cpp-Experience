#include <iostream>
#include "Student.h"
#include <string>
using namespace std;

Student::Student()
{
  //2. write implementation of constructor
  name = "XXX";
  gradYear = 3000;
  numberOfCourses = 0;
  capacity = 10;
  Courses = new string[capacity];
}


Student::Student(const string& name, int gradYear,int capacity)
{
  // 3. write write implementation of constructor
  this->name = name;
  this->gradYear = gradYear;
  numberOfCourses = 0;
  this->capacity = capacity;
  Courses = new string[capacity];
}

// 11. Write deconstructor implementation
Student::~Student(){
  cout << name << endl;
  cout << "I am releasing all course cells from memory" << endl;
  delete [] Courses;
}

//13. define a copy constructor
Student::Student(Student & s){
  this->name = s.name;
  this->gradYear = s.gradYear;
  numberOfCourses = s.numberOfCourses;
  this->capacity = s.capacity;
  Courses = new string[s.capacity];
  for (int i = 0; i < numberOfCourses; i++){
      Courses[i] = s.Courses[i];
  }
}

int Student::getgradYear(){
  return gradYear;
}
int Student::getNumberOfCourses(){
  return numberOfCourses;
}
void Student::addCourse(const string& name2){
  Courses[numberOfCourses]=name2;
  numberOfCourses++;
}
string* Student::getCourseList(){
  return Courses;
}

string Student::getName(){
  return name;
}
