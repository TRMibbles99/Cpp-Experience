#include <iostream>
using namespace std;

int main(){
  int subtotal;
  int gratuity_rate;
  double gratuity;

  cout<<"Enter the subtotal: ";
  cin>>subtotal;
  cout<<"Enter the gratuity: ";
  cin>>gratuity_rate;

  gratuity = (gratuity_rate/100.0)*subtotal;

  cout<<"The gratuity is $"<<gratuity<<" and the total is $"<<subtotal+gratuity<<endl;
  return 0;
}
