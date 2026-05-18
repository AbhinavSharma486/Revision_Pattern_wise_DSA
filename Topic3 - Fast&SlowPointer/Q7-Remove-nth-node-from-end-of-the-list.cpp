// * Question :- 19. Remove Nth Node From End of List
// & Link :- https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

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

Node *removeNthFromEnd(Node *head, int n)
{
  // iss question ko 2 phase me divide kiya hai maine
  // pehle fast ko n steps aage badhaya hai
  // then fast ko 1 step aage badhaya hai
  // aur slow ko bhi 1 step aage badhaya hai
  // jab fast null ho jayega tab slow ke next ko delete kar denge

  Node *slow = head;
  Node *fast = head;

  // Step1:- fast ko n steps aage badhaya hai
  for (int i = 0; i < n; i++)
  {
    fast = fast->next;
  }

  // Step2:- agar fast null ho jata hai to iska matlab hai ke hume head ko delete krna hai
  if (fast == NULL)
  {
    return head->next;
  }

  // Step3:- ab fast mid me hai so ab fast ko 1 step aage badhaya hai aur slow head pr hai to slow ko bhi 1 step aage badhaya hai
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next;
  }

  // Step4:- ab fast null ho jayega or slow delete hone wale node ke just pehle node pr hoga to slow ke next ko delete kr denge
  // means slow ke next ko slow ke next ke next se point kar denge
  slow->next = slow->next->next;

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

  int n = 2;

  Node *result = removeNthFromEnd(head, n);

  cout << "Modified List : ";
  while (result != NULL)
  {
    cout << result->data << "->";
    result = result->next;
  }

  return 0;
}