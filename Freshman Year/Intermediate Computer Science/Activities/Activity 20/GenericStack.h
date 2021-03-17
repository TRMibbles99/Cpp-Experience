#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template<typename T>
class Stack
{
public:
  Stack();
  bool empty() const;
  T peek() const;
  void push(T value);
  T pop();
  int getSize() const;
  void printStack();
  bool contains(T element);

  /* Question1
  Add the printStack function into the Stack class as an instance function
  to display all the elements in the stack.*/

  /* Question2
  Add the contains(T element) function into the Stack class as an instance function
  to check whether the element is in the stack.
  */

private:
  T elements[100];
  int size;
};

template<typename T>
Stack<T>::Stack()
{
  size = 0;
}


template<typename T>
bool Stack<T>::empty() const
{
  return (size == 0);
}

template<typename T>
void Stack<T>::printStack(){
  for (int i = 0; i < getSize(); i++){
    cout << elements[i] << " ";
  }
  cout << endl;
}

template<typename T>
bool Stack<T>::contains(T element){
  for (int i = 0; i < getSize(); i++){
    if (elements[i] == element){
      return true;
    }
  }
  return false;
}

template<typename T>
T Stack<T>::peek() const
{
  return elements[size - 1];
}

template<typename T>
void Stack<T>::push(T value)
{
  elements[size++] = value;
}

template<typename T>
T Stack<T>::pop()
{
  return elements[--size];
}

template<typename T>
int Stack<T>::getSize() const
{
  return size;
}


#endif
