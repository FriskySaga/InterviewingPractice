#include <cassert>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
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

// InfoSys
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

// Level 3 - Salesforce
// Example:
//      1
//     / \
//    2   3     ==> 1234567
//   / \ / \
//  4  5 6  7 
std::vector<int> levelOrder(TreeNode* root)
{
  std::vector<int> v;
  std::queue<TreeNode*> q;
  if (root) q.push(root);
  while (!q.empty())
  {
    TreeNode* node = q.front();
    q.pop();
    if (node == nullptr) continue;
    v.push_back(node->value);
    q.push(node->left);
    q.push(node->right);
  }
  return v;
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

// Level 3 - Google (Leetcode Easy)
// The diameter of a Binary Tree is defined as the
// "Number of nodes on the longest path between two leaf nodes".
// Example:
//            20                                  
//         /     \                              
//        15     30 
//       /  \      \                     
//      14  18     35
//         /  \    /
//        17  19  32
//     diameter ==> 7 
// Note we can traverse from 32 to 19
int diameter(TreeNode* root)
{
  if (root == nullptr) return 0;

  int leftHeight = getTreeHeight(root->left);
  int rightHeight = getTreeHeight(root->right);

  int leftDiameter = diameter(root->left);
  int rightDiameter = diameter(root->right);

  // Return max of either:
  // 1) Height of left subtree + height of right subtree + 1
  // 2) Diameter of left subtree
  // 3) Diameter of right subtree
  return std::max(leftHeight + rightHeight + 1, std::max(leftDiameter, rightDiameter));
}

// Count number of elements starting from the root
int getTreeSize(TreeNode* root)
{
  if (root == nullptr) return 0;
  return getTreeSize(root->left) + 1 + getTreeSize(root->right);
}

// Firecode Level 4 - Twitter - Leetcode Medium
// Write a function to find and return the kth smallest node in a
// binary search tree.
// If the node is not found, return NULL.
// Examples:
//        4
//       / \
//      2   8
//         / \
//        5  10
// find 2nd smallest node ==> 4
TreeNode* findKthSmallest(TreeNode* root, int k) 
{
  if (root == nullptr) return nullptr;

  int leftSubtreeSize = 0;
  if (root->left != nullptr) leftSubtreeSize = getTreeSize(root->left);

  if (leftSubtreeSize + 1 == k) return root;
  else if (k <= leftSubtreeSize) return findKthSmallest(root->left, k);
  else return findKthSmallest(root->right, k - leftSubtreeSize - 1);
}

// Firecode Level 4 - Apple
// Write a function to find the kth largest node in a
// binary search tree
// If the node is not found, return NULL .
// Examples:
//        4                                  
//       / \                              
//      2   8     
//         / \                     
//        5  10 
// find 2nd largest node ==> 8                 
TreeNode* findKthLargest(TreeNode* root, int k)
{
  if (root == nullptr) return nullptr;

  int rightSubtreeSize = 0;
  if (root->right != nullptr) rightSubtreeSize = getTreeSize(root->right);

  if (rightSubtreeSize + 1 == k) return root;
  else if (k <= rightSubtreeSize) return findKthLargest(root->right, k);
  else return findKthLargest(root->left, k - rightSubtreeSize - 1);
}

// Level 4 - Google
// Given a binary tree and the data values of two tree nodes, implement a function
// to find and return the LCA (Lowest Common Ancestor) node of the two nodes. a and
// b are the data values of the two input nodes. Assume that nodes with the values a
// and b will surely exist in the tree.
// Examples:
//        1
//       / \
//      2   3
//     / \ / \
//    4  5 6  7
// LCA of 6 and 4 is 1,
// LCA of 4 and 5 is 2.
TreeNode* find_lca(TreeNode* root, int a, int b)
{
  // This basically uses the fact that if a and b are in the same subtree of root
  // (i.e., both in left subtree or both in right), then find_lca(root,a,b) equals
  // find_lca(root->left,a,b) (or ->right, respectively). If a and b are split
  // across different subtrees, then root itself is the LCA. 
  if (root == nullptr) return nullptr;
  if (root->value == a || root->value == b) return root;
  TreeNode* left = find_lca(root->left, a, b);
  TreeNode* right = find_lca(root->right, a, b);
  if (left != nullptr && right != nullptr) return root;
  return left == nullptr ? right : left;
}

// Level 4 - Asana
// Given the root node of a Binary Tree, write a method to iteratively determine if
// it is a Binary Search Tree. Examples:
//           20
//          /   \
//        15    30
//       /  \
//      14  18
//     output ==> true
//           20
//          /   \
//        30    15
//       /  \
//      14  18
//    output ==> false
bool validate_bst_itr(TreeNode* root)
{
  // Stores root node and left subtree of each node
  std::stack<TreeNode*> stack;
    
  // Stores previous visited node
  TreeNode* prev = nullptr;

  // Traverse the binary tree
  while (!stack.empty() || root != nullptr)
  {
    // Traverse left subtree
    while (root != nullptr)
    {
      stack.push(root);
      root = root->left;
    }

    root = stack.top();
    stack.pop();

    // Not a BST if the value of root node is less than or equal to the value of left subtree
    if (prev != nullptr && root->value <= prev->value)
    {
      return false;
    }

    // Update prev and traverse right subtree of the tree
    prev = root;
    root = root->right;
  }

  return true;
}

// Firecode - Level 4 (LinkedIn)
// Given a binary tree, write a method to return the level that has the maximum sum.
// In case the tree is empty, return -1

// Example:
//        1
//       / \
//      2   3
//     / \ / \
//    4  5 6  7
//   /
//  8
// Output ==> 2

// Note: Assume that root is at level 0.
int find_max_sum_level(TreeNode* root)
{
  if (root == nullptr) return -1;
  int curr_sum = 0, max_sum = 0;
  int curr_lvl = 0, max_lvl = 0;
  std::queue<TreeNode*> q;
  TreeNode* ptr;
  q.push(root);          /* Insert the root node in the queue */
  q.push(nullptr);
  while (!q.empty())
  {
    ptr = q.front();      /* get a Tree node from head of the queue */
    q.pop();
    if (ptr == nullptr)
    {
      if (curr_sum > max_sum)
      {
          max_sum = curr_sum;
          max_lvl = curr_lvl;
      }
      curr_sum = 0; //reset
      if (!q.empty())
          q.push(nullptr);; //end of level indicator
      ++curr_lvl; //begin next level
    }
    else
    {
      curr_sum += ptr->value;
      if (ptr->left != nullptr) /* move the left child node of the tree node in the queue */
        q.push(ptr->left);
      if (ptr->right != nullptr) /* move the right child node of the tree node in the queue */
        q.push(ptr->right);
    }
  }
  return max_lvl;
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

  std::vector<int> answer = {1,2,3,4,5,6,7};
  assert(levelOrder(&one) == answer);

  return 0;
}
