#include <iostream>
#include <string>
#include "RationalWithOperators.h"
using namespace std;

int main()
{
  // Create and initialize two rational numbers r1 and r2.
  Rational r1(4, 2);
  Rational r2(2, 3);
  Rational r7;
  cin>>r7;
  cout<<r7;

  // Test relational operators
  cout << r1 << " < " << r2 << " is " <<
    ((r1 < r2) ? "true" : "false") << endl;


  // Test toString, add, subtract, multiply, and divide operators
  cout << r1.toString() << " + " << r2.toString() << " = " << (r1 + r2).toString() << endl;
  cout << r1.toString() << " - " << r2.toString() << " = " << (r1 - r2).toString() << endl;
  cout << r1.toString() << " * " << r2.toString() << " = " << (r1 * r2).toString() << endl;
  cout << r1.toString() << " / " << r2.toString() << " = " << (r1 / r2).toString() << endl;

  // Test augmented operators
  Rational r3(1, 2);
  r3 += r1;
  cout << "r3 is " << r3.toString() << endl;

  // Test function operator []
  Rational r4(1, 2);
  r4[0] = 3; r4[1] = 4;
  cout << "r4 is " << r4.toString() << endl;

  // Test function operators for prefix ++ and --
  r3 = r4++;
  cout << "r3 is " << r3.toString() << endl;
  cout << "--r3 is " << (--r3).toString() << endl;
  cout << "r4 is " << r4.toString() << endl;

  cout << r3+4 << endl;
  cout << 4+r3 << endl;
  cout << (4-r3) << endl;
  cout << (4*r3) << endl;
  cout << (4/r3) << endl;

  return 0;
}
