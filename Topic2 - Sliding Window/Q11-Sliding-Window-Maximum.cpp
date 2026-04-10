// * Question :- 239. Sliding Window Maximum
// & Link :- https://leetcode.com/problems/sliding-window-maximum/description/

// ^ Solution :- Brute Force Approach (Leetcode TLE)
#include <iostream>
#include <vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
  int n = nums.size();

  vector<int> result(n - k + 1);

  int low = 0;
  int high = k - 1;

  for (high = k - 1; high < n; low++, high++)
  {
    int maxElement = nums[low];

    for (int i = low + 1; i <= high; i++)
    {
      if (nums[i] > maxElement)
      {
        maxElement = nums[i];
      }
    }
    result[low] = maxElement;
  }

  return result;
}
int main()
{
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;

  vector<int> result = maxSlidingWindow(nums, k);

  for (int num : result)
  {
    cout << num << " ";
  }

  return 0;
}

// ^ Solution2:- Optimized Approach (Using Deque)
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
}
int main()
{
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;

  vector<int> result = maxSlidingWindow(nums, k);

  for (int num : result)
  {
    cout << num << " ";
  }

  return 0;
}