// * Question :- 992. Subarrays with K Different Integers
// & Link :- https://leetcode.com/problems/subarrays-with-k-different-integers/description/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// at most k
int atMostK(vector<int> &nums, int k)
{
  int n = nums.size();

  int low = 0;
  int high = 0;
  int count = 0;

  unordered_map<int, int> f;

  for (high = 0; high < n; high++)
  {
    // high ko include kro
    f[nums[high]]++;

    // ab check kro ke kitne distinct elements hai
    while (f.size() > k)
    {
      // low ko exclude kro
      f[nums[low]]--;

      // agar low ka frequency 0 ho jata hai to usko map se remove krdo
      if (f[nums[low]] == 0)
      {
        f.erase(nums[low]);
      }

      low++;
    }

    if (f.size() <= k)
    {
      count = count + (high - low + 1);
    }
  }

  return count;
}

// exactly k
// exactly k = atmost k - atmost k - 1;
int subarraysWithKDistinct(vector<int> &nums, int k)
{
  int count1 = atMostK(nums, k);
  int count2 = atMostK(nums, k - 1);
  int answer = count1 - count2;
  return answer;
}
int main()
{
  vector<int> nums = {1, 2, 1, 2, 3};
  int k = 2;

  int result = subarraysWithKDistinct(nums, k);

  cout << "Number of subarrays with " << k << " different integers: " << result;

  return 0;
}