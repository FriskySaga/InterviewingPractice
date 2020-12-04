#include <cassert>
#include <iostream>

struct ListNode
{
  int value;
  struct ListNode* next;
};

void deleteLinkedList(ListNode* toDelete)
{
  while (toDelete)
  {
    ListNode* temp = toDelete->next;
    delete toDelete;
    toDelete = temp;
  }
}

// Level 2 (Oracle)
bool isListEven(ListNode* head)
{
  bool hasEvenNodes = true;

  while (head)
  {
    head = head->next;
    hasEvenNodes = !hasEvenNodes;
  }

  return hasEvenNodes;
}

// Level 2
ListNode* insertAtTail(ListNode* head, int data)
{
  if (head == nullptr)
  {
    return new ListNode{data, nullptr};
  }

  ListNode* temp = head;
  while (temp->next)
  {
    temp = temp->next;
  }

  temp->next = new ListNode{data, nullptr};

  return head;
}

// Level 3
// pos is 1-indexed
ListNode* insertAtPosition(ListNode* head, int data, int pos)
{
  int cur = 1;
  ListNode* prev = NULL;
  ListNode* iter = head;
  while (cur <= pos)
  {
    if (cur == pos)
    {
      if (prev != NULL) prev->next = new ListNode{data, iter};
      else head = new ListNode{data, iter};
      break;
    }
    prev = iter;
    iter = iter->next;
    ++cur;
  }
  return head;
}

// Level 3 - Oracle
// n is 1-indexed
ListNode* deleteAtPos(ListNode* head, int n)
{
  int pos = 1;
  ListNode* prev = nullptr;
  ListNode* iter = head;
  while (iter)
  {
    if (pos != n)
    {
      prev = iter;
      iter = iter->next;
    }
    else
    {
      if (prev) prev->next = iter->next;
      else head = iter->next;
      delete iter;
      break;
    }
    ++pos;
  }
  return head;
}

int main()
{
  // nullptr
  assert(isListEven(nullptr));

  // 1 -> nullptr
  ListNode* first = insertAtTail(nullptr, 1);
  assert(!isListEven(first));

  // 1 -> 3 -> nullptr
  first = insertAtTail(first, 3);
  assert(isListEven(first));

  // 1 -> 2 -> 3 -> nullptr
  first = insertAtPosition(first, 2, 2);
  assert(!isListEven(first));

  deleteLinkedList(first);

  return 0;
}