// * Question :- Max Sum Subarray of size K
// & Link :- https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

// ^ Method 1 : agar high = k - 1 lete hai to below code chlega 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxSubarraySum(vector<int> &arr, int k)
{
  int n = arr.size();

  int low = 0;
  int high = k - 1;

  // max sum me current window ka sum store hoga
  int currmaxSum = 0;

  // res me overall max sum store hoga
  int res = 0;

  // initially max sum me first k elements ka sum store kr rhe hai
  // yeh bss ek he baar hoga starting me
  for (int i = 0; i <= high; i++)
  {
    currmaxSum = currmaxSum + arr[i];
  }

  // ab ek baar max sum calculate ho gya hai first k size window ka
  // ab ek loop chlega high jb tak n se chota hai tab tak
  // then ab hm res me store krenge max sum
  // jo bhe max sum hoga pehle or current jonse bhe max hoga vo res me store ho jayega
  while (high <= n)
  {
    // res me max sum store kr ke low ++ kr diya hai and high ++ bhe kr diya hai iss se window move ho jayegi
    res = max(res, currmaxSum);
    low++;
    high++;

    // ab check kiya hai ke high == n to nhi hua
    // agar ho jata hai to break kr do
    if (high == n)
    {
      break;
    }

    // agar high == n nhi hua hai to
    // next window ka max sum calculate kro
    // max sum = max sum - arr[low - 1](pehla low pointer ka element delete kr diya hai) + arr[high](high pointer ka element add kr diya hai)
    currmaxSum = currmaxSum - arr[low - 1] + arr[high];
  }

  return res;
}
int main()
{
  vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
  int k = 4;

  int result = maxSubarraySum(arr, k);

  cout << "The maximum subarray of size " << k << " is : " << result;

  return 0;
}




// ^ Method 2 : agar high = k lete hai to below code chlega

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int maxSubarraySum(vector<int> &arr, int k)
{
  int n = arr.size();

  int low = 0;
  int high = k;

  int currmaxSum = 0;

  int res = 0;

  for (int i = 0; i < high; i++)
  {
    currmaxSum = currmaxSum + arr[i];
  }

  while (high < n)
  {
    res = max(res, currmaxSum);

    currmaxSum = currmaxSum - arr[low] + arr[high];

    low++;
    high++;
  }

  return res;
}
int main()
{
  vector<int> arr = {1, 4, 2, 10, 23, 3, 1, 0, 20};
  int k = 4;

  int result = maxSubarraySum(arr, k);

  cout << "The maximum subarray of size " << k << " is : " << result;

  return 0;
}