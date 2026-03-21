// * Question :- Pair with given sum in a sorted array
// & Link :- https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1

// & Method 1 :- Brute Force Method
// ^ T.C = O(n^2)
// ^ S.C = O(1)

// #include <iostream>
// #include <vector>
// using namespace std;
// int countPairs(vector<int> &arr, int target)
// {
//   int n = arr.size();
//   int count = 0;

//   for (int i = 0; i < n - 1; i++)
//   {
//     for (int j = i + 1; j < n; j++)
//     {
//       if (arr[i] + arr[j] == target)
//       {
//         count++;
//       }
//     }
//   }

//   return count;
// }
// int main()
// {
//   vector<int> arr = {-1, 1, 5, 5, 7};
//   int target = 6;

//   int result = countPairs(arr, target);

//   cout << "The number of pairs are : " << result;

//   return 0;
// }

// & Method 2 :- 2 Pointer Method
// ^ T.C = O(n)
// ^ S.C = O(1)

// #include <iostream>
// #include <vector>
// using namespace std;
// int countPairs(vector<int> &arr, int target)
// {
//   int n = arr.size();

//   int left = 0;
//   int right = n - 1;
//   int count = 0;

//   // traverse the array
//   while (left < right)
//   {
//     int sum = arr[left] + arr[right];

//     // agar sum == target hai to
//     if (sum == target)
//     {
//       // Case 1 :- agar dono side same value hai to count kro
//       if (arr[left] == arr[right])
//       {
//         // k ke value nikal le right - left + 1 se
//         int k = right - left + 1;

//         // then count kra hai using formula
//         count = count + (k * (k - 1)) / 2;
//         break;
//       }
//       else
//       {
//         // Case 2 :- count duplicates values on left side
//         // arr[left] ke value leftVal me store kr le hai
//         int leftVal = arr[left];

//         // c1 me count store krenge duplicates value ka
//         int c1 = 0;

//         // jab tak left <= hai right ke or
//         // arr[left] == leftval ke tab tak loop chlega or count krega
//         while (left <= right && arr[left] == leftVal)
//         {
//           c1++;
//           left++;
//         }

//         // Case 3 :- count duplicates values on right side
//         // arr[right] ke value rightVal me store kr le hai
//         int rightVal = arr[right];

//         // c2 me count store krenge duplicates value ka
//         int c2 = 0;

//         // jab tak right >= left ke tab ke or
//         // jab tak arr[right] == rightVal ke tan tal loop chlega
//         // or count krenge
//         while (right >= left && arr[right] == rightVal)
//         {
//           c2++;
//           right--;
//         }

//         // ab last me jo pehle count hai uss me add krenge
//         // c1 * c2 ko
//         count = count + c1 * c2;
//       }
//     }
//     else if (sum < target)
//     {
//       left++;
//     }
//     else
//     {
//       right--;
//     }
//   }

//   return count;
// }
// int main()
// {
//   vector<int> arr = {-1, 1, 5, 5, 7};
//   int target = 6;

//   int result = countPairs(arr, target);

//   cout << "The number of pairs are : " << result;

//   return 0;
// }

// & Method 3 :- Hashmap
// ^ T.C = O(n)
// ^ S.C = O(1)

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int countPairs(vector<int> &arr, int target)
{
  int n = arr.size();
  int count = 0;
  unordered_map<int, int> f;

  for (int i = 0; i < n; i++)
  {
    int diff = target - arr[i];

    // check diff is present in hashmap or not
    // agar hashmap me diff mil gya hai to
    // count ++ kro
    // or freq. of curr. element bhe store kro
    if (f.find(diff) != f.end())
    {
      count = count + f[diff];
    }
    f[arr[i]]++;
  }

  return count;
}
int main()
{
  vector<int> arr = {-1, 1, 5, 5, 7};
  int target = 6;

  int result = countPairs(arr, target);

  cout << "The number of pairs are : " << result;

  return 0;
}
