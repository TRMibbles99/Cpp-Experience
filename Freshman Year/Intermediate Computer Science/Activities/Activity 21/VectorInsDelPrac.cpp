#include <iostream>
#include <vector>
using namespace std;

//Note: the max_element and find are not working on my computer, but I made the
//removeZeroElements with them commented out then I commented it back in to
//turn in the file. Not sure if compile issue will occur with your computer of
//if it is just my computer.

void removeZeroElements(vector<int> & vec);


int main()
{
  double values[] = {1, 2, 3, 4, 5, 6, 7};
  vector<double> v(values, values + 7);

  cout<<v.capacity()<<endl;
  cout<<v.size()<<endl;

  v.push_back(12);

  cout<<v.capacity()<<endl;
  cout<<v.size()<<endl;

  cout << "Initial contents in v: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  v.assign(4, 11.5);

  cout << "\nAfter the assign function, v: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  v.at(0) = 22.4;
  cout << "\nAfter the at function, v: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  auto itr = v.begin();

  v.insert(itr + 1, 555);
  v.insert(itr + 1, 666);
  cout << "\nAfter the insert function, v: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  cout << "\nThe max element is ";
       *max_element(v.begin()+3, v.end()) << endl;

  int key = 555;
  if (find(v.begin(), v.end(), key) == v.end())
      cout << key << " is not in the vector" << endl;
  else
      cout << key << " is in the vector" << endl;

  v.erase(itr);
  v.erase(v.end()-1);

  cout << "\nAfter the erase function, v: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  v.erase(itr + 2, itr + 4);
  cout << "\nAfter the erase function, v: ";
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";

  v.clear();
  cout << "Size is " << v.size() << endl;
  cout << "Is empty? " <<
        (v.empty() ? "true" : "false") << endl;

  vector<int> delZero{0, 85, 90, 100, 0, 0, 92, 75, 0, 91, 63, 0};
  removeZeroElements(delZero);
  for (int i = 0; i < delZero.size(); i++)
    cout << delZero[i] << " ";

  return 0;
}

/*
 * Function: removeZeroElements
 * Usage: removeZeroElements(vec);
 * -------------------------------
 * This function goes through the elements of the vector and removes any
 * elements whose value is zero.  The loop operates in reverse order to
 * ensure that removing an element doesn't change the indices of the
 * elements that are left to be examined.
 */

void removeZeroElements(vector<int> & vec) {
    for(int i = vec.size()-1; i >= 0; i--){
      if(vec.at(i) == 0){
        vec.erase(vec.begin()+i);
      }
    }
}
