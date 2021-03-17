#include "item.h"
#include "shoppingList.h"
#include <iostream>
#include <string>
using namespace std;


 Node::Node() // No-arg constructor
  {
    next = NULL;
    //next=nullptr;
  }

 
  Node::Node(Item element) // Constructor
  {
    this->element = element;
    next = NULL;
  }


ShoppingList::ShoppingList()
{
    head = tail = NULL;
    size = 0;
}

void ShoppingList::addItem(string name, int num)
{
    Item i1 = Item(name, num);
    if(size < 1)
    {
       head = tail = new Node(i1);
       size++;
    }else if(name < head -> element.getName())
    {
        Node* temp = head;
        head = new Node(i1);
        head -> next = temp;
        size++;
    
    }
    else{
        Node* current = head;
        Item i3 = current -> element;
        if(i3.getName() == name)
        {
            updateQuantity(0, i3.getQuantity() + num);
            current = current -> next;
            
        }else{
            int count = 1;
            while(current != tail)
            {
                Item i2 = current -> next -> element;
                if(name < i2.getName())
                {
                    Node* temp = current -> next;
                    current -> next = new Node(i1);
                    current -> next -> next = temp;
                    size++;
                    break;
                }
                if(name == i2.getName())
                {
                    updateQuantity(count, i2.getQuantity() + num);
                    break;
                }
                current = current -> next; 
                count++;
            }
        }
        if(current == tail)
        {
            tail -> next = new Node(i1);
            tail = tail -> next;
            size++;
        }
        
    }
}

void ShoppingList::removeItem(int index)
{
    if(index == 0)
    {
        Node* temp = head;
        head = head -> next;
        size--;
        delete temp;
    }
    else if(index == size - 1)
    {
        Node* temp = head;
        for(int i = 0; i < index; i++)
        {
            temp = temp -> next;
        }
        Node* current = tail;
        tail = temp;
        tail -> next = NULL;
        size--;
        delete current;

    }else if(index > 0 && index < size - 1)
    {
        Node* temp = head;
        for(int i = 0; i < index - 1; i++)
        {
            temp = temp -> next;
        }
        Node* current = temp -> next;
        temp-> next = current -> next;
        size --;
        delete current;
    }else{
        cout << "Index out of range" << endl;
        return;
    }

}


void ShoppingList::updateQuantity(int index, int num)
{
    Node* temp = head;
    for(int i = 0; i < index; i++)
    {
        temp = temp -> next;
    }
    Item i1 = temp -> element;
    i1.setQuantity(num);
    temp -> element = i1; 

} 
void ShoppingList::clearShoppingList()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head-> next;
        delete temp;
    }
    tail = NULL;
    size = 0; 
}

void ShoppingList::printShoppingList()
{
    Node* temp = head;
    if(size == 0)
    {
        cout << "List is empty :(" << endl;
    }
    for(int i = 0; i < size; i++)
    {
        cout<< temp -> element << endl;
        temp = temp -> next; 
    }
}

int ShoppingList::getSize()
{
    return size;
}

Item ShoppingList::getItem(int index){
  Node* temp = head;
  for(int i = 0; i < index; i++)
  {
    temp = temp -> next;
  }
  Item i1 = temp -> element;
  return i1;
}

bool ShoppingList::addAll(ShoppingList anotherList)
{
  for(int i = 0; i < anotherList.getSize(); i++){
    Item i1 = anotherList.getItem(i);
    addItem(i1.getName(), i1.getQuantity());
  }
  return true;
}

bool ShoppingList::removeReduceAll(ShoppingList anotherList)
{
  for(int i = 0; i < anotherList.getSize(); i++){
    Item i1 = anotherList.getItem(i);
    int counter = 0;
    while(counter < size){
      Item i2 = getItem(counter);
      if(i1.getName() == i2.getName()){
        updateQuantity(counter, i2.getQuantity()-i1.getQuantity());
        Item newI = getItem(counter);
        if(newI.getQuantity() <= 0){
          removeItem(counter);
        }
        break;
      }
      counter++;
    }
  }
  return true;
}