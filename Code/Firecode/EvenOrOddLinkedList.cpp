#include <cassert>
#include <cstdint>
#include <iostream>

struct ListNode
{
  struct ListNode* next;
};

bool isListEven(ListNode* head)
{
  uint16_t numNodes = 0;

  while(head != NULL)
  {
    head = head->next;
    ++numNodes;
  }

  return numNodes % 2 == 0 ? true: false;
}

int main()
{
  ListNode* first = new ListNode();
  ListNode* second = new ListNode();

  first->next = second;
  second->next = NULL;
  assert(isListEven(first));

  ListNode* third = new ListNode();
  second->next = third;
  third->next = NULL;
  assert(!isListEven(first));

  assert(isListEven(NULL));

  delete third;
  delete second;
  delete first;

  return 0;
}