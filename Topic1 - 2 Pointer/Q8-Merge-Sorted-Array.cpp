// * Question :- 88. Merge Sorted Array
// & Link :- https://leetcode.com/problems/merge-sorted-array/description/

#include <iostream>
#include <vector>
using namespace std;
vector<int> merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
  int i = m - 1, j = n - 1, k = m + n - 1;

  while (i >= 0 && j >= 0)
  {
    if (nums1[i] > nums2[j])
    {
      nums1[k] = nums1[i];
      i--;
      k--;
    }
    else
    {
      nums1[k] = nums2[j];
      j--;
      k--;
    }
  }

  while (j >= 0)
  {
    nums1[k] = nums2[j];
    j--;
    k--;
  }

  return nums1;
}
int main()
{
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {2, 5, 6};

  int m = 3;
  int n = 3;

  vector<int> result = merge(nums1, m, nums2, n);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}