#include <iostream>
#include <cassert>
#include "bst.cpp"
#include "dict.cpp"

using namespace std;

void test_get(Dictionary<int>& dict, int key){
  assert(*(dict.get(key)) == key);
}

void test_empty(Dictionary<int>& dict){
  assert(dict.empty() == 1);
}

void test_notempty(Dictionary<int>& dict){
  assert(dict.empty() == 0);
}

int main(){
  int a[4] = {2,1,4,3};

  Dictionary<int> dict;
  test_empty(dict);

  for (int i = 0; i < 4; i++){
    dict.insert(&(a[i]));
  }

  test_get(dict, 1);
  test_get(dict, 2);
  test_get(dict, 3);
  test_get(dict, 4);

  test_notempty(dict);

  dict.remove(1);
  dict.remove(2);
  dict.remove(3);
  dict.remove(4);

  //test_empty(dict);

  return 0;
}
