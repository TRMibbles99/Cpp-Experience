#include <iostream>
#include <cassert>
#include "hash.cpp"
#include "dict.cpp"
#include "dummy.h"

using namespace std;

void test_get(Dictionary<Dummy>& dict, Dummy key){
  assert(*(dict.get(key)) == key);
}

void test_empty(Dictionary<Dummy>& dict){
  assert(dict.empty() == 1);
}

void test_notempty(Dictionary<Dummy>& dict){
  assert(dict.empty() == 0);
}

int main(){
  Dummy a(1,4);
  Dummy b(2,4);
  Dummy c(3,4);
  Dummy d(4,4);

  Dictionary<Dummy> dict(4);
  test_empty(dict);

  dict.insert(&a);
  dict.insert(&b);
  dict.insert(&c);
  dict.insert(&d);

  test_get(dict, a);
  test_get(dict, b);
  test_get(dict, c);
  test_get(dict, d);

  test_notempty(dict);

  dict.remove(a);
  dict.remove(b);
  dict.remove(c);
  dict.remove(d);

  return 0;
}
