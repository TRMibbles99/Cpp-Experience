all: shoppingUnitTest myShoppingList

shoppingUnitTest: shoppingUnitTest.o shoppingList.o item.o
	g++ shoppingUnitTest.o shoppingList.o item.o -o shoppingUnitTest

myShoppingList:myShoppingList.o shoppingList.o item.o
	g++ myShoppingList.o shoppingList.o item.o -o myShoppingList

shoppingUnitTest.o: shoppingUnitTest.cpp shoppingList.h item.h
	g++ -c shoppingUnitTest.cpp -o shoppingUnitTest.o

myShoppingList.o:myShoppingList.cpp shoppingList.h item.h
	g++ -c myShoppingList.cpp -o myShoppingList.o

shoppingList.o:shoppingList.cpp item.h
	g++ -c shoppingList.cpp -o shoppingList.o

item.o: item.cpp item.h
	g++ -c item.cpp -o item.o
