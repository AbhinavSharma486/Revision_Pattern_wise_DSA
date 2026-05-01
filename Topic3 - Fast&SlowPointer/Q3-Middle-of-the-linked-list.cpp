// * Question :- 876. Middle of the Linked List
// & Link :- https://leetcode.com/problems/middle-of-the-linked-list/description/?source=submission-ac

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
Node *middleNode(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
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

  Node *ans = middleNode(head);

  cout << "The middle node is : " << ans->data;

  return 0;
}