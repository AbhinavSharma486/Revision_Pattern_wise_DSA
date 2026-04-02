// * Question :- Longest Substring with k uniques
// & Link :- https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include <iostream>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;
int longestKSubstr(string &s, int k)
{
  int n = s.size();

  int low = 0;
  int high = 0;
  int res = INT_MIN;
  unordered_map<char, int> f;

  // sliding window approach start from this loop
  // ek for loop chalaya hai jo ke 0 se n - 1 tak chalega or high pointer ko move karega
  for (high = 0; high < n; high++)
  {
    // Step1: high ko window me include kro
    f[s[high]]++;

    // Step2: jab tak unique char ki count k se zyada hai tab tak low ko move kro
    // f.size() > k
    while (f.size() > k)
    {
      // low ko window se exclude kro
      f[s[low]]--;

      // agar low ka count 0 hai too uss ko remove kro hashmap se
      if (f[s[low]] == 0)
      {
        f.erase(s[low]);
      }

      // low ko move kro
      low++;
    }

    // Step3:
    if (f.size() == k)
    {
      res = max(res, high - low + 1);
    }
  }

  return res == INT_MIN ? -1 : res;
}
int main()
{
  string s = "aabacbebebe";
  int k = 3;

  int result = longestKSubstr(s, k);

  cout << "Length of the longest substring with " << k << " unique characters is : " << result;

  return 0;
}