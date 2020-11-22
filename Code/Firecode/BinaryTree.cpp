/**
 * Firecode Level 2 / Leetcode Medium
 * 
 * Given the root node of a Binary Tree, determine if it is a Binary Search Tree.
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

struct TreeNode
{
  int value;
  struct TreeNode* left;
  struct TreeNode* right;
};

void traceBSTValidation(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
{
  std::string rootStr = root != nullptr ? std::to_string(root->value) : "nullptr";
  std::string minNodeStr = minNode != nullptr ? std::to_string(minNode->value) : "nullptr";
  std::string maxNodeStr = maxNode != nullptr ? std::to_string(maxNode->value) : "nullptr";

  std::cout << "Root: " << rootStr << ", Min: " << minNodeStr << ", Max: " << maxNodeStr << std::endl;
}

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

bool validateBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
{
  traceBSTValidation(root, minNode, maxNode);

  if (root == nullptr)
  {
    return true;
  }

  if ((minNode != nullptr && root->value <= minNode->value) ||
      (maxNode != nullptr && root->value >= maxNode->value))
  {
    return false;
  }

  return validateBST(root->left, minNode, root) && validateBST(root->right, root, maxNode);
}

bool isValidBST(TreeNode* root)
{
  return validateBST(root, nullptr, nullptr);
}

// Example:  
//      1
//     / \
//    2   3     ==> 1245367
//   / \ / \
//  4  5 6  7 
void preorder(TreeNode* root)
{
  if (root != NULL)
  {
    std::cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
  }
}

int main()
{
  return 0;
}