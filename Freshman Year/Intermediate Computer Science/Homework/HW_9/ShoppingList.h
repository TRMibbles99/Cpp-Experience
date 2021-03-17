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

class ShoppingList{
public:
  ShoppingList();

  void addItem(string, int);
  void removeItem(int);
  void updateQuantity(int, int);
  void clearShoppingList();
  void printShoppingList();
//  boolean addAll(ShoppingList anotherList);
  //boolean removeReduceAll(ShoppingList anotherList);

private:
  Node Item* head;
	Node Item* tail;
  int size;
};
