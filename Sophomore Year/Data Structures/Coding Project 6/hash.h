#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <cmath>
#include "list.h"
using namespace std;

template <class KeyType>
class HashTable : public List<KeyType>
{
public:
  HashTable(int numSlots);
  HashTable(const HashTable<KeyType>& h);
  ~HashTable();

  KeyType* get(const KeyType& k) const;
  void insert(KeyType *k);
  void remove(const KeyType& k);
  bool empty() const;

  HashTable<KeyType>& operator=(const HashTable<KeyType>& h);

  std::string toString(int slots) const;


private:
  int slots;
  List<KeyType> *table; // an array of List<KeyType>’s
  void copy(const HashTable<KeyType>& h);

};

#endif
