// * Question :- Three sum closest
// & Link :- https://leetcode.com/problems/3sum-closest/description/?source=submission-ac

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
  // sbse pehle to given array ko sort kro
  sort(nums.begin(), nums.end());

  int n = nums.size();

  // bestDiff -> me ab tak ka best difference store hoga jo target or current sum ke closest difference ho
  int bestDiff = INT_MAX;

  // bestSum -> me ab tak ka best sum store hoga jo target ke closest ho
  int bestSum = 0;

  // travere the given array
  for (int i = 0; i < n - 2; i++)
  {
    int left = i + 1;
    int right = n - 1;

    // 2 pointer approach
    while (left < right)
    {
      // current sum of left, right and nums[i]
      int currSum = nums[i] + nums[left] + nums[right];

      // current difference of current sum and target
      int currDiff = abs(target - currSum);

      // agar currdiff < bestdiff se to bestdiff or bestsum ko update kro
      if (currDiff < bestDiff)
      {
        bestDiff = currDiff;
        bestSum = currSum;
      }

      // agar currsum < target se to left++ kro
      if (currSum < target)
      {
        left++;
      }

      // agar currsum > target se to right-- kro
      else
      {
        right--;
      }
    }
  }

  return bestSum;
}
int main()
{
  vector<int> arr = {-1, 2, 1, -4};
  int target = 1;

  int result = threeSumClosest(arr, target);

  cout << "The closest sum is : " << result;

  return 0;
}