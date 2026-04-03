// * Question :- 904. Fruit Into Baskets
// & Link :- https://leetcode.com/problems/fruit-into-baskets/description/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
int totalFruit(vector<int> &fruits)
{
  int n = fruits.size();

  int low = 0;
  int high = 0;
  int maxFruits = INT_MIN;
  unordered_map<int, int> f;

  for (high = 0; high < n; high++)
  {
    // sbse pehle to high ko include kr diya hai
    f[fruits[high]]++;

    // agar unordered map ki size 2 se zyada ho jati hai to low ko remove kro
    // jab tak size 2 se choti ya equal na ho jaye
    while (f.size() > 2)
    {
      f[fruits[low]]--;

      if (f[fruits[low]] == 0)
      {
        f.erase(fruits[low]);
      }

      low++;
    }

    // jab unordered map ki size 2 se choti ya equal ho jaye to maxFruits ko update kro
    if (f.size() <= 2)
    {
      maxFruits = max(maxFruits, high - low + 1);
    }
  }

  return maxFruits;
}
int main()
{
  vector<int> fruits = {1, 2, 3, 2, 2};

  cout << "The maximum number of fruits that can be collected is : " << totalFruit(fruits);

  return 0;
}