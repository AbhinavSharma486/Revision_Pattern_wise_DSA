// * Question  :- Maximum Twin Sum of a Linked List
// & Link :- https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/

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
int pairSum(Node *head)
{
  // Step 1: Find the middle of the linked list
  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  // Step 2:- Reverse the second half of the linked list
  Node *prev = NULL;

  while (slow != NULL)
  {
    Node *nextNode = slow->next;
    slow->next = prev;
    prev = slow;
    slow = nextNode;
  }

  // Step 3:- Calculate the twin sum and find the maximum
  int maxTwinSum = 0;

  while (prev != NULL)
  {
    int twinSum = head->data + prev->data;
    maxTwinSum = max(maxTwinSum, twinSum);
    head = head->next;
    prev = prev->next;
  }

  return maxTwinSum;
}
int main()
{
  Node *n1 = new Node(5);
  Node *n2 = new Node(4);
  Node *n3 = new Node(2);
  Node *n4 = new Node(1);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;

  Node *head = n1;

  int result = pairSum(head);

  cout << "Maximum Twin Sum: " << result;

  return 0;
}
