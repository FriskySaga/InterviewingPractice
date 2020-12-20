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

// Level 3 - Oracle
ListNode* reverseList(ListNode* head)
{
  ListNode* prev = nullptr;
  while (head != nullptr)
  {
    // Save off the current's next pointer
    ListNode* nextPtr = head->next;

    // Reverse current's next pointer
    head->next = prev;

    // Advance each pointer
    prev = head;
    head = nextPtr;
  }
  return prev;
}

// Level 3 - Amazon
// Example:
// 1->2->3->4->5->6, head = 1
// findNthNodeFromEnd(head, 2) ==> 5
ListNode* findNthNodeFromEnd(ListNode* head, int n)
{
  ListNode* p = head, *q = head;

  // Move p to (n+1)th node from the beginning
  for (int i = 1; i <= n; ++i)
  {
    if (p == nullptr) return nullptr;
    p = p->next;
  }

  // Then move p and q until p reaches the end
  while (p != nullptr)
  {
    p = p->next;
    q = q->next;
  }

  // Therefore, q should be nth node from the end
  return q;
}

// Level 3 - Find middle node of linked list.
// If there is a tie, use the left node
ListNode* findMiddleNode(ListNode* head)
{
  ListNode* fast = head;
  ListNode* slow = head;

  // Traverse the list by moving one pointer with double the speed
  // as the slow pointer. Stop when the faster pointer reaches
  // the end of the linked list.
  while (fast && fast->next && fast->next->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
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