#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;

int divHash(string s, int slots){
  int k = 0;
  char c;

  for(int i = 0; i < s.length(); i++){
    c = s[i];
    k = c * pow(11,i) + k;
  }

  return k % slots;
}

int multHash(string s, int slots){
  int k = 0;
  float A = 0.618;
  char c;

  for(int i = 0; i < s.length(); i++){
    c = s[i];
    k = c + k;
  }

  int B = A*k;
  float C = A*k;
  return floor((C-B)*slots);
}

int main(){
  string word;
  int index;
  int a[1000] = {};

  ifstream file("dict.txt");
  while(!file.eof()){
    getline(file, word, '\n');
    index = divHash(word, 1000);
    a[index] = a[index] + 1;
  }
  file.close();

  for(int i = 0; i < 1000; i++){
    cout << a[i] << endl;
  }
}
