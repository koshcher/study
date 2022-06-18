
#ifndef TREE_NODE_H
#define TREE_NODE_H

template <class K, class V>
class TreeNode
{
private:
  K key;
  V value;

public:
  TreeNode* parent = nullptr;
  TreeNode* rightChild = nullptr; // more
  TreeNode* leftChild = nullptr; // less

public:
  TreeNode(K key, V value);

  V getValue();
  K getKey();

  bool AddChild(TreeNode<K, V>* node);
};

#endif // !TREE_NODE_H
