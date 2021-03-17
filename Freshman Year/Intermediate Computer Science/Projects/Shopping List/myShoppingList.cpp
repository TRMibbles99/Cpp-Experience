 #include <iostream>
 #include <stdexcept>
 #include <string>
 #include "shoppingList.h"
 
 using namespace std;


 int main()
 {
   ShoppingList listA;

   // Add elements to the list
   listA.addItem("Strawberry", 2);
   listA.addItem("Tuna", 5);
   listA.addItem("Celery",3);
   listA.addItem("Salmon",4);
   listA.addItem("Bread",10);
   listA.addItem("Milk",1);
   listA.addItem("Apple",20);
   listA.addItem("Lettuce",8);
   listA.addItem("Kiwi",16);
   listA.addItem("Kale",6);
  
   cout << "\n(1) Print listA: " <<endl;
   listA.printShoppingList();
   
   listA.removeItem(3);
   cout << "\n(2) after remove item at index 3" << endl;
   listA.printShoppingList();

  
   listA.updateQuantity(5,13);
   cout << "\n(3) Update the 5th item in list quantity as 13: " << endl;
   listA.printShoppingList();

   ShoppingList listB;
   listB.addItem("Strawberry",1);
   listB.addItem("Blueberry",2);
   listB.addItem("Celery",1);
   listB.addItem("Salmon",2);
   listB.addItem("Bread",3);
   listB.addItem("Banana",10);
   listB.addItem("Apple",10);
   listB.addItem("Lettuce",8);
   listB.addItem("Cheese",4);
   listB.addItem("Kale",6);

   cout << "\n(4) Print listB: " << endl;
   listB.printShoppingList();
    
   if (listA.addAll(listB))
   {
     cout << "\n(5) Print listA after adding listB: " << endl;
     listA.printShoppingList();
   }



   listB.clearShoppingList();
   cout << "\n(6) Print cleared listB: " <<endl;
   listB.printShoppingList();

   ShoppingList listC;
   listC.addItem("Strawberry",1);
   listC.addItem("Tuna",2);
   listC.addItem("Celery",4);
   listC.addItem("Salmon",2);
   listC.addItem("Bread",3);
   listC.addItem("Milk",15);
   listC.addItem("Apple",10);
   listC.addItem("Lettuce",8);
   listC.addItem("Kiwi",4);
   listC.addItem("Kale",6);
   listC.addItem("Yogurt",3);

   cout << "\n(7) Print listC: " << endl;
   listC.printShoppingList();

   if (listA.removeReduceAll(listC))
   {
     cout << "\n(8) Print listA after reducing by listC: " <<endl;
     listA.printShoppingList();
   }




   return 0;
 }
