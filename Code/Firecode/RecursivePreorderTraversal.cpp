/**
 * Firecode Level 2
 */

// Given a binary tree, write a method to recursively traverse the tree in the
// preorder manner. Mark a node as visited by adding its value to the list - vector
// <int> preordered_list.

#include <cassert>
#include <iostream>

struct TreeNode
{
  int value;
  struct TreeNode* left;
  struct TreeNode* right;
};

// Function provided by Firecode (but implementation done by me)
int getTreeHeight(TreeNode* root)
{
  if (root == nullptr)
  {
    return 0;
  }

  int lHeight = getTreeHeight(root->left);
  int rHeight = getTreeHeight(root->right);

  return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
}

int main()
{


  return 0;
}