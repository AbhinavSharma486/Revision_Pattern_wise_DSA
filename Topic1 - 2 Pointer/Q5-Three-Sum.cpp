// * Question :- Three Sum -> 0
// & Link :-

// & Optimized Approach :-
// ^ Time complexity :- O(n^2)
// ^ Space complexity :- O(n)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
  // sbse pehle to given array ko sort kro
  sort(nums.begin(), nums.end());

  int n = nums.size();

  // 2d vector result store krne ke liye
  vector<vector<int>> result;

  // 3 pointer approach
  for (int i = 0; i < n - 2; i++)
  {
    // agar nums[i] == nums[i-1] ho jata hai to continue krdo
    if (i > 0 && nums[i] == nums[i - 1])
    {
      continue;
    }

    int left = i + 1;
    int right = n - 1;
    int sum = -1 * nums[i];

    // 2 pointer approach start
    while (left < right)
    {
      // store the sum of left and right pointer
      int s = nums[left] + nums[right];

      // check the negative sum is equal to current left and right pointer sum
      if (s == sum)
      {
        result.push_back({nums[i], nums[left], nums[right]});
        left++;
        right--;

        // agar left or right pointer ke value same ho jata hai to increment kro
        // yeh dono while ka code remove duplicates krne ke liye hai
        while (left < right && nums[left] == nums[left - 1])
        {
          left++;
        }

        while (left < right && nums[right] == nums[right + 1])
        {
          right--;
        }
      }

      // yeh else if ka code whi 2 pointer approach wala hai 
      else if (s < sum)
      {
        left++;
      }
      else
      {
        right--;
      }
    }
  }

  return result;
};
int main()
{
  vector<int> arr = {-1, 0, 1, 2, -1, -4};

  vector<vector<int>> result = threeSum(arr);

  for (int i = 0; i < result.size(); i++)
  {
    for (int j = 0; j < result[i].size(); j++)
    {
      cout << result[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}