// set.cpp

#include <sstream>
#include <iostream>
#include "set.h"

using namespace std;

template <class Element>
Set<Element>::Set()
{
   head = NULL;
   length = 0;
}

template <class Element>
void Set<Element>::copy(const Set<Element>& s)
{
  if(s.length == 0){
    head = NULL;
    length = 0;
  }else{
    Node<Element> *stemp = s.head;
    while(stemp != NULL){
      insert(stemp -> value);
      stemp = stemp -> next;
    }
  }
}

template <class Element>
void Set<Element>::destroy()
{
  while(head != NULL){
    Node<Element> *temp = head;
    head = head -> next;
    delete temp;
  }
  head = NULL;
  length = 0;
}

template <class Element>
Set<Element>::Set(const Set<Element>& s)
{
  copy(s);
}

template <class Element>
Set<Element>& Set<Element>::operator=(const Set<Element>& s)
{
  copy(s);
}

template <class Element>
Set<Element>::~Set()
{
  destroy();
}

template <class Element>
bool Set<Element>::empty() const
{
  if(length == 0){
    return true;
  }
  return false;
}

template <class Element>
int Set<Element>::cardinality() const
{
  return length;
}

template <class Element>
bool Set<Element>::contains(const Element& item) const
{
  Node<Element> *temp = head;
  for (int i = 0; i < length; i++){
    if (temp -> value == item){
      return true;
    }
    temp = temp -> next;
  }
  return false;
}

template <class Element>
void Set<Element>::insert(const Element& item)
{
  if (!contains(item)){
    Node<Element>* newNode = new Node<Element>(item);
    newNode->next = head;
    head = newNode;
    length++;
  }
}

template <class Element>
void Set<Element>::remove(const Element& item)
{
  if (contains(item)){
    Node<Element> *temp = head;
    Node<Element> *prev = head;
    while(temp != NULL){
      if(temp->value == item){
        if(head -> value == item){
          head = head -> next;
          delete temp;
          length--;
          return;
        }else{
          prev -> next = temp -> next;
          delete temp;
          length--;
          return;
        }
      }
      prev = temp;
      temp = temp -> next;
    }
  }
}

template <class Element>
bool Set<Element>::operator<=(const Set<Element>& s) const
{
  if(length >= s.cardinality()){
    Node<Element> *temp = s.head;
    while(temp != NULL){
      if(!contains(temp->value)){
        return false;
      }
      temp = temp -> next;
    }
  }else{
    return true;
  }
  return true;
}

template <class Element>
bool Set<Element>::operator==(const Set<Element>& s) const
{
  if (length != s.cardinality()){
    return false;
  }else{
    Node<Element> *temp = head;
    while(temp != NULL){
      if(!s.contains(temp -> value)){
        return false;
      }
      temp = temp -> next;
    }
  }
  return true;
}

template <class Element>
Set<Element> Set<Element>::operator+(const Set<Element>& s) const
{
  Set<Element> t;
  Node<Element> *temp = head;
  while(temp != NULL){
    t.insert(temp -> value);
    temp = temp -> next;
  }
  Node<Element> *stemp = s.head;
  while(stemp != NULL){
    t.insert(stemp -> value);
    stemp = stemp -> next;
  }
  return t;
}

template <class Element>
Set<Element> Set<Element>::operator&(const Set<Element>& s) const
{
  Set<Element> t;
  Node<Element> *temp = head;
  while(temp != NULL){
    if(s.contains(temp -> value)){
      t.insert(temp -> value);
    }
    temp = temp -> next;
  }
  return t;
}

template <class Element>
Set<Element> Set<Element>::operator-(const Set<Element>& s) const
{
  Set<Element> t;
  Node<Element> *temp = head;
  while(temp != NULL){
    t.insert(temp -> value);
    temp = temp -> next;
  }
  Node<Element> *stemp = s.head;
  while(stemp != NULL){
    t.remove(stemp -> value);
    stemp = stemp -> next;
  }
  return t;
}

template <class Element>
string Set<Element>::toString() const
{
  stringstream ss;
  if (length == 0){
    ss << "{}";
    return ss.str();
  }
  ss << "{";
  Node<Element> *temp = head;
  while(temp->next != NULL){
    ss << temp -> value << ",";
    temp = temp -> next;
  }
  ss << temp->value << "}";
  return ss.str();
}

template <class Element>
ostream& operator<<(ostream& stream, const Set<Element>& s)
{
   stream << s.toString();
   return stream;
}
