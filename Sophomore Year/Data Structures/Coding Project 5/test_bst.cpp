#include <iostream>
#include <cassert>
#include "bst.cpp"
using namespace std;

void test_get(BST<int>& bst, int num){
  assert(*(bst.get(num)) == num);
}

void test_empty(BST<int>& bst){
  assert(bst.empty() == 1);
}

void test_notempty(BST<int>& bst){
  assert(bst.empty() == 0);
}

void test_successor(BST<int>& bst, int num){
  assert(*(bst.successor(num)) > num);
}

void test_predecessor(BST<int>& bst, int num){
  assert(*(bst.predecessor(num)) < num);
}

void test_max(BST<int>& bst, int max){
  assert(*(bst.maximum()) == max);
}

void test_min(BST<int>& bst, int min){
  assert(*(bst.minimum()) == min);
}

int main(){
  int a[4] = {2,1,4,3};

  BST<int> bst;
  test_empty(bst);

  for (int i = 0; i < 4; i++){
    bst.insert(&(a[i]));
  }

  test_get(bst, 1);
  test_get(bst, 2);
  test_get(bst, 3);
  test_get(bst, 4);

  test_notempty(bst);

  cout << bst.inOrder() << endl;
  cout << bst.preOrder() << endl;
  cout << bst.postOrder() << endl;

  test_successor(bst, 3);
  test_predecessor(bst, 3);
  test_max(bst, 4);
  test_min(bst, 1);

  bst.remove(1);
  bst.remove(2);
  bst.remove(3);
  bst.remove(4);

  test_empty(bst);

  return 0;
}
