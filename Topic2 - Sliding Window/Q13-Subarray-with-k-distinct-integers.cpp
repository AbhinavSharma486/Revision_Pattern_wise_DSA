// * Question :- Subarrays with K Distinct Integers
// & Link :- https://www.geeksforgeeks.org/problems/subarrays-with-k-different-integers/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// at most k
int atMostK(vector<int> &arr, int k)
{
  int n = arr.size();

  int low = 0;
  int high = 0;
  int count = 0;

  unordered_map<int, int> f;

  for (high = 0; high < n; high++)
  {
    // high ko include kro
    f[arr[high]]++;

    // ab check kro ke kitne distinct elements hai
    while (f.size() > k)
    {
      // low ko exclude kro
      f[arr[low]]--;

      // agar low ka frequency 0 ho jata hai to usko map se remove krdo
      if (f[arr[low]] == 0)
      {
        f.erase(arr[low]);
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
int exactlyK(vector<int> &arr, int k)
{
  int count1 = atMostK(arr, k);
  int count2 = atMostK(arr, k - 1);
  int answer = count1 - count2;
  return answer;
}
int main()
{
  vector<int> nums = {3, 1, 2, 2, 3};
  int k = 3;

  int result = exactlyK(nums, k);

  cout << "Number of subarrays with " << k << " different integers: " << result;

  return 0;
}