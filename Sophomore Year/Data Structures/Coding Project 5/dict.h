#ifndef DICT_H
#define DICT_H

#include <iostream>
#include "bst.h"
using namespace std;

template <class KeyType>
class Dictionary : public BST<KeyType>
{
public:
  Dictionary();

  KeyType* get(const KeyType& k) const;
  void insert(KeyType *k);
  void remove(const KeyType &k);
  bool empty() const;

  using BST<KeyType>::get;
  using BST<KeyType>::insert;
  using BST<KeyType>::remove;
  using BST<KeyType>::empty;


private:

};

#endif
