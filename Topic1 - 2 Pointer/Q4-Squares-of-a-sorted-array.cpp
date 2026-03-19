// * Question :- 977. Squares of a sorted array
// & Link :- https://leetcode.com/problems/squares-of-a-sorted-array/description/

#include <iostream>
#include <vector>
using namespace std;

vector<int> squareOfSortedArray(vector<int> &nums)
{
  int n = nums.size();

  vector<int> res(n);

  int left = 0;
  int right = n - 1;
  int pos = n - 1;

  while (left <= right)
  {
    if (abs(nums[left]) > abs(nums[right]))
    {
      res[pos] = nums[left] * nums[left];
      left++;
    }
    else
    {
      res[pos] = nums[right] * nums[right];
      right--;
    }

    pos--;
  }

  return res;
}

int main()
{
  vector<int> nums = {-4, -1, 0, 3, 10};

  vector<int> result = squareOfSortedArray(nums);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}