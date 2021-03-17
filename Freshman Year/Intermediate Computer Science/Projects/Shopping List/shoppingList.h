#ifndef SHOPPINGLIST_H
#define SHOPPINGLIST_H
#include "item.h"
#include <string>


class Node
{
public:
  Item element;  // Element contained in the node
  Node* next; // Pointer to the next node

  Node(); // No-arg constructor

  Node(Item element); // Constructor
};
 
class ShoppingList
{
    private:
    Node* head;
    Node* tail;
    int size;

    public:
    ShoppingList();
    
    void addItem(string, int);
    void removeItem(int);
    void updateQuantity(int, int); 
    void clearShoppingList();
    void printShoppingList();
    bool addAll(ShoppingList);
    bool removeReduceAll(ShoppingList);
    int getSize();
    Item getItem(int);
};

#endif
