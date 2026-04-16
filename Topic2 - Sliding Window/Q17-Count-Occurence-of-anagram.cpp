// * Question :- Count Occurences of Anagrams
// & Link :- https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int search(string &txt, string &pat)
{
  vector<int> result;
  int n = txt.size();
  int m = pat.size();

  if (m > n)
  {
    return result.size();
  }

  unordered_map<char, int> f;

  // string p ke freq. f hashmap me store kr le hai
  for (int i = 0; i < m; i++)
  {
    f[pat[i]]++;
  }

  int low = 0;
  int high = 0;

  // sliding window approach start from this loop
  for (int high = 0; high < n; high++)
  {
    // Step1: high ko window me include kro or high ke freq. ko f hashmap me decrease kr do
    f[txt[high]]--;

    // Step2: maintain window size
    // current window size > p ke size se to low ko window me exclude kro
    // or low ke freq. ko f hashmap me increase kr do
    // overall window size maintain kr rhe hai or window ko shrink kr rhe hai
    if (high - low + 1 > m)
    {
      f[txt[low]]++;
      low++;
    }

    // Step3: check if valid anagram
    // yha current window ka size == m hai
    if (high - low + 1 == m)
    {
      bool isAnagram = true;

      // ab check kr rhe hai ke hashmap me sabhi chars ke freq. 0 hai ya nhi
      // agar 0 nhi hai to
      // to iska matlab hai ke curr. window ka char ke freq. p ke char ke freq. se match nhi hoti hai
      // or yeh anagram nhi hai
      for (auto it : f)
      {
        if (it.second != 0)
        {
          isAnagram = false;
          break;
        }
      }

      // agar anagram hai to result me low index ko push kr do
      if (isAnagram)
      {
        result.push_back(low);
      }
    }
  }

  return result.size();
}
int main()
{
  string txt = "forxxorfxdofr";
  string pat = "for";

  int result = search(txt, pat);

  cout << "Number of anagrams found: " << result;

  return 0;
}