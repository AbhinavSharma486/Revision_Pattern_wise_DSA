// * Question :- 234. Palindrome Linked List
// & Link :- https://leetcode.com/problems/palindrome-linked-list/description/

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
bool isPalindrome(Node *head)
{
  Node *slow = head;
  Node *fast = head;

  // Phase 1: Find the middle of the linked list
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  // Phase 2: Reverse the second half of the linked list
  Node *temp = NULL;

  while (slow != NULL)
  {
    Node *nextNode = slow->next;
    slow->next = temp;
    temp = slow;
    slow = nextNode;
  }

  // Phase 3: Compare the both halves of the linked list
  Node *firstHalf = head;
  Node *secondHalf = temp;

  while (secondHalf != NULL)
  {
    if (firstHalf->data != secondHalf->data)
    {
      return false;
    }

    firstHalf = firstHalf->next;
    secondHalf = secondHalf->next;
  }

  return true;
}
int main()
{
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(2);
  Node *n4 = new Node(1);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;

  Node *head = n1;

  if (isPalindrome(head))
  {
    cout << "The linked list is a palindrome.";
  }
  else
  {
    cout << "The linked list is not a palindrome.";
  }

  return 0;
}