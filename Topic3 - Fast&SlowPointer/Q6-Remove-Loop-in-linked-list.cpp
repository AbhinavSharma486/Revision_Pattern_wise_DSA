// * Question :- Remove loop in Linked List
// & Link :- https://www.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

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
bool removeLoop(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  // Phase1:- Detect Cycle

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      break;
    }
  }

  if (slow != fast)
  {
    return 0;
  }

  // Phase2:- Find the starting point
  slow = head;

  while (slow != fast)
  {
    slow = slow->next;
    fast = fast->next;
  }

  // Phase3:- Remove the loop
  while (fast->next != slow)
  {
    fast = fast->next;
  }

  fast->next = NULL;

  return 1;
}
int main()
{
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;

  n4->next = n2; // cycle created

  bool result = removeLoop(n1);

  if (result)
  {
    cout << "Loop removed successfully";
  }
  else
  {
    cout << "No loop found";
  }

  return 0;
}