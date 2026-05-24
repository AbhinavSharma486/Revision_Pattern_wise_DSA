// * Question :- 725. Split Linked List in Parts
// & Link :- https://leetcode.com/problems/split-linked-list-in-parts/description/

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
vector<Node *> splitListToParts(Node *head, int k)
{
  // 1. Calculate the length of the linked list
  // 2. Calculate the size of each part and the number of extra nodes
  // 3. Split the linked list into parts
  // 4. First extra parts -> baseSize + 1
  // 5. Remaining parts -> baseSize
  // 6. Step1: current node ko answer me store kro
  // 7. Step2: Decide kro iss part ki size kya hogi
  // -> agar extra > 0 ----- baseSize + 1
  // -> warna ----- baseSize
  // 8. Step3: Move current node to the end of the current part size
  // 9. Step4: Part cut kro and move current node to the next part

  // Step1:- Calculate the length of the linked list
  int length = 0;
  Node *temp = head;

  while (temp != NULL)
  {
    length++;
    temp = temp->next;
  }

  // Step2:- Calculate the size of each part and the number of extra nodes
  int baseSize = length / k;
  int extra = length % k;

  vector<Node *> ans(k, NULL);

  // Step3:- Split the linked list into parts
  Node *current = head;
  for (int i = 0; i < k; i++)
  {
    ans[i] = current;

    int partSize = baseSize + (extra > 0 ? 1 : 0);

    // Move till the end of the current part
    for (int j = 1; j < partSize; j++)
    {
      if (current != NULL)
      {
        current = current->next;
      }
    }

    // Step4:- Part cut kro and move current node to the next part
    if (current != NULL)
    {
      Node *nextPart = current->next;
      current->next = NULL;
      current = nextPart;
    }

    // Extra node used
    if (extra > 0)
    {
      extra--;
    }
  }

  return ans;
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
  Node *n10 = new Node(10);

  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;
  n6->next = n7;
  n7->next = n8;
  n8->next = n9;
  n9->next = n10;

  int k = 3;

  Node *head = n1;

  vector<Node *> ans = splitListToParts(head, k);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << "Part " << i + 1 << ": ";

    Node *temp = ans[i];

    while (temp != NULL)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }

    cout << endl;
  }

  return 0;
}