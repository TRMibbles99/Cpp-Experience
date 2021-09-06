#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

template <class KeyType>
class Node
{
public:
  KeyType *value;
  Node<KeyType> *parent;
  Node<KeyType> *left;
  Node<KeyType> *right;

  Node(){
    value = nullptr;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }

  Node(KeyType* item){
    value = item;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
  }

};

template <class KeyType>
class BST
{
public:
  BST();
  BST(const BST<KeyType>& bst);
  ~BST();

  bool empty() const; // return true if empty; false o/w
  int getlen() const;
  KeyType *get(const KeyType& k) const; // (search) return first item with key equal to k
  void insert(KeyType *k); // insert k into the tree
  void remove(const KeyType& k); // delete first item with key equal to k
  KeyType *maximum() const; // return the maximum item
  KeyType *minimum()const ; // return the minimum item
  KeyType *successor(const KeyType& k); // return the successor of k
  KeyType *predecessor(const KeyType& k) const; // return the predecessor of k

  std::string inOrder() const; // return string of items from an inorder traversal
  std::string preOrder() const; // return string of items from a preorder traversal
  std::string postOrder() const; // return string of items from a postorder traversal
private:
  Node<KeyType>* root;
  int length;

  Node<KeyType>* copy(Node<KeyType>* n);
  void destroy();

  Node<KeyType>* search(Node<KeyType>* node, const KeyType& key) const;
  Node<KeyType>* minimum(Node<KeyType>* node) const;
  Node<KeyType>* maximum(Node<KeyType>* node) const;

  std::string preOrder(Node<KeyType>* node) const;
  std::string inOrder(Node<KeyType>* node) const;
  std::string postOrder(Node<KeyType>* node) const;

};

class KeyError { };
class EmptyError { };

#endif
