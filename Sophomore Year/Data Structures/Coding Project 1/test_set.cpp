#include <iostream>
#include <stdexcept>
#include <string>
#include "set_empty.cpp"
using namespace std;

int main(){
  Set<int> s;
  s.insert(3);
  s.insert(4);
  s.insert(4);
  cout << "s: " << s << endl;
  cout <<"s cardinality: " << s.cardinality() <<endl;
  if (s.contains(4)){
    cout << "s contains 4: " << endl;
  }
  s.remove(3);
  cout << "s after removing 3: " << s << endl;
  cout << s.contains(3) << endl;
  Set<int> t;
  t.insert(4);
  cout << "t: " << t << endl;
  if(s == t){
    cout << "s = t" << endl;
  }
  t.insert(9);
  cout << "t after inserting 9: " << t << endl;
  if(s <= t){
    cout << "s is in t" << endl;
  }
  s.insert(5);
  cout << "s after inserting 5: " << s << endl;
  Set<int> a = t + s;
  cout << "a is t + s: " << a << endl;
  cout << "now a - s: " << a - s << endl;
  Set<int> b = t & s;
  cout << "b is t & s: " << b << endl;
  Set<int> c;
  c = s;
  cout << "s is equal to c: " << c << endl;
  //cout << "c is a copy of s: " << c << endl;
  Set<int> d;
  if (d.empty()){
    cout << "d is empty: " << endl;
  }

  return 0;
}
