// * Question :- 76. Minimum Window Substring
// & Link :- https://leetcode.com/problems/minimum-window-substring/description/
// ^ Link :- https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;
string minWindow(string s, string t)
{
  int n = s.size();
  int m = t.size();

  if (m > n)
  {
    return {};
  }

  unordered_map<char, int> f;

  for (int i = 0; i < m; i++)
  {
    f[t[i]]++;
  }

  int low = 0;
  int high = 0;
  int count = m; // total required characters
  int minLength = INT_MAX;
  string ans;    // final answer substring
  int start = 0; // final answer ka starting index

  // sliding window pattern start here
  for (high = 0; high < n; high++)
  {
    f[s[high]]--;

    // Agar char useful tha (t me exist karta hai), tabhi count kam hoga
    // Agar extra hai → ignore
    if (f[s[high]] >= 0)
    {
      count--;
    }

    // jb count 0 ho jaye
    // iska matlab hai ke abhi ke window me sare char exist karte hai
    while (count == 0)
    {
      // agar current window choti hai min length se update kro
      if (high - low + 1 < minLength)
      {
        // then min length ko update kro
        minLength = high - low + 1;
        start = low; // start index ko update kr diya hai
      }

      // window ko shrink kr rhe hai
      // low pointer chars ko hta rhe hai
      f[s[low]]++;

      // agar char useful tha (t me exist karta hai), tabhi count badhega
      // agar extra hai -> ignore
      if (f[s[low]] > 0)
      {
        count++;
      }

      low++; // window shrink
    }
  }

  return (minLength == INT_MAX) ? "" : s.substr(start, minLength);
}
int main()
{
  string s = "ADOBECODEBANC";
  string t = "ABC";

  string result = minWindow(s, t);

  cout << "Minimum window substring: " << result;

  return 0;
}