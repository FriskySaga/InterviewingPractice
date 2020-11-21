/**
 * Firecode Level 2 / Leetcode Medium
 * 
 * Given the root node of a Binary Tree, determine if it is a Binary Search Tree.
 */

#include <cassert>
#include <iostream>
#include <string>

struct TreeNode
{
  int value;
  struct TreeNode* left;
  struct TreeNode* right;
};

/**
 * This function is provided by Firecode, but the implementation is not provided.
 * Therefore, I had to write this function from scratch, even if I don't end up using it.
 * 
 * Firecode Description:
 * This function takes in a node of a tree and
 * returns the number of nodes on the longest downward path between that node and any leaf.
 * If the node is nullptr, returns 0. 
 */
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

void traceBSTValidation(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
{
  std::string rootStr = root != nullptr ? std::to_string(root->value) : "nullptr";
  std::string minNodeStr = minNode != nullptr ? std::to_string(minNode->value) : "nullptr";
  std::string maxNodeStr = maxNode != nullptr ? std::to_string(maxNode->value) : "nullptr";

  std::cout << "Root: " << rootStr << ", Min: " << minNodeStr << ", Max: " << maxNodeStr << std::endl;
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
  std::cout << "===================================" << std::endl;
  TreeNode* prev = nullptr;
  return validateBST(root, nullptr, nullptr);
}

int main()
{
  TreeNode* first = new TreeNode();
  TreeNode* second = new TreeNode();
  TreeNode* third = new TreeNode();
  TreeNode* fourth = new TreeNode();

  first->value = 1;
  second->value = 2;
  third->value = 3;
  fourth->value = 4;

  // Valid BST
  //    2
  //   / \
  //  1   3
  //       \
  //        4
  first->left = nullptr;
  second->right = nullptr;
  second->left = first;
  second->right = third;
  third->left = nullptr;
  third->right = fourth;
  fourth->left = nullptr;
  fourth->right = nullptr;

  assert(getTreeHeight(second) == 3);
  assert(isValidBST(second));

  // Valid BST
  //     20
  //    /  \
  //  15    40
  //    \
  //     30
  second->value = 20;
  second->left = first;
  
  first->value = 15;
  first->left = nullptr;
  first->right = third;

  third->value = 30;
  third->left = nullptr;
  third->right = nullptr;

  second->right = fourth;

  fourth->value = 40;
  fourth->left = nullptr;
  fourth->right = nullptr;

  assert(getTreeHeight(second) == 3);
  assert(!isValidBST(second));

  // Invalid BST
  //        1
  //       /
  //      2
  //     /
  //    3
  //   /
  //  4
  first->left = second;
  first->right = nullptr;
  second->left = third;
  second->right = nullptr;
  third->left = fourth;
  third->right = nullptr;
  fourth->left = nullptr;
  fourth->right = nullptr;

  assert(getTreeHeight(first) == 4);
  assert(!isValidBST(second));

  delete fourth;
  delete third;
  delete second;
  delete first;

  TreeNode* twentyfive = new TreeNode();
  TreeNode* twenty = new TreeNode();
  TreeNode* ten = new TreeNode();
  TreeNode* five = new TreeNode();
  TreeNode* twelve = new TreeNode();
  TreeNode* twentytwo = new TreeNode();
  TreeNode* thirtysix = new TreeNode();
  TreeNode* thirty = new TreeNode();
  TreeNode* twentyeight = new TreeNode();
  TreeNode* forty = new TreeNode();
  TreeNode* thirtyeight = new TreeNode();
  TreeNode* fortyeight = new TreeNode();

  twentyfive->value = 25;
  twenty->value = 20;
  ten->value = 10;
  five->value = 5;
  twelve->value = 12;
  twentytwo->value = 22;
  thirtysix->value = 36;
  thirty->value = 30;
  twentyeight->value = 28;
  forty->value = 40;
  thirtyeight->value = 38;
  fortyeight->value = 48;

  //          25
  //        /    \
  //       20    36
  //      / \    / \
  //    10  22  30  40
  //   /  \    /    / \
  //  5   12  28   38  48
  twentyfive->left = twenty;
  twentyfive->right = thirtysix;
  twenty->left = ten;
  twenty->right = twentytwo;
  ten->left = five;
  ten->right = twelve;
  five->left = nullptr;
  five->right = nullptr;
  twelve->left = nullptr;
  twelve->right = nullptr;
  twentytwo->left = nullptr;
  twentytwo->right = nullptr;
  thirtysix->left = thirty;
  thirtysix->right = forty;
  thirty->left = twentyeight;
  thirty->right = nullptr;
  twentyeight->left = nullptr;
  twentyeight->right = nullptr;
  forty->left = thirtyeight;
  forty->right = fortyeight;
  thirtyeight->left = nullptr;
  thirtyeight->right = nullptr;
  fortyeight->left = nullptr;
  fortyeight->right = nullptr;
  assert(getTreeHeight(twentyfive) == 4);
  assert(isValidBST(twentyfive));

  delete twenty;
  delete ten;
  delete five;
  delete twelve;
  delete twentytwo;
  delete thirtysix;
  delete thirty;
  delete twentyeight;
  delete forty;
  delete thirtyeight;
  delete fortyeight;
  delete twentyfive;

  return 0;
}