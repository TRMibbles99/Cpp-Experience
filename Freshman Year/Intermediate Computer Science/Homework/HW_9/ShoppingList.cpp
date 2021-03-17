#include "Item.h"
#include "ShoppingList.h"

Item::Item(){
  name = " ";
  quantity = 0;
}

Item::Item(string newName){
  name = newName;
  quantity = 1;
}

Item::Item(string newName, int newQuantity){
  name = newName;
  quantity = newQuantity;
}

void Item::setQuantity(int newQuantity){
  quantity = newQuantity;
}

void Item::setName(string newName){
  name = newName;
}

string Item::getName(){
  return name;
}

int Item::getQuantity(){
  return quantity;
}

void Item::addQuantity(int num){
  quantity = quantity + num;
}

void Item::subQuantity(int num){
  if (quantity > num){
    quantity = quantity - num;
  }else{
    cout << "Invalid amount to subtract..." << endl;
  }
}

ostream& operator<<(ostream&, const Item& i1){
  out << i1.getName() << ": " << i1.getQuantity();
  return out;
}

ShoppingList::ShoppingList(){
  head = tail = NULL;
  size = 0;
}

void ShoppingList::addItem(string name, int quantity){
  Item item(name, quantity);
  if (size < 1){
    head = tail = new Node Item(item);
  }else{
    Node Item *current = head;
    for(int i = 1; i < size; i++){
      if (current.getName() < current->next.getName()){
        Node Item *temp = current->next;
        current->next = new Node Item(item);
        (current->next)->next = temp;
        break;
      }else if(i+1=size){
        tail->next = new Node Item(item);
        tail = tail->next;
      }
    }
  }
  size++;
}



void removeItem(int index) throw (runtime_error){
  if (index < 0 || index >= size || size == 0){
    throw runtime_error("Index out of range");
  }else if (index == 0){
    Node Item *temp = head;
    head = head->next;
    size--;
    Item element = temp->element;
    delete temp;
    return element;
  }else if (index == size - 1){
    if (size == 1){
      Node Item *temp = head;
      head = tail = NULL;
      size = 0;
      Item element = temp->element;
      delete temp;
      return element;
    }else{
      Node Item *current = head;

      for (int i = 0; i < size - 2; i++)
          current = current->next;

      Node Item *temp = tail;
      tail = current;
      tail->next = NULL;
      size--;
      Item element = temp->element;
      delete temp;
      return element;
    }
  }else{
    Node Item* previous = head;
    for (int i = 1; i < index; i++)
    {
        previous = previous->next;
    }
    Node Item* current = previous->next;
    previous->next = current->next;
    size--;
    Item element = current->element;
    delete current;
    return element;
  }
}

void ShoppingList::updateQuantity(int index, int num){
  if (index < 0 || index > size -1){
    throw runtime_error("Index out of range");
  }

  Node Item* current = head;
  for(int i = 0; i < index; i++){
    current = current->next;
  }
  current->element.setQuantity(num);
}

void ShoppingList::clearShoppingList(){
  while(head!=nullptr){
    Node Item* temp=head;
    head = head->next;
    delete temp;
  }
  tail=NULL;
  size = 0;
}

void ShoppingList::printShoppingList(){
  Node Item *temp = head;
  if (size > 0){
    for (int i=0;i<size;i++){
        cout<<temp->element<<" ";
        temp=temp->next;
    }
    cout<<endl;
  }else{
    cout << "List is empty..." << endl;
  }
}

//boolean ShoppingList::addAll(ShoppingList anotherList);
//boolean ShoppingList::removeReduceAll(ShoppingList anotherList);
