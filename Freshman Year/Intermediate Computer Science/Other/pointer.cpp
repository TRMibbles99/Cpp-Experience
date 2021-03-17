#include <iostream>
using namespace std;

int main(){
  int count = 5;
  // * for pointer declaration
  int* pCount = &count;

  double num = 34.5;
  double * numPtr;
  numPtr = &num;

  cout << "The value of count is: " << count << endl;
  cout << "The address of count is: " << &count << endl;
  cout << "The address of count is: " << pCount << endl;
  //dereferencing opterator
  cout << "The value of count is: " << *pCount << endl;
}
