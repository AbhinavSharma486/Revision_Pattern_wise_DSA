// * Question :- 1004. Max Consecutive Ones III
// & Link :- https://leetcode.com/problems/max-consecutive-ones-iii/description/?source=submission-ac

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
int longestOnes(vector<int> &nums, int k)
{
  int n = nums.size();

  int low = 0;
  int high = 0;
  int res = 0;
  unordered_map<int, int> f;

  for (high = 0; high < n; high++)
  {
    // high ko include kr diya hai
    f[nums[high]]++;

    // high ko include krne ke baad curr. length calculate kr de hai
    int len = high - low + 1;

    // high ko add krne ke baad maxCount calculate kr diya hai
    int maxCount = f[1];

    // high ko add krne ke baad diff calculate kr diya hai
    int diff = len - maxCount;

    // Case1: diff > k
    // hashmap me 2 he freq. store hogi
    // ya to 1 ya fir 0
    // question me sidha sidha bola hai ke 0 ko he flip krna hai k times
    // so agar diff > k hai to iska matlab hai ke 0 ke freq. k se jyada hai
    // then window ko shrink krna padega
    while (diff > k)
    {
      f[nums[low]]--;

      low++;

      // low ko exclude krne ke baad curr. length calculate kr de hai
      len = high - low + 1;

      // low ko exclude krne ke baad maxCount calculate kr diya ahi
      maxCount = f[1];

      // low ko exclude krne ke baad diff calculate kr diya hai
      diff = len - maxCount;
    }

    // Case2: diff <= k
    len = high - low + 1;

    res = max(res, len);
  }

  return res;
}
int main()
{
  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;

  int result = longestOnes(nums, k);

  cout << "The longest subarray of 1's after flipping at most " << k << " zeros is : " << result;

  return 0;
}