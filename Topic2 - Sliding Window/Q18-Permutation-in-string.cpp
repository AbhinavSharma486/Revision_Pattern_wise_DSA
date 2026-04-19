// * Question :- 567. Permutation in String
// & Link :- https://leetcode.com/problems/permutation-in-string/description/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
bool checkInclusion(string s1, string s2)
{
  int n = s1.size();
  int m = s2.size();

  if (n > m)
  {
    return {};
  }

  unordered_map<char, int> f;

  // s1 string ke sare chars ke frequency ka count hashmap me store kr diya hai
  for (int i = 0; i < n; i++)
  {
    f[s1[i]]++;
  }

  int low = 0;
  int high = 0;

  for (high = 0; high < m; high++)
  {
    // Step1: high ko include kro
    f[s2[high]]--;

    // Case1: high - low + 1 > n
    while(high - low + 1 > n)
    {
      f[s2[low]]++;

      low++;
    }

    // Case2: high - low + 1 == n
    if(high - low + 1 == n)
    {
      bool isPermutation = true;

      for(auto it : f)
      {
        if(it.second != 0)
        {
          isPermutation = false;
        }
      }

      if(isPermutation)
      {
        return true;
      }
    }
  }

  return false;
}
int main()
{
  string s1 = "ab";
  string s2 = "eidbaooo";

  string s3 = "ab";
  string s4 = "eidboaoo";

  bool result1 = checkInclusion(s1, s2);

  cout << "Result for s1 and s2: " << (result1 ? "True" : "False");

  return 0;
}