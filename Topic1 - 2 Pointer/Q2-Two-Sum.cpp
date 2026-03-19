// * Question :- Two Sum
// & Link :- https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

#include <iostream>
#include <vector>
using namespace std;
vector<int> twoSum(vector<int> &nums, int target)
{
  int n = nums.size();

  int i = 0;
  int j = n - 1;

  // 2 pointer approach start
  while (i < j)
  {
    // calculating sum
    int sum = nums[i] + nums[j];

    // agar sum == target ho jata hai to return kro i and j
    if (sum == target)
    {
      return {i + 1, j + 1}; // 1 based indexing
    }

    // agar sum < target hai to i++
    else if (sum < target)
    {
      i++;
    }

    // agar sum > target hai to j--
    else
    {
      j--;
    }
  }

  return {};
}
int main()
{
  vector<int> nums = {2, 7, 11, 15};

  int target = 9;

  vector<int> result = twoSum(nums, target);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}