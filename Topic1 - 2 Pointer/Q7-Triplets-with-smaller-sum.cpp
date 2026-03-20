// * Question :- Triplets with smaller sum
// & Link :- https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int tripletsWithSmallerSum(vector<int> &nums, int target)
{
  // sbse pehle given array ko sort kro
  sort(nums.begin(), nums.end());

  int n = nums.size();

  // left or right pointer define or initialize kr diya hai
  int left = 0;
  int right = n - 1;

  // count me triplets ka count store krenge
  int count = 0;

  // traverse the given array
  for (int i = 0; i < n - 1; i++)
  {
    // leff pointer ko i + 1 kr diya hai
    left = i + 1;
    // right pointer ko n - 1 kr diya hai
    right = n - 1;

    // jab tak left < right se
    // 2 pointer approach start from here
    while (left < right)
    {
      // current sum calculate kiay hai left, right and nums[i] ka
      int sum = nums[i] + nums[left] + nums[right];

      // agar current sum >= target hai to right-- kro
      if (sum >= target)
      {
        right--;
      }

      // else ka matlab hai ke current sum < target hai
      // to count ko update kro
      // or left ++ kro
      else
      {
        count = count + (right - left);
        left++;
      }
    }
  }

  return count;
}
int main()
{
  vector<int> nums = {1, 0, -2, 3};
  int target = 2;

  int result = tripletsWithSmallerSum(nums, target);

  cout << "The number of triplets are : " << result;

  return 0;
}