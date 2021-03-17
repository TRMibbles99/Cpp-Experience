#include <iostream>
using namespace std;

//when converting to hexadecimal take 4 change using binary then take that number and use it for hexadecimal

void question7();
void question8();
void question10(int* a, int* b);

int main(){
  //p points to the integer variable
  //q3
  int *p;
  //q4
  int count = 10;
  p = &count;
  //q5
  cout << *p << endl;
  //q6 dont forget we are in base 16 (04BFA810 -> 04BFA818 -> 04BFA820)
  int list[] = {1, 2, 3, 4};
  p = list;
  for (int i = 0; i < 4; i++){
    cout << p+i << " " <<*(p+i)<<endl;
  }

  question7();
  question8();

  int j = 1;
  int k = 6;
  question10(&j, &k);
  cout << j << " " << k << endl;

  return 0;
}

void question7(){
  int list[6] = {11, 12, 13, 14, 15, 16};
  int* p = list;
  for (int i = 0; i < 6; i++){
    cout << "address: "<<p+i<< " " <<
    "value: " << *(list + i) << " " <<
    "value: " << list[i] << " " <<
    "value: " << *(p+i) << " " <<
    "value: " << p[i] << endl;
  }
}

void question8(){
  int count = 10;
  int *p;
  p = &count;
  cout << p << endl;
  cout << *p << endl;
  (*p)++;
  cout << *p << endl;
}

void question10(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
  cout << *a << " " << *b << endl;
}
