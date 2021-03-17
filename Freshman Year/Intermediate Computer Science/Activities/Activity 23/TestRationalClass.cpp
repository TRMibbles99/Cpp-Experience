#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
  // Create and initialize two rational numbers r1 and r2.
  Rational r1(4, 12);
  Rational r2(2, 3);

  // Test toString, add, subtract, multiply, and divide


  cout << r1.toString() << " + " << r2.toString() << " = "
    << r1.add(r2).toString() << endl;

  cout << r1.toString() << " + " << r2.toString() << " = "
    << (r1+r2).toString() << endl;

  cout << r1.toString() << " - " << r2.toString() << " = "
    << r1.subtract(r2).toString() << endl;

  cout << r1.toString() << " - " << r2.toString() << " = "
      << (r1-r2).toString() << endl;

  cout << r1.toString() << " * " << r2.toString() << " = "
    << r1.multiply(r2).toString() << endl;

  cout << r1.toString() << " * " << r2.toString() << " = "
    << (r1*r2).toString() << endl;

  cout << r1.toString() << " / " << r2.toString() << " = "
    << r1.divide(r2).toString() << endl;

  cout << r1.toString() << " / " << r2.toString() << " = "
    << (r1/r2).toString() << endl;

  // Test intValue and double
  cout << "r2.intValue()" << " is " << r2.intValue() << endl;
  cout << "r2.doubleValue()" << " is " << r2.doubleValue() << endl;

  // Test compareTo and equal
  cout << "r1.compareTo(r2) is " << r1.compareTo(r2) << endl;

  cout << "r1.compareTo(r2) is " << ((r1<r2)?"r1 is smaller":"r1 is bigger") << endl;

  cout << "r2.compareTo(r1) is " << r2.compareTo(r1) << endl;
  cout << "r1.compareTo(r1) is " << r1.compareTo(r1) << endl;
  cout << "r1.equals(r1) is "
       << (r1.equals(r1) ? "true" : "false") << endl;
  cout << "r1.equals(r2) is "
       << (r1.equals(r2) ? "true" : "false") << endl;

  Rational r3(1,2);
  r3+=r1;
  cout << "r3 is " << r3.toString() << endl;

  Rational r4(3,6);
  r4[0]=2; r4[1]=5;
  cout << "r4 is " << r4.toString() << endl;

  r3=++r4;
  cout << "r3 is " << r3.toString() << endl;
  cout << "r4 is " << r4.toString() << endl;
  cout << "r4 is " << (--r4).toString() << endl;

  return 0;
}
