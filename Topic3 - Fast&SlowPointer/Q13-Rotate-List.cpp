// * Question :- 61. Rotate List
// & Link :- https://leetcode.com/problems/rotate-list/description/

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
Node *rotateRight(Node *head, int k)
{
  // Base case:- if the list is empty or has only one node, or if k is 0, return the list
  if (head == NULL || head->next == NULL || k == 0)
  {
    return head;
  }

  // Step 1: Find the length of the list and the last node
  Node *lastNode = head;

  int length = 1;

  while (lastNode->next != NULL)
  {
    lastNode = lastNode->next;
    length++;
  }

  // Step 2:- Connect the last node of the list to the head to make it circular
  lastNode->next = head;

  // Step 3:- Find the new tail and the new head of the rotated list
  k = k % length;

  int stepsToNewHead = length - k;

  Node *newTail = head;

  for (int i = 1; i < stepsToNewHead; i++)
  {
    newTail = newTail->next;
  }

  Node *newHead = newTail->next;

  // Step 4:- Break the circular link to finalize the rotated list
  newTail->next = NULL;

  return newHead;
};
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
  n5->next = NULL;

  Node *head = n1;

  int k = 2;

  Node *ans = rotateRight(head, k);

  while (ans != NULL)
  {
    cout << ans->data << " ";
    ans = ans->next;
  }

  return 0;
}