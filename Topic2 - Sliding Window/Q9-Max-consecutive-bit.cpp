// * Question :- Max Consecutive Bit
// & Link :- https://www.geeksforgeeks.org/problems/max-consecutive-one/1

#include <iostream>
#include <vector>
using namespace std;
int maxConsecBits(vector<int> &arr)
{
  int n = arr.size();

  int low = 0;
  int high = 0;
  int count = 0;
  int res = 0;

  // sliding window approach start
  for (high = 1; high < n; high++)
  {
    // agar current element and previous element same hai
    // to count ko 1 se increase kr do
    if (arr[high] == arr[high - 1])
    {
      count = count + 1;
    }

    // agar current element and previous element same nhi hai to
    // to count ko 1 kr do
    else
    {
      count = 1;
    }

    res = max(res, count);
  }

  return res;
}
int main()
{
  vector<int> arr = {0, 0, 0, 1, 0, 0, 1};

  int result = maxConsecBits(arr);

  cout << "Maximum consecutive bits : " << result;

  return 0;
}