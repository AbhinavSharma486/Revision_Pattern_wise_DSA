// * Question :- 424. Longest Repeating Character Replacement
// & Link :- https://leetcode.com/problems/longest-repeating-character-replacement/description/?source=submission-ac

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

// hashmap me se maxcount of character nikalne ke liye function
int find(unordered_map<char, int> &f)
{
  int maxCount = -1;

  for (auto &x : f)
  {
    maxCount = max(maxCount, x.second);
  }

  return maxCount;
};

int characterReplacement(string s, int k)
{
  int n = s.size();

  int low = 0, high = 0;
  unordered_map<char, int> f;
  int res = INT_MIN;

  for (high = 0; high < n; high++)
  {
    // high ko include kro
    f[s[high]]++;

    // len me current window ka size (length) store kr rhe hai
    int len = high - low + 1;
    int maxCount = find(f);
    int diff = len - maxCount;

    // Case1: diff > k
    // window ko shrink krna padega
    if (diff > k)
    {
      // low ko exclude kro
      f[s[low]]--;

      // low ko aage badha diya hai
      low++;

      // low ko aage badhane ke baad
      // current window ka size calculate kr diya hai
      len = high - low + 1;

      // low ko aage badhane ke baad
      // current window ka size calculate krne ke baad
      // maxCount again calculate kr diya hai
      maxCount = find(f);

      // low ko aage badhane ke baad
      // current window ka size calculate krne ke baad
      // maxCount calculate krne ke baad
      // ab difference bhe calculate kr diya hai
      diff = len - maxCount;
    }

    // Case2: diff <= k
    // window ka current size calculat kro
    len = high - low + 1;
    res = max(res, len);
  }
  return res;
}
int main()
{
  string s = "AABABBA";
  int k = 1;

  int result = characterReplacement(s, k);

  cout << "The length of the longest substring that can be obtained by replacing at most " << k << " characters is : " << result;

  return 0;
}