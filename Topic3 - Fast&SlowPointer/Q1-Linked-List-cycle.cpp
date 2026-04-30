// * Question :- 141. Linked List Cycle
// & Link :- https://leetcode.com/problems/linked-list-cycle/description/?source=submission-ac

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

bool hasCycle(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;

    if (slow == fast)
    {
      return true;
    }
  }
  return false;
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

  // cycle created
  n5->next = n3;

  if (hasCycle(n1))
  {
    cout << "Cycle is present" << endl;
  }

  else
  {
    cout << "Cycle is not present" << endl;
  }
}