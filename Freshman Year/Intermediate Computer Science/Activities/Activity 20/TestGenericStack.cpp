#include <iostream>
#include <string>
#include "GenericStack.h"

using namespace std;

int main()
{
  // Create a stack of int values
  Stack<int> intStack;
  for (int i = 0; i < 10; i++)
    intStack.push(i);

  intStack.printStack();
  if (intStack.contains(9)){
    cout << "List does contain a 9" <<  endl;
  } else {
    cout << "List does not contain a 9" << endl;
  }
  if (intStack.contains(20)){
    cout << "List does contain a 20" << endl;
  } else {
    cout << "List does not contain a 20" << endl;
  }

  while (!intStack.empty())
    cout << intStack.pop() << " ";
  cout << endl;

  // Create a stack of strings
  Stack<string> stringStack;
  stringStack.push("Chicago");
  stringStack.push("Denver");
  stringStack.push("London");

  while (!stringStack.empty())
    cout << stringStack.pop() << " ";
  cout << endl;

    if (stringStack.contains("Chicago")){
      cout << "List does contain Chicago" << endl;
    } else {
      cout << "List does not contain Chicago" << endl;
    }
    if (stringStack.contains("Ohio")){
      cout << "List does contain Ohio" << endl;
    } else {
      cout << "List does not contain Ohio" << endl;
    }

  return 0;
}
