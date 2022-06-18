
#ifndef TREE_H
#define TREE_H

#include "TreeNode.h"

template <class K, class V>
class Tree
{
private:
  TreeNode<K, V>* root;
public:
  Tree();
  Tree(TreeNode<K, V>* root);

  bool Add(TreeNode<K, V>* node);
  TreeNode<K, V>* GetNode(K key);
  void Remove(TreeNode<K, V>* node);
  void Clear();
  void Print();


};

/*
#include "Tree.h"
#include "TreeNode.h"

template <class K, class V>
Tree<K, V>::Tree() : root{ nullptr } {}

template <class K, class V>
Tree<K, V>::Tree(TreeNode<K, V>* root) : root{ root } {}

template <class K, class V>
bool Tree<K, V>::Add(TreeNode<K, V>* node) {
  if (root == nullptr) {
    root = node;
    return true;
  }
  return root->AddChild(node);
}

template <class K, class V>
TreeNode<K, V>* Tree<K, V>::GetNode(K key) {
  TreeNode<K, V>* node = root;
  while (node->key != key) {
    if (key < node->key) {
      if (node->leftChild != nullptr) {
        node = node->leftChild;
      }
      else {
        return nullptr;
      }
    }
    else {
      if (node->rightChild != nullptr) {
        node = node->rightChild;
      }
      else {
        return nullptr;
      }
    }
  }
  return node;
}
*/

#endif // !TREE_H

