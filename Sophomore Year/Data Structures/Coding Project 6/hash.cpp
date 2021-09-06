#include <iostream>
#include <sstream>
#include <string>
#include "hash.h"

using namespace std;

template <class KeyType>
HashTable<KeyType>::HashTable(int numSlots){
  table = new List<KeyType>[numSlots];
  slots = numSlots;
}

template <class KeyType>
HashTable<KeyType>::HashTable(const HashTable<KeyType>& h){
  copy(h);
}

template <class KeyType>
HashTable<KeyType>::~HashTable(){
  while (slots != 0){
    table[slots-1].~List();
    slots--;
  }
}

template<class KeyType>
void HashTable<KeyType>::copy(const HashTable<KeyType>& h){
  slots = h.slots;
  table = new List<KeyType>[slots];
  for(int i = 0; i < slots; i++){
    table[i] = h.table[i];
  }
}

template <class KeyType>
bool HashTable<KeyType>::empty() const{
  if(slots == 0){
    return true;
  }else{
    for(int i = 0; i < slots; i++){
      if(table[i].length() != 0){
        return false;
      }
    }
    return true;
  }
}

template <class KeyType>
KeyType* HashTable<KeyType>::get(const KeyType& k) const{
  int index = k.hash;
  return table[index].get(k);
}

template <class KeyType>
void HashTable<KeyType>::insert(KeyType *k){
  int index = k->hash;
  table[index].insert(0, k);
}

template <class KeyType>
void HashTable<KeyType>::remove(const KeyType& k){
  int index = k.hash;
  table[index].remove(k);
}

template <class KeyType>
HashTable<KeyType>& HashTable<KeyType>::operator=(const HashTable<KeyType>& h){
  if (this != &h){
    copy(h);
  }
  return *this;
}

template <class KeyType>
std::string HashTable<KeyType>::toString(int slots) const{
  std::stringstream ss;
  for(int i = 0; i < slots; i++){
    ss << table[i].List::toString();
  }
  return ss.str();
}
