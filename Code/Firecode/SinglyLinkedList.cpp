/**
 * Firecode Level 2
 * 
 * A bunch of simple data structure operations with the Singly Linked List data structure.
 */

#include <cassert>
#include <iostream>

using namespace std;

struct ListNode
{
  int value;
  struct ListNode* next;
};

/**
 * My own function to delete the memory of the Linked List
 */
void deleteLinkedList(ListNode* toDelete)
{
  while (toDelete != nullptr)
  {
    ListNode* temp = toDelete->next;
    delete toDelete;
    toDelete = temp;
  }
}

/**
 * Determine if a given linked list has an even or odd number of nodes.
 */
bool isListEven(ListNode* head)
{
  bool hasEvenNodes = true;

  while (head != nullptr)
  {
    head = head->next;
    hasEvenNodes = !hasEvenNodes;
  }

  return hasEvenNodes;
}

/**
 * Insert a node at the end of a singly-linked list.
 * Return the head of the modified list. 
 * 
 * Developer's Note: This is absolutely horrible design, but this is what Firecode gave me to work with.
 */
ListNode* insertAtTail(ListNode* head, int data)
{
  if (head == nullptr)
  {
    return new ListNode{data, nullptr};
  }

  ListNode* temp = head;
  while (temp->next != nullptr)
  {
    temp = temp->next;
  }

  temp->next = new ListNode{data, nullptr};

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