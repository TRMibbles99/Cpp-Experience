CPPORTIONS = -std=c++11 -g
LDOPTIONS =

all: test_pq huffman

test_pq: heap.h heap.cpp pq.h pq.cpp test_pq.cpp
	g++ $(CPPOPTIONS) -o test_pq test_pq.cpp

huffman: heap.h pq.h node.h heap.cpp pq.cpp node.cpp huffman.cpp
	g++ $(CPPOPTIONS) -o huffman huffman.cpp

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean: tidy
	rm -f *.o
