// * Question :- 141. Linked List Cycle
// & Link :- https://leetcode.com/problems/linked-list-cycle-ii/description/?source=submission-ac

#include <iostream>
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

Node *detectCycle(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return NULL;
  }

  Node *slow = head;
  Node *fast = head;

  // Step 1: Detect cycle
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      break;
    }
  }

  // Step 2: No cycle
  if (fast == NULL || fast->next == NULL)
  {
    return NULL;
  }

  // Step 3: Find starting node of cycle
  slow = head;

  while (slow != fast)
  {
    slow = slow->next;
    fast = fast->next;
  }

  return slow;
}

int main()
{
  Node *n1 = new Node(3);
  Node *n2 = new Node(2);
  Node *n3 = new Node(0);
  Node *n4 = new Node(-4);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n2; // cycle

  Node *head = n1;

  Node *ans = detectCycle(head);

  if (ans != NULL)
    cout << "The cycle starting node is : " << ans->data;
  else
    cout << "No cycle found";

  return 0;
}