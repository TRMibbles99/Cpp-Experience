// heap.cpp

#include <sstream>

using namespace std;

// Implement heap methods here.

template <class KeyType>
MinHeap<KeyType>::MinHeap()
{
		//A = new KeyType[0];
		A = NULL;
		heapSize = 0;
		capacity = 0;
}

//Precondition: N/A
//Postcondition: Heap with capacity n.
template <class KeyType> //default constructor
MinHeap<KeyType>::MinHeap(int n)
{
		//A = new KeyType[n];
		A = new KeyType*[n]; //A = new KeyType*[n];
		heapSize = 0;
		capacity = n;
}

//Precondition: Array of length n.
//Postcondition: Heap with values from array with capacity and heapSize n.
template <class KeyType> //construct heap
MinHeap<KeyType>::MinHeap(KeyType initA[], int n)
{
		capacity = n;
		heapSize = 0;
		A = new KeyType*[n];
		for (int i = 0; i < n; i++)
		{
				A[i] = initA[i];
				heapSize++;
		}
		buildHeap();
}

//Precondition: insert a heap
//Postcondition: outputs a heap that is the same of the inputed heap
template <class KeyType> //copy constructor
MinHeap<KeyType>::MinHeap(const MinHeap<KeyType>& heap)
{
		copy(heap);
}

//Precondition: Heap exists
//Postcondition: heap is destroyed
template <class KeyType> //destructor
MinHeap<KeyType>::~MinHeap()
{
		destroy();
}

//Precondition: Have a heap with values and empty array.
//Postcondition: Values from heap will be entered in sorted into the array.
template <class KeyType> // heapsort, return result in sorted
void MinHeap<KeyType>::heapSort(KeyType sorted[])
{
		//buildHeap();
		int x = 0;
		for (int i = heapSize-1; i >= 0; i--)
		{
			 sorted[x] = A[0];
			 swap(0,i);
			 heapSize = heapSize - 1;
			 heapify(0);
			 x++;
		}
}

//Precondition: Index of heap.
//Postcondition: children should be larger than the parent
template <class KeyType> //heapify
void MinHeap<KeyType>::heapify(int index)
{
		int small;
		int left = leftChild(index);
		int right = rightChild(index);
		if (left < heapSize && *(A[left]) < *(A[index]))
				small = left;
		else
				small = index;
		if (right < heapSize && *(A[right]) < *(A[index]) && *(A[left]) > *(A[right]))
				small = right;
		if (small != index)
		{
				swap(index, small);
				heapify(small);
		}
}

//Precondition: a valid heap
//Postcondition: sets heap to be equal to the values of the other heap
template <class KeyType> //assignment operator
MinHeap<KeyType>& MinHeap<KeyType>::operator=(const MinHeap<KeyType>& heap)
{
		if(this != &heap)
		{
				this -> destroy();
				this -> copy(heap);
		}
		return *this;
		/*
		A = new KeyType[heap.capacity];
		heapSize = heap.heapSize;
		capacity = heap.capacity;
		for (int i = 0; i < capacity; i++)
				A[i] = heap[i];
		//return temp; */
}

//Precondition: A vaild heap array.
//Postcondition: heapifys the entire array
template <class KeyType> //buildHeap
void MinHeap<KeyType>::buildHeap()
{
		heapSize = capacity;
		for (int i = (capacity/2)-1; i >= 0; i--)
				heapify(i);
}

//Precondition: Index of heap.
//Postcondition: children should be larger than the parent
template <class KeyType> //recursive heapify
void MinHeap<KeyType>::heapifyR(int index)
{
	int small;
	int left = leftChild(index);
	int right = rightChild(index);
	if (left < heapSize && A[left]->value < A[index]->value)
			small = 1;
	else
			small = index;
	if (right < heapSize && A[right]->value < A[index]->value)
			small = right;
	if (small != index)
	{
			swap(index, small);
			heapify(small);
	}
}

//Precondition: Index of heap.
//Postcondition: children should be larger than the parent
template <class KeyType> //iterative heapify
void MinHeap<KeyType>::heapifyI(int index)
{
		int small;
		int left = leftChild(index);
		int right = rightChild(index);
		while (index < (capacity/2)+1 && index > -1)
		{
				if (A[left] < heapSize && A[left] < A[index])
						small = left;
				else
						small = index;
				if (A[right] < heapSize && A[right] < A[index])
						small = right;
				if(small != index)
				{
						swap(index, small);
						index = small;
				}
				else
						int i = (capacity/2)+1;
		}
}

//Precondition: two index values
//Postcondition: swaps around the values of heap at the two indexs.
template <class KeyType> //swap elements
void MinHeap<KeyType>::swap(int index1, int index2)
{
		KeyType* x = A[index1];
		KeyType* y = A[index2];
		A[index1] = y;
		A[index2] = x;
}

//Precondition: Input a heap.
//Postcondition: sets heap to be a copy of the inputed heap.
template <class KeyType> //copy heap to this heap
void MinHeap<KeyType>::copy(const MinHeap<KeyType>& heap)
{
		A = new KeyType*[heap.capacity];
		heapSize = heap.heapSize;
		capacity = heap.capacity;
		for (int i = 0; i < heapSize; i++)
				A[i] = heap.A[i];
}

//Precondition: heap
//Postcondition: deallocates all data within the heap
template <class KeyType> //deallocate heap
void MinHeap<KeyType>::destroy()
{
		if (capacity != 0)
		{
				capacity = 0;
				heapSize = 0;
				delete A;
		}
}

// Use the following toString() for testing purposes.

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
