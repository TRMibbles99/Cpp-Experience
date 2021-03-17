#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Item{
public:
  Item();
  Item(string);
  Item(string, int);

  void setQuantity(int);
  void setName(string);

  string getName();
  int getQuantity();

  void addQuantity(int);
  void subQuantity(int);

private:
  string name;
  int quantity;
};

ostream& operator<<(ostream&, const Item&);
