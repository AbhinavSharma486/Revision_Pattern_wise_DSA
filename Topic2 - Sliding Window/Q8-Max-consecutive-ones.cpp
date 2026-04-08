// * Question :- 485. Max Consecutive Ones
// & Link :- https://leetcode.com/problems/max-consecutive-ones/description/

#include <iostream>
#include <vector>
using namespace std;
int findMaxConsecutiveOnes(vector<int> &nums)
{
  int n = nums.size();

  int low = 0;
  int high = 0;
  int maxCount = 0;
  int res = 0;

  for (high = 0; high < n; high++)
  {
    // high index pr 2 case banenge
    // Case1: high idx pr 1 hoga
    // Case2: high idx pr 0 hoga

    // Case1: high idx pr 1 hoga
    if (nums[high] == 1)
    {
      // then maxCount ko 1 se increase krenge
      maxCount++;
    }

    // Case2: high idx pr 0 hoga
    else
    {
      // 0 aane pr maxCount ko 0 kr denge
      maxCount = 0;
    }

    // res me maxCount ko update krenge
    res = max(res, maxCount);
  }

  return res;
}
int main()
{
  vector<int> nums = {1, 1, 0, 1, 1, 1, 1};

  int result = findMaxConsecutiveOnes(nums);

  cout << "Maximum number of consecutive 1's: " << result;

  return 0;
}