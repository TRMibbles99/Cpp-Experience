#include <iostream>
#include <cassert>
using namespace std;

#include <string>
#include "pq.h"

int main(void)
{
    //constructor test
    MinPriorityQueue<int> test1(10);
    assert(test1.length() == test1.heapSize);
    assert(test1.empty());

    int num1 = 3;
    int num2 = 4;
    int num3 = 6;
    int num4 = 5;
    int num5 = 7;
    int num6 = 12;
    int num7 = 2;
    int num8 = 1;
    int num9 = 4;
    int num10 = 6;

    test1.insert(&num1);
    test1.insert(&num2);
    test1.insert(&num3);
    test1.insert(&num4);
    test1.insert(&num5);
    test1.insert(&num6);
    test1.insert(&num7);
    test1.insert(&num8);
    test1.insert(&num9);
    test1.insert(&num10);

    //cout << test1 << endl;
    assert(test1.length() == test1.heapSize);

    //copy constructor test
    MinPriorityQueue<int> test2(test1);
    assert(test2.minimum() == test1.minimum());
    //cout << test2 << endl;
    //cout << test2.minimum() << endl;

    test2.extractMin();
    //cout << test2 << endl;
    assert(test2.minimum() != test1.minimum());



    return 0;
}
