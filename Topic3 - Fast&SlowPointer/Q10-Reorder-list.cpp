// * Question :- 143. Reorder List
// & Link :- https://leetcode.com/problems/reorder-list/description/

#include <iostream>
#include <vector>
using namespace std;
struct Node
{
  int data;

  Node *next;

  Node(int x)
  {
    data = x;
    next = NULL;
  }
};
Node *reorderList(Node *head)
{
  // Edge case
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  // Phase 1: Find the middle of the linked list
  Node *slow = head;
  Node *fast = head;
  Node *prev = NULL;

  while (fast != NULL && fast->next != NULL)
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  prev->next = NULL; // split the linked list into two halves

  // Phase 2: Reverse the second half of the linked list
  Node *temp = NULL;

  while (slow != NULL)
  {
    Node *nextNode = slow->next;
    slow->next = temp;
    temp = slow;
    slow = nextNode;
  }
  // Phase 3: Merge the two halves of the linked list
  Node *first = head;
  Node *second = temp;

  while (second != NULL && first != NULL)
  {
    Node *firstNext = first->next;
    Node *secondNext = second->next;

    first->next = second;
    second->next = firstNext;

    first = firstNext;
    second = secondNext;
  }

  return head;
}
int main()
{
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  Node *head = n1;

  Node *result = reorderList(head);

  while (result != NULL)
  {
    cout << result->data << "->";
    result = result->next;
  }

  return 0;
}