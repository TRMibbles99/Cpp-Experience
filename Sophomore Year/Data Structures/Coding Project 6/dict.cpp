#include <iostream>
#include <sstream>
#include "dict.h"
#include "hash.h"

using namespace std;

template <class KeyType>
Dictionary<KeyType>::Dictionary(int numSlots) : HashTable<KeyType>(numSlots)
{ }

template <class KeyType>
KeyType* Dictionary<KeyType>::get(const KeyType& k) const{
  return HashTable<KeyType>::get(k);
}

template <class KeyType>
void Dictionary<KeyType>::insert(KeyType *k){
  if(HashTable<KeyType>::get(*k) != NULL){
    throw KeyError();
  }
  HashTable<KeyType>::insert(k);
}

template <class KeyType>
void Dictionary<KeyType>::remove(const KeyType &k){
  HashTable<KeyType>::remove(k);
}

template <class KeyType>
bool Dictionary<KeyType>::empty() const{
  return HashTable<KeyType>::empty();
}
