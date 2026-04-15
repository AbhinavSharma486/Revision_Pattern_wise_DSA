// * Question :- Smallest subarray with sum greater than x
// & Link :- https://www.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int smallestSubWithSum(int x, vector<int> &arr)
{
  int n = arr.size();

  int low = 0;
  int high = 0;
  int sum = 0;
  int count = INT_MAX;

  for (high = 0; high < n; high++)
  {
    sum = sum + arr[high];

    while (sum > x)
    {
      count = min(count, high - low + 1);
      sum = sum - arr[low];
      low++;
    }
  }
  if (count == INT_MAX)
  {
    return 0;
  }
  return count;
}
int main()
{
  vector<int> arr = {1, 4, 45, 6, 0, 19};
  int k = 51;

  int result = smallestSubWithSum(k, arr);

  cout << "Smallest subarray length with sum greater than " << k << " is: " << result;

  return 0;
}