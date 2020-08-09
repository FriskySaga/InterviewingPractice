// Kevin Tran
// October 31, 2017
// Determine if a given singly linked list contains a cycle.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LL_LENGTH 6     /* length of linked list */

struct linkedList {
    int data;
    struct linkedList *next;
};

// Given the head of a singly linked list, detect whether a cycle exists using
// Floyd's cycle-finding algorithm. Return 1 if a cycle exists, else 0.
int find_cycle(struct linkedList *node) {
    // Base case: list is empty or contains one node pointing to NULL.
    if (node == NULL || node-> next == NULL) return 0;

    // If the list has a cycle, the faster iterator will overlap the slower iterator.
    struct linkedList *tortoise = node;     /* slower moving iterator */
    struct linkedList *hare = node->next;   /* faster moving iterator */

    // Run into the next dimension! O(n) runtime
    while (hare != NULL) {
        // There is a cycle because the faster runner has caught up with the
        // slower runner!
        if (hare == tortoise)
            return 1;

        // There can't be a cycle if NULL exists.
        else if (hare->next == NULL)
            return 0;

        // Move the turtle one step, but move the rabbit two steps!
        else {
            tortoise = tortoise->next;
            hare = hare->next->next;
        }
    }

    // There is no cycle.
    return 0;
}

// Given the head of a linked list and the node number to find, iterate through
// the linked list and return the target node.
struct linkedList *find_node(struct linkedList *node, int nodeNumber) {
    for (int i = 1; i < nodeNumber; i++) node = node->next;
    return node;
}

// Given the head of a linked list and data for the new node to be inserted,
// insert to the FRONT of the linked list. Return the head of the linked list.
struct linkedList *insert_front(struct linkedList *list, int number) {
    // Make the node.
    struct linkedList *node = (struct linkedList *) malloc(sizeof(struct linkedList));
    node->data = number;

    // Point the new node to the list.
    node->next = list;

    return node;
}

// Given the head of a completed linked list, randomly decide whether the last
// node should point to NULL or loop back to a previous node (or itself).
// Return the node that is pointed by the tail node.
// If the tail points to NULL, then return -1.
int insert_loop(struct linkedList **head) {
    int loopNode;

    // Make an iter variable to iterate through the linked list.
    struct linkedList *iter = *head;

    // Go to the end of the linked list.
    while (iter->next != NULL) iter = iter->next;

    // 50% chance that no loop will be added.
    float loopChoice = rand() % 2;

    // Do not add a loop if the choice is 0.
    if (loopChoice == 0) return -1;

    // Add a loop from the tail node to any previous node (or itself).
    else {
        // Randomly select a node for the tail to loop.
        loopNode = 1 + rand() % (LL_LENGTH);
        iter->next = find_node(*head, loopNode);
    }

    return loopNode;
}

// Given an empty linked list, fill the linked list.
// Return the node that is pointed by the tail node.
// If the tail points to NULL, then return -1.
int make_ll(struct linkedList **list) {
    // Seed the rand() function.
    srand(time(0));

    // Number the nodes of the linked list.
    for (int i = LL_LENGTH; i > 0; i--)
        *list = insert_front(*list, i);

    // Let the computer decide whether the last node should have a loop.
    return insert_loop(list);
}

// Given the head of a linked list and the node pointed by the tail node,
// print the linked list to the screen.
void print_list(struct linkedList *node, int loopNode) {
    printf("\nHere is the linked list:\n\n");
    for (int i = 1; i <= LL_LENGTH; i++)
        printf("  %d  ->", i);

    // Show where the tail node is pointing.
    if (loopNode == -1) printf("  NULL\n");
    else printf("  %d\n", loopNode);
}

int main(void) {
    // Tell the user about this program.
    printf("\nThis program will determine if a given linked list contains a"
           " cycle.\n");

    // Generate a random singly linked list.
    struct linkedList *list = NULL;
    int loopNode = make_ll(&list);

    // Print the generated linked list.
    print_list(list, loopNode);

    // Detect if there is a cycle in the linked list.
    int hasCycle = find_cycle(list);

    if (hasCycle == 0) printf("\nThere is no cycle.\n");
    else printf("\nThere is a cycle!\n");

    // Wrap up the program.
    printf("\n\nHit Enter to stop the program...\n");
    getchar();

    return 0;
}
