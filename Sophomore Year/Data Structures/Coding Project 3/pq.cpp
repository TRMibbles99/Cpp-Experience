// pq.cpp

// These 3 constructors just call the corresponding MinHeap constructors.  That's all.
template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue() : MinHeap<KeyType>()
{ }

template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(int n) : MinHeap<KeyType>(n)
{ }

template <class KeyType>
MinPriorityQueue<KeyType>::MinPriorityQueue(const MinPriorityQueue<KeyType>& pq) : MinHeap<KeyType>(pq)
{ }

// Functions

//Precondition: Take in a MPQ
//Postcondition: return pointer of min
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::minimum() const
{
		return A[0];
}

//Precondition: Take in a MPQ
//Postcondition: Return pointer of min and remove min from MPQ
template <class KeyType>
KeyType* MinPriorityQueue<KeyType>::extractMin()
{
		if (heapSize == 0)
		{
				throw EmptyError();
		}
		else
		{
				KeyType* min = A[0];
				swap(0, heapSize-1);
				heapSize = heapSize - 1;
				heapify(0);
				return min;
		}
}

//Precondition: Takes in key and index. Have a valid MPQ
//Postcondition: Has moved key from index to proper place in MPQ
template <class KeyType>
void MinPriorityQueue<KeyType>::decreaseKey(int index, KeyType* key)
{
		if (*(key) < *(A[index]))
		{
				throw KeyError();
		}
		A[index] = key;
		while (index > 0 && *(A[parent(index)]) > *(A[index]))
		{
				swap(index,parent(index));
				index = parent(index);
		}
}

//Precondition: Takes in key and have a valid MPQ
//Postcondition: Places key at end of MPQ
template <class KeyType>
void MinPriorityQueue<KeyType>::insert(KeyType* key)
{
		if (capacity == heapSize)
		{
			 throw FullError();
		}
		else
		{
				heapSize = heapSize + 1;
				A[heapSize-1] = key;
				decreaseKey(heapSize-1, key);
		}
}

//Precondition: Takes in MPQ
//Postcondition: Returns true or false based off if MPQ has items in it
template <class KeyType>
bool MinPriorityQueue<KeyType>::empty() const
{
		if (heapSize > 0)
		{
				return false;
		}
		else
		{
				return true;
		}
}

//Precondition: Have a MPQ
//Postcondition: returns number of items in MPQ
template <class KeyType>
int MinPriorityQueue<KeyType>::length() const
{
		return heapSize;
}

// toString
template <class KeyType>
std::string MinPriorityQueue<KeyType>::toString() const
{
	std::stringstream ss;

	if (heapSize == 0)
	{
		ss << "[ ]";
	}
	else
	{
		ss << "[";
		for (int index = 0; index < heapSize - 1; index++)
			ss << *(A[index]) << ", ";
		ss << *(A[heapSize - 1]) << "]";
	}
	return ss.str();
}

template <class KeyType>
std::ostream& operator<<(std::ostream& stream, const MinPriorityQueue<KeyType>& pq)
{
	stream << pq.toString();

	return stream;
}
