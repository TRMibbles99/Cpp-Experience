#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include <iostream>
using namespace std;

template<typename T>
class Node
{
public:
  T element;  // Element contained in the node
  Node<T>* next; // Pointer to the next node

  Node() // No-arg constructor
  {
    next = NULL;
    //next=nullptr;
  }

  Node(T element) // Constructor
  {
    this->element = element;
    next = NULL;
  }
};


template<typename T>
class LinkedList
{
public:
  LinkedList();
  void addFirst(T element);
  void addLast(T element);
  void add(int index, T element);
  void printList() const;
  int getSize() const;
  T get(int index) const;
  T removeFirst() throw (runtime_error);
  T removeLast();
  T removeAt(int index) throw (runtime_error);
  bool remove(T element); // q2. attendance assignment- remove first element but more general it can be more than one remove
  bool contains(T element); // q1. attendance assignment
  void clear();

private:
  Node<T>* head;
	Node<T>* tail;
  int size;
};

template<typename T>
LinkedList<T>::LinkedList()
{
  head = tail = NULL;
  size = 0;
}


template<typename T>
void LinkedList<T>::addFirst(T element)
{
  //Create a node dynamically
  Node<T>* newNode = new Node<T>(element);
  //make a connection between newnode and old first node
  newNode->next = head;
  // make newnode as list first node
  head = newNode;
  size++;

  if (tail == NULL)
    tail = head;
}

template<typename T>
void LinkedList<T>::addLast(T element)
{
    if (tail == NULL)
    {
        head = tail = new Node<T>(element);
    }
    else {
        tail->next = new Node<T>(element);
        tail = tail->next;
    }

    size++;
}
template<typename T>
void LinkedList<T>::add(int index, T element)
{
    if (index == 0)
        addFirst(element);
    else if (index >= size)
        addLast(element);
    else
    {
        Node<T> *current = head;
        for (int i = 1; i < index; i++)
            current = current->next;
        Node<T> *temp = current->next;
        current->next = new Node<T>(element);
        (current->next)->next = temp;
        size++;
    }
}

template<typename T>
T LinkedList<T>::get(int index) const
{
  if (index < 0 || index > size - 1)
    throw runtime_error("Index out of range");

  Node<T>* current = head;
  for (int i = 0; i < index; i++)
    current = current->next;

  return current->element;
}


template<typename T>
int LinkedList<T>::getSize() const
{
  return size;
}

template<typename T>
void LinkedList<T>::printList() const{
    Node<T> * temp=head;
    if (size>0){
        for (int i=0;i<size;i++){
            cout<<temp->element<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    else
    cout<<"list is empty"<<endl;
}
template<typename T>
T LinkedList<T>::removeFirst() throw (runtime_error)
{
    if (size == 0)
        throw runtime_error("No elements in the list");
        else
        {
            Node<T> *temp = head;
            head = head->next;
            size--;
            T element = temp->element;
            delete temp;
            return element;
        }
}

template<typename T>
T LinkedList<T>::removeLast()
{
    if (size == 0)
        throw runtime_error("No elements in the list");
    else if (size == 1)
    {
        Node<T> *temp = head;
        head = tail = NULL;
        size = 0;
        T element = temp->element;
        delete temp;
        return element;
    }
    else
    {
        Node<T> *current = head;

        for (int i = 0; i < size - 2; i++)
            current = current->next;

        Node<T> *temp = tail;
        tail = current;
        tail->next = NULL;
        size--;
        T element = temp->element;
        delete temp;
        return element;
    }
}

template<typename T>
T LinkedList<T>::removeAt(int index) throw (runtime_error)
{
    if (index < 0 || index >= size)
        throw runtime_error("Index out of range");
        else if (index == 0)
            return removeFirst();
        else if (index == size - 1)
            return removeLast();
        else {
            Node<T>* previous = head;
            for (int i = 1; i < index; i++)
            {
                previous = previous->next;
            }
            Node<T>* current = previous->next;
            previous->next = current->next;
            size--;
            T element = current->element;
            delete current;
            return element;
        }
}















#endif
