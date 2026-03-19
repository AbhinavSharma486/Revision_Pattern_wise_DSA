// * Question :- 26. Remove Duplicates from Sorted Array
// & Link :- https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
  int n = nums.size();

  int officer = 0;
  int cm = 1;
  int result = 0;

  while (cm < n)
  {
    if (nums[cm] == nums[cm - 1])
    {
      cm++;
      continue;
    }

    nums[officer + 1] = nums[cm];
    cm++;
    officer++;
    result++;
  }

  return result + 1; // 1 based indexing
};
int main()
{
  vector<int> nums = {1, 1, 1, 2, 2, 3, 3};

  int result = removeDuplicates(nums);

  cout << "The unique number of elements are : " << result;

  return 0;
}