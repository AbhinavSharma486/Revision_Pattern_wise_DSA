// * Question :- 1721. Swapping Nodes in a Linked List
// & Link :- https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/

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
Node *swapNodes(Node *head, int k)
{
  // Step 1 : Find the length of the linked list
  // Step 2 : Staring se kth node ko find kro and save kro
  // Step 3 : ab slow ko head pr rakho
  // Step 4 : fast ko kth node pr rakho (jaha abhi slow tha vha fast ko rakho)
  // Step 5 : ab fast ko end tak le jao and slow ko bhi fast ke sath le jao
  // Step 6 : dono ko ek sath 1 step forward krte hue le jao
  // Step 7 : ab fast end pr hoga and slow kth node pr hoga
  // Step 8 : ab save node ke data ko slow ke data se swap kr do
  // Step 9 : return head

  Node *slow = head;
  Node *fast = head;

  // Step 2
  for (int i = 1; i < k; i++)
  {
    slow = slow->next;
  }

  Node *save = slow;

  fast = slow;

  slow = head;

  while (fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next;
  }

  int temp = save->data;
  save->data = slow->data;

  slow->data = temp;

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
  n5->next = NULL;

  Node *head = n1;

  int k = 2;

  Node *ans = swapNodes(head, k);

  while (ans != NULL)
  {
    cout << ans->data << " ";
    ans = ans->next;
  }

  return 0;
}