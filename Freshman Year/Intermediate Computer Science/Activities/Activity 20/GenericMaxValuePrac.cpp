#include <iostream>
#include <string>
using namespace std;

template<typename T>
T maxValue(T value1, T value2)
{
  //The two values have the same type;
  //The two values can be compared using the > operator
  if (value1 > value2)
    return value1;
  else
    return value2;
}
/* Q2
Design a generic function that returns a maximum element from an array.
The function should have two parameters.
One is the array of a generic type, and the other is the size of the array.
Test the function with the array of int, double, and string values
*/
template<typename T>
T maxListValue(T list[], int size){
  T storage = list[0];
  for (int i = 0; i < size; i++){
    if (list[i] > storage){
      storage = list[i];
    }
  }
  return storage;
}




int main()
{
  cout << "Maximum between 1 and 3 is " << maxValue(1, 3) << endl;
  cout << "Maximum between 1.5 and 0.3 is "
    << maxValue(1.5, 0.3) << endl;
  cout << "Maximum between 'A' and 'N' is "
    << maxValue('A', 'N') << endl;
  cout << "Maximum between \"NBC\" and \"ABC\" is "
    << maxValue(string("NBC"), string("ABC")) << endl;

 // Test Q2 here
 int intA[] = {1, 2, 3};
 cout << "Max = " << maxListValue(intA, 3) << endl;
 string stringA[] = {"abc", "cbs", "nbc"};
 cout << "Max = " << maxListValue(stringA, 3) << endl;

  return 0;
}
