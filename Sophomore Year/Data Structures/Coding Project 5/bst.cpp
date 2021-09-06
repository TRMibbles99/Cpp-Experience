#include <iostream>
#include <sstream>
#include "bst.h"

using namespace std;

template <class KeyType>
BST<KeyType>::BST(){
  root = nullptr;
  length = 0;
}

template <class KeyType>
BST<KeyType>::~BST(){
  destroy();
}

template <class KeyType>
Node<KeyType>* BST<KeyType>::copy(Node<KeyType>* n){
  if (n != nullptr){
    Node<KeyType>* newNode = new Node<KeyType>(n->value);
    newNode->left = copy(n->left);
    newNode->right = copy(n->right);
    newNode->parent = n->parent;
    return newNode;
  }else{
    return nullptr;
  }
}

template <class KeyType>
void BST<KeyType>::destroy(){
  //This is probably wrong (actually i dont think it is)
  while(root != nullptr){
    remove(*(root->value));
  }
}

template <class KeyType>
Node<KeyType>* BST<KeyType>::search(Node<KeyType>* node, const KeyType& key) const{
  if(node->value == nullptr){
    return nullptr;
  }
  if(key < *(node->value)){
    return search(node->left, key);
  }else if(key > *(node->value)){
    return search(node->right, key);
  }
  return node;
}

template <class KeyType>
Node<KeyType>* BST<KeyType>::minimum(Node<KeyType>* node) const{
  if(node->value == nullptr){
    return nullptr;
  }else if(node->left == nullptr){
    return node;
  }
  return minimum(node->left);
}

template <class KeyType>
Node<KeyType>* BST<KeyType>::maximum(Node<KeyType>* node) const{
  if(node == nullptr){
    return nullptr;
  }else if(node->right == nullptr){
    return node;
  }
  return maximum(node->right);
}

template <class KeyType>
BST<KeyType>::BST(const BST<KeyType>& bst){
  if(bst.length != 0){
    root = copy(bst.root);
    length = bst.length;
  }else{
    throw EmptyError();
  }
}

template <class KeyType>
bool BST<KeyType>::empty() const{
  return length == 0;
}

template <class KeyType>
int BST<KeyType>::getlen() const{
  return length;
}

template <class KeyType>
KeyType* BST<KeyType>::get(const KeyType& k) const{
  //seg faults when the node doesnt exist
  if(length != 0){
    Node<KeyType>* node = search(root, k);
    if(node == nullptr){
      throw KeyType();
    }else{
      return node->value;
    }
  }
  throw KeyType();
}

template <class KeyType>
void BST<KeyType>::insert(KeyType *k){
  Node<KeyType>* current = root;
  Node<KeyType>* parent = nullptr;
  while(current != nullptr){
    parent = current;
    if(*k < *(current->value)){
      current = current->left;
    }else{
      current = current->right;
    }
  }
  Node<KeyType>* newNode = new Node<KeyType>;
  newNode->value = k;
  newNode->parent = parent;

  if(parent == nullptr){
    root = newNode;
  }else if(*k <= *(parent->value)){
    parent->left = newNode;
  }else{
    parent->right = newNode;
  }
  length = length + 1;
}

template <class KeyType>
void BST<KeyType>::remove(const KeyType& k){
  Node<KeyType>* node = search(root, k);
  Node<KeyType>* splice;
  Node<KeyType>* child;
  if(node->left != nullptr && node->right != nullptr){
    splice = search(root, *successor(k));
  }else{
    splice=node;
  }

  if(splice->left != nullptr){
    child = splice->left;
  }else{
    child = splice->right;
  }

  if(child != nullptr){
    child->parent = splice->parent;
  }

  if(splice->parent == nullptr){
    root = child;
  }else if(splice==splice->parent->left){
    splice->parent->left = child;
  }else{ 
    splice->parent->right = child;
  }

  if(splice != node){
    node->value = splice->value;
  }
  if(splice == nullptr){
    throw KeyError();
  }
  delete splice;
  length = length - 1;
}

template <class KeyType>
KeyType* BST<KeyType>::maximum() const{
  Node<KeyType>* node = maximum(root);
  if (node == nullptr){
    return nullptr;
  }
  return node->value;
}

template <class KeyType>
KeyType* BST<KeyType>::minimum() const{
  Node<KeyType>* node = minimum(root);
  if (node == nullptr){
    return nullptr;
  }
  return node->value;
}

template <class KeyType>
KeyType* BST<KeyType>::successor(const KeyType& k){
  Node<KeyType>* node = search(root, k);
  Node<KeyType>* parent;
  if(node == nullptr){
    return nullptr;
  }else if(node->right != nullptr){
    return minimum(node->right)->value;
  }else{
    parent=node->parent;
    while(parent != nullptr && parent->right == node){
      node = parent;
      parent = parent->parent;
    }
  }
  if(parent == nullptr){
    throw KeyError();
  }
  return parent->value;
}

template <class KeyType>
KeyType* BST<KeyType>::predecessor(const KeyType& k) const{
  Node<KeyType>* parent;
  Node<KeyType>* node = search(root, k);
  if(node == nullptr){
    return nullptr;
  }else if(node->left != nullptr){
    return maximum(node->left)->value;
  }else{
    parent=node->parent;
    while(parent!= nullptr && parent->left == node){
      node = parent;
      parent = parent->parent;
    }
  }
  if(parent == nullptr){
    throw KeyError();
  }
  return parent->value;
}

template <class KeyType>
std::string BST<KeyType>::inOrder(Node<KeyType>* node) const{
  std::stringstream ss;
  if(node != nullptr){
    ss << inOrder(node->left);
    ss << *(node->value) << " ";
    ss << inOrder(node->right);
  }
  return ss.str();
}

template <class KeyType>
std::string BST<KeyType>::preOrder(Node<KeyType>* node) const{
  std::stringstream ss;
  if(node != nullptr){
    ss << *(node->value) << " ";
    ss << preOrder(node->left);
    ss << preOrder(node->right);
  }
  return ss.str();
}

template <class KeyType>
std::string BST<KeyType>::postOrder(Node<KeyType>* node) const{
  std::stringstream ss;
  if(node != nullptr){
    ss << *(node->value) << " ";
    ss << postOrder(node->right);
    ss << postOrder(node->left);
  }
  return ss.str();
}

template <class KeyType>
std::string BST<KeyType>::inOrder() const{
  std::stringstream ss;
  ss << "[ " << inOrder(root) << "]";
  return ss.str();
}

template <class KeyType>
std::string BST<KeyType>::preOrder() const{
  std::stringstream ss;
  ss << "[ " << preOrder(root) << "]";
  return ss.str();
}

template <class KeyType>
std::string BST<KeyType>::postOrder() const{
  std::stringstream ss;
  ss << "[ " << postOrder(root) << "]";
  return ss.str();
}
