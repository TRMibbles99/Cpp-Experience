// heap.cpp

#include <sstream>
#include <iostream>
#include "heap.h"

// Implement heap methods here.

// Use the following toString() for testing purposes.

//The default constructor of MinHeap making capacity
//default (100) and heapSise 0.
template <class KeyType>
MinHeap<KeyType>::MinHeap(int n){
	A = new KeyType[n];
	heapSize = 0;
	capacity = n;
}

//Calls heapifyR
//pre-condition: the parent of the node are in correct order
//post-condition: the node and its children are in correct order
template <class KeyType>
void MinHeap<KeyType>::heapify(int index){
	heapifyR(index);
}

//builds a correct min heap
template <class KeyType>
void MinHeap<KeyType>::buildHeap(){
	heapSize = capacity;
	for(int i = (capacity/2)-1; i >= 0; i--){
		heapify(i);
	}
}

//A recursive version of heapifyR
template <class KeyType>
void MinHeap<KeyType>::heapifyR(int index){
	int left = leftChild(index);
	int right = rightChild(index);
	int smallest = index;

	//checks if left side is smaller than index
	if ((left < heapSize) && (A[left] < A[index])){
		smallest = left;
	} else {
		smallest = index ;
	}

	//check if right side is smaller than index
	if ((right < heapSize) && (A[right] < A[smallest])){
		smallest = right;
	}

	//if the smallest is not at the index then swap and repeat
	if (smallest != index){
		swap(index, smallest);
		heapifyR(smallest);
	}
}

//An iterative version of heapify
template <class KeyType>
void MinHeap<KeyType>::heapifyI(int index){
	int left = leftChild(index);
	int right = rightChild(index);
	int smallest = index;
	int i = index;

	//runs a while loop until the index that is being looked
	//at is larger than the heapSize (when we reach past a leaf)
	while(i < heapSize){
		if ((left < heapSize) && (A[left] < A[i])){
			smallest = left;
		} else {
			smallest = i;
		}
		if ((right < heapSize) && (A[right] < A[smallest])){
			smallest = right;
		}

		//if smallest is at the current index then swap and update
		//everything before rerunning, if not break loop.
		if (smallest != i){
			swap(i, smallest);
			i = smallest;
			left = leftChild(i);
			right = rightChild(i);
		}else{
			break;
		}
	}
}

//Swaps two items in a heap using the index
template <class KeyType>
void MinHeap<KeyType>::swap(int index1, int index2){
	KeyType temp = A[index1];
	A[index1] = A[index2];
	A[index2] = temp;
}

//Copies a heap into a new heap object
template <class KeyType>
void MinHeap<KeyType>::copy(const MinHeap<KeyType>& heap){
	heapSize = heap.heapSize;
	capacity = heap.capacity;
	A = new KeyType[capacity];
	for(int i = 0; i < heapSize; i++){
		A[i] = heap.A[i];
	}
}

//destroys heap
template <class KeyType>
void MinHeap<KeyType>::destroy(){
	heapSize = 0;
	capacity = 0;
	delete[] A;
}

//A second constructor for MinHeap, creates heap using a list and list size
template <class KeyType>
MinHeap<KeyType>::MinHeap(KeyType initA[], int n){
	A = new KeyType[n];
	for(int i = 0; i < n; i++){
		A[i] = initA[i];
	}
	capacity = n;
	heapSize = n;
	buildHeap();
}

//Another constructor that creates a heap from another heap
template <class KeyType>
MinHeap<KeyType>::MinHeap(const MinHeap<KeyType>& heap){
	copy(heap);
}

//deconstructor
template <class KeyType>
MinHeap<KeyType>::~MinHeap(){
	destroy();
}

//makes a list with sorted values (ascending) from a heap, destorying
//the heap afterwards
template <class KeyType>
void MinHeap<KeyType>::heapSort(KeyType sorted[]){
	buildHeap();
	int x = 0;
	for(int i = heapSize - 1; i >= 0; i--){
		sorted[x] = A[0];
		swap(0, i);
		heapSize = heapSize - 1;
		heapify(0);
		x++;
	}
}

//Makes the equal operator copy one heap to another.
template <class KeyType>
MinHeap<KeyType>& MinHeap<KeyType>::operator=(const MinHeap<KeyType>& heap){
	if (this != &heap){
		destroy();
		copy(heap);
	}
	return *this;
}

template <class KeyType>
std::string MinHeap<KeyType>::toString() const
{
	std::stringstream ss;

	if (capacity == 0)
		ss << "[ ]";
	else
	{
		ss << "[";
		if (heapSize > 0)
		{
			for (int index = 0; index < heapSize - 1; index++)
				ss << A[index] << ", ";
			ss << A[heapSize - 1];
		}
		ss << " | ";
		if (capacity > heapSize)
		{
			for (int index = heapSize; index < capacity - 1; index++)
				ss << A[index] << ", ";
			ss << A[capacity - 1];
		}
		ss << "]";
	}
	return ss.str();
}

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinHeap<KeyType>& heap)
{
	return stream << heap.toString();
}
