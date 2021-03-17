#include <iostream>
using namespace std;

void selectionSort(int a[], int size, int index);
void swap(int a[], int index1, int index2);
void printArray(int a[], int size);


int main(){
  int size;
  cout << "How many items do you want to sort: ";
  cin >> size;
  int a[size];
  for(int i = 0; i < size; i++){
    int num;
    cout << "Number: ";
    cin >> num;
    a[i] = num;
  }
  selectionSort(a, size, 0);
  printArray(a, size);
  return 0;
}

void selectionSort(int a[], int size, int index){
  if(index >= size){
    return;
  }

  int min = index;
  for(int i = index + 1; i < size; i++){
    if(a[i]<a[min])
    min = i;
  }

  swap(a, min, index);
  selectionSort(a, size, index+1);
}

void swap(int a[], int index1, int index2){
  int temp = a[index1];
  a[index1] = a[index2];
  a[index2] = temp;
}

void printArray(int a[], int size){
  for(int i = 0; i < size; i++){
    cout << a[i] << ", ";
  }
  cout << endl;
}
