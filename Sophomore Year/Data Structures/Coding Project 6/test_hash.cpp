#include <iostream>
#include <cassert>
#include "hash.cpp"
#include "dummy.h"

using namespace std;

void test_get(HashTable<Dummy>& h, Dummy key){
  assert(*(h.get(key)) == key);
}

void test_empty(HashTable<Dummy>& h){
  assert(h.empty() == 1);
}

void test_notempty(HashTable<Dummy>& h){
  assert(h.empty() == 0);
}

int main(){
  Dummy a(1,4);
  Dummy b(2,4);
  Dummy c(3,4);
  Dummy d(4,4);

  HashTable<Dummy> h(4);
  test_empty(h);

  h.insert(&a);
  h.insert(&b);
  h.insert(&c);
  h.insert(&d);

  test_get(h, a);
  test_get(h, b);
  test_get(h, c);
  test_get(h, d);

  test_notempty(h);

  h.remove(a);
  h.remove(b);
  h.remove(c);
  h.remove(d);

  return 0;
}
