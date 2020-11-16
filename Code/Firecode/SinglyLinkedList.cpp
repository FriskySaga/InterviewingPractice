/**
 * Firecode Level 2
 * 
 * A bunch of simple data structure operations with Singly Linked List
 */

#include <cassert>
#include <iostream>

using namespace std;

struct ListNode
{
  struct ListNode* next;
  int value;
};

/**
 * Determine if a given linked list has an even or odd number of nodes.
 */
bool isListEven(ListNode* head)
{
  bool hasEvenNodes = true;

  while (head != NULL)
  {
    head = head->next;
    hasEvenNodes = !hasEvenNodes;
  }

  return hasEvenNodes;
}

int main()
{
  ListNode* first = new ListNode();
  ListNode* second = new ListNode();
  ListNode* third = new ListNode();

  // 1 -> 2 -> NULL
  first->value = 1;
  first->next = second;
  second->value = 2;
  second->next = NULL;
  assert(isListEven(first));

  // 1 -> 2 -> 3 -> NULL
  second->next = third;
  third->value = 3;
  third->next = NULL;
  assert(!isListEven(first));

  // NULL
  assert(isListEven(NULL));

  delete third;
  delete second;
  delete first;

  return 0;
}