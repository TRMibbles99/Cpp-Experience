#include <iostream>
#include <cassert>
#include "shoppingList.h"
#include "item.h"
using namespace std;

int main(){
  ShoppingList slist;
  assert(slist.getSize() == 0);
  slist.addItem("A", 2);
  assert(slist.getSize() != 0);
  assert(slist.getSize() == 1);
  assert(slist.getItem(0).getName() == "A");
  assert(slist.getItem(0).getQuantity() == 2);
  slist.addItem("B", 5);
  assert(slist.getSize() == 2);
  assert(slist.getItem(1).getName() == "B");
  assert(slist.getItem(1).getQuantity() == 5);
  slist.addItem("C", 5);
  slist.removeItem(1);
  assert(slist.getSize() == 2);
  assert(slist.getItem(0).getName() == "A");
  assert(slist.getItem(0).getQuantity() == 2);
  assert(slist.getItem(1).getName() == "C");
  assert(slist.getItem(1).getQuantity() == 5);
  slist.updateQuantity(0,3);
  assert(slist.getItem(0).getName() == "A");
  assert(slist.getItem(0).getQuantity() == 3);

  ShoppingList slist2;
  assert(slist2.getSize() == 0);
  slist2.addItem("B", 4);
  assert(slist2.getSize() == 1);
  assert(slist2.getItem(0).getName() == "B");
  assert(slist2.getItem(0).getQuantity() == 4);
  slist2.addItem("C", 7);
  assert(slist2.getSize() == 2);
  assert(slist2.getItem(1).getName() == "C");
  assert(slist2.getItem(1).getQuantity() == 7);
  assert(slist.addAll(slist2));
  assert(slist.getSize() == 3);
  assert(slist.getItem(0).getName() == "A");
  assert(slist.getItem(0).getQuantity() == 3);
  assert(slist.getItem(1).getName() == "B");
  assert(slist.getItem(1).getQuantity() == 4);
  assert(slist.getSize() == 3);
  assert(slist.getItem(2).getName() == "C");
  assert(slist.getItem(2).getQuantity() == 12);

  ShoppingList slist3;
  assert(slist3.getSize() == 0);
  slist3.addItem("A", 2);
  assert(slist3.getSize() == 1);
  assert(slist3.getItem(0).getName() == "A");
  assert(slist3.getItem(0).getQuantity() == 2);
  slist3.addItem("D", 4);
  assert(slist3.getSize() == 2);
  assert(slist3.getItem(1).getName() == "D");
  assert(slist3.getItem(1).getQuantity() == 4);
  slist3.addItem("C", 7);
  assert(slist3.getSize() == 3);
  assert(slist3.getItem(1).getName() == "C");
  assert(slist3.getItem(1).getQuantity() == 7);
  assert(slist.removeReduceAll(slist3));
  assert(slist.getSize() == 3);
  assert(slist.getItem(0).getName() == "A");
  assert(slist.getItem(0).getQuantity() == 1);


  slist.clearShoppingList();
  slist2.clearShoppingList();
  slist3.clearShoppingList();
  assert(slist.getSize() == 0);
  assert(slist2.getSize() == 0);
  assert(slist3.getSize() == 0);

  cout << "Shopping Unit Test succeeded" << endl;

  return 0;
}
