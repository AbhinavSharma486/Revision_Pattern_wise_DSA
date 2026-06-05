// * Question :- 86. Partition List
// & Link :- https://leetcode.com/problems/partition-list/description/

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
Node *partition(Node *head, int x)
{
  Node *curr = head;
  Node *smallHead = NULL;
  Node *smallTail = NULL;
  Node *largeHead = NULL;
  Node *largeTail = NULL;

  while(curr != NULL)
  {
    // Case 1: curr < x
    if(curr->data < x)
    {
      if(smallHead == NULL)
      {
        smallHead = curr;
        smallTail = curr;
      }
      else {
        smallTail->next = curr;
        smallTail = curr;
      }
    }
    // Case 2: curr >= x
    else {
      if(largeHead == NULL)
      {
        largeHead = curr;
        largeTail = curr;
      }
      else {
        largeTail->next = curr;
        largeTail = curr;
      }
    }

    curr = curr->next;
  }

  // Case 1: small list is empty 
  if(smallHead == NULL)
  {
    return largeHead;
  }

  // Case2: small list is not empty 
  smallTail->next = largeHead;

  // Case 3: large list is empty 
  if(largeTail != NULL)
  {
    largeTail->next = NULL;
  }

  return smallHead;
}
int main()
{
  Node *n1 = new Node(1);
  Node *n2 = new Node(4);
  Node *n3 = new Node(3);
  Node *n4 = new Node(2);
  Node *n5 = new Node(5);
  Node *n6 = new Node(2);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;

  Node *head = n1;

  int x = 3;

  Node *ans = partition(head, x);

  while (ans != NULL)
  {
    cout << ans->data << " ";
    ans = ans->next;
  }

  return 0;
}