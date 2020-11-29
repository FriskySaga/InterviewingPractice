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

// Level 2
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

// Level 3 - Oracle
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
  assert(first->value == 1);
  assert(first->next == nullptr);
  assert(!isListEven(first));

  // 1 -> 2 -> nullptr
  first = insertAtTail(first, 2);
  ListNode* second = first->next;
  assert(second->value == 2);
  assert(second->next == nullptr);
  assert(isListEven(first));

  // 1 -> 2 -> 3 -> nullptr
  first = insertAtTail(first, 3);
  ListNode* third = second->next;
  assert(third->value == 3);
  assert(third->next == nullptr);
  assert(!isListEven(first));

  deleteLinkedList(first);

  return 0;
}