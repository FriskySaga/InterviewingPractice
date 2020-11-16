/**
 * Firecode Level 2
 * 
 * Determine if a given linked list has an even or odd number of nodes.
 */

#include <cassert>
#include <iostream>

using namespace std;

struct ListNode
{
  struct ListNode* next;
  int value;
};

// Initial solution
bool isListEven1(ListNode* head)
{
  int numNodes = 0;

  while(head != NULL)
  {
    head = head->next;
    ++numNodes;
  }

  return numNodes % 2 == 0 ? true: false;
}

// Slightly more clever solution
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

  first->value = 1;
  first->next = second;
  second->value = 2;
  second->next = NULL;
  assert(isListEven(first));

  ListNode* third = new ListNode();
  second->next = third;
  third->value = 3;
  third->next = NULL;
  assert(!isListEven(first));

  assert(isListEven(NULL));

  delete third;
  delete second;
  delete first;

  return 0;
}
