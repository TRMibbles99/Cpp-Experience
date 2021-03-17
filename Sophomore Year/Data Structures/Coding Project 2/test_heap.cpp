#include <iostream>
#include <stdexcept>
#include <string>
#include <cassert>
#include <sys/time.h>
#include "heap.cpp"
using namespace std;

void test_same(MinHeap<int>& heapA, MinHeap<int>& heapB){
  for(int i = 0; i <= heapA.heapSize - 1; i++){
    assert(heapA.A[i] == heapB.A[i]);
  }
}

void test_isheap(MinHeap<int>& heap){
  int left;
  int right;
  for(int i = 0; i <= heap.heapSize - 1; i++){
    left = heap.leftChild(i);
    right = heap.rightChild(i);
    if(left < heap.heapSize && right < heap.heapSize){
      assert(heap.A[i] <= heap.A[left]);
      assert(heap.A[i] <= heap.A[right]);
    }
  }
}

void test_construct(MinHeap<int>& heap){
  assert(heap.capacity != 0);
}

void test_heapsort(int a[], int n){
  for(int i = 1; i <= n-1; i++){
    assert(a[i-1] <= a[i]);
  }
}

void test_isempty(MinHeap<int>& heap){
  assert(heap.heapSize == 0);
}

void merge(int a[], int s1, int e1, int s2, int e2){
  int b[e1-s1+1];
  int i = s1;
  int j = s2;
  int k = 0;

  while(i <= e1 && j <= e2){
    if (a[i] < a[j]){
      b[k++] = a[i++];
    }else{
      b[k++] = a[j++];
    }
  }

  while(i <= e1){
    b[k++] = a[i++];
  }
  while(j <= e2){
    b[k++] = a[j++];
  }

  i = s1;
  k = 0;
  while(i <= e2){
    a[i++] = b[k++];
  }
}

void mergeSort(int a[], int low, int high){
  if(low < high){
    int mid = (low+high)/2;
    mergeSort(a,low,mid);
    mergeSort(a,mid+1,high);
    merge(a,low,mid,mid+1,high);
  }
}

void insertionSort(int a[], int n){
  for(int i = 1; i < n; i++){
    int j = i;
    while(j > 0 && a[j] < a[j-1]){
      int temp = a[j];
      a[j] = a[j-1];
      a[j-1] = temp;
      j--;
    }
  }
}

void heapTime(){
  for(int i = 1; i <= 100; i++){
    int n = 10000 + i * 500;
    int heapA[n];
    for(int j = 0; j < n; j++){
      int randNum = rand() % n + 1;
      heapA[j] = randNum;
    }
    MinHeap<int> heapT(heapA, n);

    timeval timeBef, timeAf;
    long diffSec, diffUSec;
    int sortedA[n];

    gettimeofday(&timeBef, NULL);
    heapT.heapSort(sortedA);
    gettimeofday(&timeAf, NULL);

    diffSec = timeAf.tv_sec - timeBef.tv_sec;
    diffUSec = timeAf.tv_usec - timeBef.tv_usec;
    cout << diffSec + diffUSec/1000000.0 << endl;
  }
}

void mergeTime(){
  for(int i = 1; i <= 100; i++){
    int n = 10000 + i * 500;
    int mergeA[n];
    for(int j = 0; j < n; j++){
      int randNum = rand() % n + 1;
      mergeA[j] = randNum;
    }

    timeval timeBef, timeAf;
    long diffSec, diffUSec;


    gettimeofday(&timeBef, NULL);
    mergeSort(mergeA, 0, n);
    gettimeofday(&timeAf, NULL);

    diffSec = timeAf.tv_sec - timeBef.tv_sec;
    diffUSec = timeAf.tv_usec - timeBef.tv_usec;
    cout << diffSec + diffUSec/1000000.0 << endl;
  }
}

void insertionTime(){
  for(int i = 1; i <= 100; i++){
    int n = 10000 + i * 500;
    int insertA[n];
    for(int j = 0; j < n; j++){
      int randNum = rand() % n + 1;
      insertA[j] = randNum;
    }

    timeval timeBef, timeAf;
    long diffSec, diffUSec;

    gettimeofday(&timeBef, NULL);
    insertionSort(insertA, n);
    gettimeofday(&timeAf, NULL);

    diffSec = timeAf.tv_sec - timeBef.tv_sec;
    diffUSec = timeAf.tv_usec - timeBef.tv_usec;
    cout << diffSec + diffUSec/1000000.0 << endl;
  }
}

int main(){
  int a[] = {1,2,3,4};
  int b[] = {2,1,3,4};
  int c[] = {1,4,3,5,9,8,3,2,6,5};

  MinHeap<int> heap0;
  test_isheap(heap0);
  test_construct(heap0);
  test_isempty(heap0);

  cout << "heap0: " << heap0 << endl;

  MinHeap<int> heap1 = MinHeap<int>(a,4);
  test_isheap(heap1);
  test_construct(heap1);

  MinHeap<int> heap2 = MinHeap<int>(b,4);
  test_isheap(heap2);
  test_construct(heap2);

  cout << "heap1: " << heap1 << endl;
  cout << "heap2: " << heap2 << endl;

  test_same(heap1, heap2);

  MinHeap<int> heap3 = MinHeap<int>(c,10);
  test_isheap(heap3);
  test_construct(heap3);

  cout << "heap3: " << heap3 << endl;

  int s[10];
  heap3.heapSort(s);
  test_heapsort(s, 10);

  cout << "sorted heap3 list: ";
  for(int i = 0; i < 10; i++){
    cout << s[i] << " ";
  }

  cout << endl;


  // heapTime();
  // mergeTime();
  // insertionTime();

  return 0;
}
