// * Question :- 713. Subarray Product Less Than K
// & Link :- https://leetcode.com/problems/subarray-product-less-than-k/description/

#include <iostream>
#include <vector>
using namespace std;
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
  int n = nums.size();

  int low = 0;
  int high = 0;
  int product = 1;
  int count = 0;

  if (k <= 1)
  {
    return 0;
  }

  for (high = 0; high < n; high++)
  {

    product = product * nums[high];

    // Case1: Product >= k
    // if(product >= k)
    if (product >= k)
    {
      product = product / nums[low];
      low++;
    }

    // Case1: Product < k
    // if(product < k)
    count = count + (high - low + 1);
  }
  return count;
}
int main()
{
  vector<int> nums = {1, 2, 3, 4};
  int k = 10;

  int result = numSubarrayProductLessThanK(nums, k);

  cout << "Number of subarrays with product less than " << k << " : " << result;

  return 0;
}