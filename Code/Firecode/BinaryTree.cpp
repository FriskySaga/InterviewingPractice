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

bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
{
  if (root == nullptr)
  {
    return true;
  }

  if ((minNode != nullptr && root->value <= minNode->value) ||
      (maxNode != nullptr && root->value >= maxNode->value))
  {
    return false;
  }

  return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}

// Level 2
bool validateBST(TreeNode* root)
{
  return isValidBST(root, nullptr, nullptr);
}

// Level 2
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

void traverseLevel(TreeNode* root, int level)
{
  if (root == NULL)
  {
    return;
  }
  if (level == 0)
  {
    std::cout << root->value << " ";
  }
  else if (level > 0)
  {
    traverseLevel(root->left, level-1);
    traverseLevel(root->right, level-1);
  }
}

// Level 3 - Salesforce
// Example:
//      1
//     / \
//    2   3     ==> 1234567
//   / \ / \
//  4  5 6  7 
void levelOrder(TreeNode* root)
{
  int height = getTreeHeight(root);
  for (int level = 0; level < height; ++level)
  {
    traverseLevel(root, level);
  }
}

int main()
{
  TreeNode seven = {7, nullptr, nullptr};
  TreeNode six = {6, nullptr, nullptr};
  TreeNode five = {5, nullptr, nullptr};
  TreeNode four = {4, nullptr, nullptr};
  TreeNode three = {3, &six, &seven};
  TreeNode two = {2, &four, &five};
  TreeNode one = {1, &two, &three};
  levelOrder(&one); std::cout << std::endl;

  return 0;
}