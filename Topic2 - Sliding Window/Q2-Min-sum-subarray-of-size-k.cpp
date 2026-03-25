// * Question :- 209. Minimum Size Subarray Sum
// & Link :- https://leetcode.com/problems/minimum-size-subarray-sum/description/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int minSubArrayLen(int target, vector<int> &nums)
{
  int n = nums.size();

  // low or high ko 0 iss liye liya hai ke minimum sub array ke length 0 bhe ho skti hai 
  int low = 0;
  int high = 0;
  int sum = 0;

  int res = INT_MAX;

  // jab tak high < n hai tab  tak loop chlega
  while (high < n)
  {
    // sum me high ko add kr liya hai
    sum = sum + nums[high];

    // Case1 : sum < target
    // Case2 : sum > target
    // Cass3 : sum == target

    // so case1 agar hai to high++ kro
    // agar case2 or case3 ko combined kr do kyuki
    // hme sum >= target chaiye 
    // agar sum > target hai to hm low ++ kr denge 
    // or sum < target hai to high++ to hoga he

    // jab tak sum >= target hai tab tak ek loop chlega
    // iss ka matlab hai ke sum ya to bda hai ya fir jb equal hoga
    // jab tak sum bda hai tab tak low++ krenge kyuki
    // jyada developers hire kr liye hai ab fire honge 

    // iss liye yeh while fire kr rha hai
    while (sum >= target)
    {
      // res me low - high + 1 kr ke length nikal kr store kr de hai
      res = min(res, high - low + 1);

      // sum me low ko subtract kr diya hai
      sum = sum - nums[low];
      low++;
    }

    // high++ iss liye kr rhe hai kyuki sum < target hai
    high++;
  }

  return res;
}
int main()
{
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;

  int result = minSubArrayLen(target, nums);

  cout << "The minimum length of subarray is : " << result;

  return 0;
}