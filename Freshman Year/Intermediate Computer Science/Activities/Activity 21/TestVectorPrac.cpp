#include <iostream>
#include <vector>
#include <string>
using namespace std;

// function template for outputting vector elements
template<typename T>
void printVector(vector<T> &v){
  // for (int i = 0; i < v.size(); i++)
  //   cout << intVector[i] << " ";
  for (T item:v){
    cout << item << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> intVector;

  // Store numbers 1, 2, 3, 4, 5, ..., 10 to the vector
  for (int i = 0; i < 10; i++){
    intVector.push_back(i + 1);
    cout<<"c:"<<intVector.capacity()<<endl;
    cout<<"s:"<<intVector.size()<<endl;

  }

  // Display the numbers in the vector
  cout << "Numbers in the vector: ";
  printVector(intVector);

  // for (int i = 0; i < intVector.size(); i++)
  //   cout << intVector[i] << " ";
    //cout << intVector.at(i) << " ";


  vector<string> stringVector;

  // Store strings into the vector
  stringVector.push_back("Dallas");
  stringVector.push_back("Houston");
  stringVector.push_back("Austin");
  stringVector.push_back("Norman");

  // Display the string in the vector

  cout << "\nStrings in the string vector: ";
  printVector(stringVector);
  // for (int i = 0; i < stringVector.size(); i++)
  //   cout << stringVector[i] << " ";



  stringVector.pop_back(); // Remove the last element

  vector<string> v2;
  v2.swap(stringVector);
  v2[0] = "Atlanta";

  // Redisplay the string in the vector
  cout << "\nStrings in the vector v2: ";
  printVector(v2);
  // for (int i = 0; i < v2.size(); i++)
  //   cout << v2.at(i) << " ";


  return 0;
}
