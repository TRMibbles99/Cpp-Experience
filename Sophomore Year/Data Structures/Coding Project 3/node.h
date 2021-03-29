// node.h

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <sstream>
using namespace std;

class Node
{
    public:
        char C;    //character
        int freq;    //frequency
        Node* leftPtr; // left pointer
        Node* rightPtr; // right pointer

    //public:
        Node();             // default constructor
        Node(char c, int f);   // construct a node with char and frequency
        Node(char c, int f, Node& left, Node& right); //full node constructor
        Node(const Node& nd); // copy constructors

        std::string toString() const; //toString
        bool operator<(const Node& n); //less than operator
        bool operator>(const Node& n); //greater than operator

};

std::ostream& operator<<(std::ostream& stream, const Node& n);


#include "node.cpp"

#endif
