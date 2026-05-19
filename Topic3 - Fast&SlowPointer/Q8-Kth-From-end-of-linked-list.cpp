// * Question :- Kth From End of Linked List
// & Link :- https://www.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

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

int getKthFromLast(Node *head, int k)
{
  Node *slow = head;
  Node *fast = head;

  for (int i = 0; i < k; i++)
  {
    if (fast == NULL)
    {
      return -1;
    }
    fast = fast->next;
  }

  while (fast != NULL)
  {
    slow = slow->next;
    fast = fast->next;
  }

  return slow->data;
}
int main()
{
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  Node *n6 = new Node(6);
  Node *n7 = new Node(7);
  Node *n8 = new Node(8);
  Node *n9 = new Node(9);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;
  n6->next = n7;
  n7->next = n8;
  n8->next = n9;
  Node *head = n1;

  int k = 2;

  int result = getKthFromLast(head, k);

  cout << "Kth Node from end is : " << result;

  return 0;
}