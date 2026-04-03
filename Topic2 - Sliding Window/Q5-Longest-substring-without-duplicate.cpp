// * Question :- 3. Longest Substring Without Repeating Characters
// & Link :- https://leetcode.com/problems/longest-substring-without-repeating-characters/description/?source=submission-ac

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

int lengthOfLongestSubstring(string s)
{
  int n = s.size();

  unordered_map<char, int> f;

  int low = 0;
  int high = 0;
  int res = INT_MIN;

  for (high = 0; high < n; high++)
  {
    // high ko include kr diya hai
    f[s[high]]++;

    // current window ki length calculate kr de hai
    int k = high - low + 1;

    // Case1: f.size() < k
    // agar aisa hai to low ko decrease kro
    while (f.size() < k)
    {
      f[s[low]]--;

      if (f[s[low]] == 0)
      {
        f.erase(s[low]);
      }

      low++;

      // low ko decrease krne ke baad curr. window ka size calculate kr diya hai
      // or agar low == 0 ho gya hai to then usko remove kr diya hai
      // and uske baad bhe k ko update kr diya hai
      k = high - low + 1;
    }

    // Case2: f.size() == k
    res = max(res, high - low + 1);
  }
  return res;
}

int main()
{
  string s = "abcabcbb";

  int result = lengthOfLongestSubstring(s);

  cout << "The length of the longest substring without repeating characters is : " << result;

  return 0;
}