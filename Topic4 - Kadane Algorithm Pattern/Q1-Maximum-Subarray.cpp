// * Question :- 53. Maximum Subarray
// & Link :- https://leetcode.com/problems/maximum-subarray/description/

#include <iostream>
#include <vector>
using namespace std;
int maxSubArray(vector<int> &nums)
{
  int n = nums.size();

  int bestEnding = nums[0];

  int ans = nums[0];

  for (int i = 1; i < n; i++)
  {
    bestEnding = max(bestEnding + nums[i], nums[i]);
    ans = max(ans, bestEnding);
  }
  return ans;
}
int main()
{
  vector<int> nums = {5, 4, -1, 7, 8};

  int result = maxSubArray(nums);

  cout << "Maximum Subarray Sum : " << result;

  return 0;
}