// * Question :- 287. Find the Duplicate Number
// & Link :- https://leetcode.com/problems/find-the-duplicate-number/description/?source=submission-ac

// ^ Approach 1 :- Using Fast and Slow Pointer
#include <iostream>
#include <vector>
using namespace std;
int findDuplicate(vector<int> &nums)
{
  int slow = 0;
  int fast = 0;

  while (true)
  {
    slow = nums[slow];
    fast = nums[fast];
    fast = nums[fast];

    if (slow == fast)
    {
      slow = 0;

      while (slow != fast)
      {
        slow = nums[slow];
        fast = nums[fast];
      }

      return slow;
    }
  }

  return 0;
}
int main()
{
  vector<int> nums = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};

  int duplicate = findDuplicate(nums);

  cout << "The duplicate number is : " << duplicate;

  return 0;
}









// ^ Approach 2 :- Using Hash map
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int findDuplicate(vector<int> &nums)
{
  int n = nums.size();

  unordered_map<int, int> f;

  for (int i = 0; i < n; i++)
  {
    f[nums[i]]++;
  }

  for (auto i : f)
  {
    if (i.second > 1)
    {
      return i.first;
    }
  }
  return -1;
}
int main()
{
  vector<int> nums = {3, 1, 3, 4, 2};

  int duplicate = findDuplicate(nums);

  cout << "The duplicate number is : " << duplicate;

  return 0;
}
