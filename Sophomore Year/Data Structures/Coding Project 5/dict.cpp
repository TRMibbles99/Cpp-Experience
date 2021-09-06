#include <iostream>
#include <sstream>
#include "dict.h"
#include "bst.h"

using namespace std;

template <class KeyType>
Dictionary<KeyType>::Dictionary() : BST<KeyType>()
{ }

template <class KeyType>
KeyType* Dictionary<KeyType>::get(const KeyType& k) const{
  return BST<KeyType>::get(k);
}

template <class KeyType>
void Dictionary<KeyType>::insert(KeyType *k){
  BST<KeyType>::insert(k);
}

template <class KeyType>
void Dictionary<KeyType>::remove(const KeyType &k){
  BST<KeyType>::remove(k);
}

template <class KeyType>
bool Dictionary<KeyType>::empty() const{
  return BST<KeyType>::empty();
}
