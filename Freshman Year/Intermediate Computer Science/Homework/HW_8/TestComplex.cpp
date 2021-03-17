#include <iostream>
#include <string>
#include "Complex.h"

int main(){
  Complex number1;
  cout << "Enter the first complex number: ";
  cin >> number1;
  Complex number2;
  cout << "Enter teh second compled number: ";
  cin >> number2;

  cout << " (" << number1 << ")" << " + " << "(" << number2
    << ") = " << (number1 + number2) << endl;
  cout << " (" << number1 << ")" << " - " << "(" << number2
    << ") = " << (number1 - number2) << endl;
  cout << " (" << number1 << ")" << " * " << "(" << number2
    << ") = " << (number1 * number2) << endl;
  cout << " (" << number1 << ")" << " / " << "(" << number2
    << ") = " << (number1 / number2) << endl;

  number1[0] = 3.4;
  cout << "number1:"<<number1<< endl;
  cout << "number2:"<<number2<< endl;
  number2=number1++;
  cout << "number1:"<<number1<< endl;
  cout << "number2:"<<number2<< endl;
  number2 = ++number1;
  cout << "number1:"<<number1<< endl;
  cout << "number2:"<<number2<< endl;

  cout << "(3 + number2)=" << (3 + number2)<<endl;
  cout << "(number2 += number1)=" << (number2 += number1) << endl;
  cout << "(number2 *= number1)=" << (number2 *= number1) << endl;

  return 0;
}
