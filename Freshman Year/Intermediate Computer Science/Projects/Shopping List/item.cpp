#include "item.h"
#include <string>
#include <iostream>
using namespace std;

Item::Item()
{
    itemName = " ";
    quantity = 0;
}
Item::Item(string name)
{
    itemName = name;
    quantity = 1;
}
Item::Item(string name, int num)
{
    itemName = name;
    quantity = num;
}

string Item::getName()
{
    return itemName;
}
int Item::getQuantity()
{
    return quantity;
}

int Item::setQuantity(int num)
{
    quantity = num;
    return quantity;
}

void Item::operator+(int newQ)
{
    quantity = quantity + newQ;
}
void Item::operator-(int newQ)
{
    quantity = quantity - newQ;
}

ostream& operator<<(ostream& output, Item& i)
{
    output << "Name: " << i.getName() << " Quantitiy: " << i.getQuantity();
    return output; 
}