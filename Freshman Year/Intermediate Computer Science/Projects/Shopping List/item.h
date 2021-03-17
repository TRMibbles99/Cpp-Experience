#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
using namespace std;    

class Item
{
private:
    string itemName;
    int quantity;

public:
    Item();
    Item(string);
    Item(string, int);
    string getName();
    int getQuantity();
    int setQuantity(int);

    void operator+(int);
    void operator-(int);

};
ostream& operator<<(ostream& out, Item& i);

#endif