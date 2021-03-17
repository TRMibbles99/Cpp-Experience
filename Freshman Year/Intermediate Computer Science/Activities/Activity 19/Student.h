#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using namespace std;

class Student
{
public:
  Student();
  // 13 define copy constructor
  Student(Student &);
  Student(const string& name, int gradYear,int capacity);
  // 10. Define deconstructor
  ~Student();
  string getName();
  int getgradYear();
  string* getCourseList();
  void addCourse(const string& name2);
  int getNumberOfCourses();

private:
  string name;
  int gradYear;
  // 1. define course list as a string pointer named Courses
  string * Courses;
  int numberOfCourses;
  int capacity;
};

#endif
