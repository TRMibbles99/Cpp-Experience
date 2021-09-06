#include <sstream>
#include <cmath>
#include <iostream>

class Dummy
{
public:
  int data;
  int hash;

  Dummy(){
    data = 0;
    hash = 0;
  }

  Dummy(int num, int slots){
    data = num;
    hash = num % slots;
  }

  bool operator==(const Dummy& d) const{
    return (data == d.data);
  }

  std::string toString() const{
    std::stringstream ss;
    ss << data;
    return ss.str();
  }

  friend ostream& operator<<(ostream& stream, const Dummy& d){
    stream << d.data;
    return stream;
  }
};
