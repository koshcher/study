// simple_tree.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Tree.h"
#include "TreeNode.h"

int main()
{
  Tree<int, char>* tree = new Tree<int, char>();

  tree->Add(new TreeNode<int, char>(3, 'f'));
  tree->Add(new TreeNode<int, char>(1, 'n'));
  tree->Add(new TreeNode<int, char>(5, 'm'));
  tree->Add(new TreeNode<int, char>(4, 'g'));

  TreeNode<int, char>* tmp = tree->GetNode(5);
  std::cout << tmp->getValue();

  delete tree;
}