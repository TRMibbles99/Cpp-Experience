#include <iostream>
#include "Student.h"
#include <string>
using namespace std;

int main()
{
  // 4. create a student name Anna
  Student s1("Anna", 2022, 10);

  //5. create a student Ali on heap
  Student * s2Ptr = new Student("Ali", 2021, 5);

  //6. add course CS111-1 to Anna
  s1.addCourse("CS111-1");
  s1.addCourse("CS173");

  //7. add course CS181 to  Ali
  s2Ptr->addCourse("CS181");

  // 8. print course list of two students
  string * crs = s1.getCourseList();
  cout << s1.getName() << ": Course List" << endl;
  for (int i = 0; i < s1.getNumberOfCourses(); i++){
    cout << crs[i] << endl;
    //cout << *(crs+i) << endl;
  }
  cout << s2Ptr->getName() << ": Course List" << endl;
  crs = s2Ptr->getCourseList();
  for (int i = 0; i < s2Ptr->getNumberOfCourses(); i++){
    cout << crs[i] << endl;
    //cout << *(crs+i) << endl;
  }

  //9. delete student Ali
  delete s2Ptr;

  // 12. shallow copy: copy student Anna with copy constructor
  // and add a course and print course list
  Student s2(s1);
  cout << s2.getName() << endl;
  cout << s2.getgradYear() << endl;
  crs = s2.getCourseList();
  for (int i = 0; i < s2.getNumberOfCourses(); i++){
    cout << crs[i] << endl;
    //cout << *(crs+i) << endl;
  }

  cout << s1.getCourseList() << endl;
  cout << s2.getCourseList() << endl;

  // 13. deepcopy: copy student Anna with copy constructor
  // and add a course and print course list
  Student s3(s1);
  cout << s3.getName() << endl;
  s3.addCourse("CS271");
  crs = s3.getCourseList();
  for (int i = 0; i < s3.getNumberOfCourses(); i++){
    cout << crs[i] << endl;
    //cout << *(crs+i) << endl;
  }

  return 0;
}
