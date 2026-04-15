// * Question :- 2461. Maximum Sum of Distinct Subarrays With Length K
// & Link :- https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/description/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
long long maximumSubarraySum(vector<int> &nums, int k)
{
  int n = nums.size();

  unordered_map<int, int> f;

  int low = 0;
  int high = 0;
  long long sum = 0;
  long long ans = 0;

  // calculating the sum of the first fixed sized window of size k
  for (high = 0; high < n; high++)
  {
    // adding the new element to the sum
    sum = sum + nums[high];

    // increasing the freq. of the new element in hashmap
    f[nums[high]]++;

    // element ke freq. 1 se zyada nhi honi chaiye
    // kyuki hm distinct subarrays chahte hai
    // iss liye jb bhe freq. 1 se zyada ho jaye
    // to hm low pointer se elements ko remove krte jayenge jb tak freq. 1 nhi ho jati
    // or high - low + 1 agar > k hai to bhi hm low pointer se elements ko remove krte jayenge jb tak window ka size k ke barabar nhi ho jata hai
    // kyuki hm fixed sized window chahte hai jiska size k ho
    while (f[nums[high]] > 1 || high - low + 1 > k)
    {
      // sum me se low ko subtract kr diya hai
      sum = sum - nums[low];

      // hashmap me low ki freq. decrease kr diya hai
      f[nums[low]]--;

      // agar low ki freq. 0 ho jati hai to uss element ko hashmap se erase kr diya hai
      if (f[nums[low]] == 0)
      {
        f.erase(nums[low]);
      }

      // low ko aage badha diya hai
      low++;
    }

    // agar current window ka size k ke barabar hai to ans me max sum ko update kr diya hai
    if (high - low + 1 == k)
    {
      if (f.size() == k)
      {
        ans = max(ans, sum);
      }
    }
  }

  return ans;
}
int main()
{
  vector<int> nums = {1, 5, 4, 2, 9, 9, 9};
  int k = 3;

  long long result = maximumSubarraySum(nums, k);

  cout << "Maximum sum of distinct subarrays with length " << k << ": " << result;

  return 0;
}