#ifndef DICT_H
#define DICT_H

#include <iostream>
#include "hash.h"
using namespace std;

template <class KeyType>
class Dictionary : public HashTable<KeyType>
{
public:
  Dictionary(int numSlots);

  KeyType* get(const KeyType& k) const;
  void insert(KeyType *k);
  void remove(const KeyType &k);
  bool empty() const;

  using HashTable<KeyType>::get;
  using HashTable<KeyType>::insert;
  using HashTable<KeyType>::remove;
  using HashTable<KeyType>::empty;


private:

};

class KeyError {};

#endif
