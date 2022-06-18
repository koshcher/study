#include "TreeNode.h"

template<class K, class V>
TreeNode<K, V>::TreeNode(K key, V value) 
  : key{ key }, value{ value } {}

template<class K, class V>
V TreeNode<K, V>::getValue() {
  return value;
}

template<class K, class V>
K TreeNode<K, V>::getKey() {
  return key;
}

template<class K, class V>
bool TreeNode<K, V>::AddChild(TreeNode<K, V>* node) {
  if (node->key == key) {
    return false;
  }

  if (node->key > key) {
    // right side
    if (rightChild != nullptr) {
      return rightChild->AddChild(node);
    }
    rightChild = node;
    rightChild->parent = this;
    return true;
  }
  //left side
  if (leftChild != nullptr) {
    return leftChild->AddChild(node);
  }
  leftChild = node;
  rightChild->parent = this;
  return true;
}