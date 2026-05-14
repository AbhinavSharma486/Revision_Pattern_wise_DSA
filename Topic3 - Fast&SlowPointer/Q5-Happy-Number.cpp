// * Question :- 202. Happy Number
// & Link :- https://leetcode.com/problems/happy-number/description/?source=submission-ac

#include <iostream>
#include <vector>
using namespace std;
int getNext(int n)
{
  int sum = 0;

  while (n > 0)
  {
    int digit = n % 10;
    n = n / 10;
    sum = sum + digit * digit;
  }

  return sum;
}
bool isHappy(int n)
{
  int slow = n, fast = n;

  while (fast != 1)
  {
    slow = getNext(slow);
    fast = getNext(getNext(fast));

    if(slow == fast && slow != 1)
    {
      return false;
    }
  }

  return true;
}
int main()
{
  int n = 19;

  if (isHappy(n))
  {
    cout << n << " is a Happy Number.";
  }
  else
  {
    cout << n << " is not a Happy Number.";
  }

  return 0;
}