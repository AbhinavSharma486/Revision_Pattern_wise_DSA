// * Question :- 283. Move Zeroes
// & Link :- https://leetcode.com/problems/move-zeroes/description/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> moveZeroes(vector<int> &nums)
{
  int n = nums.size();

  int pos = 0;

  // ek for loop chalaya hai
  // jab tak i < n hai tab tak
  // iss me hm check krenge ke
  // jo bhe non zero elements hai unko pos index ke according array me shift krenge
  // and pos ko ++ karte rehenge
  for (int i = 0; i < n; i++)
  {
    // agar nums[i] != 0 hai to
    // nums[pos] = nums[i] kr denge
    // or pos ko ++ krenge
    if (nums[i] != 0)
    {
      nums[pos] = nums[i];
      pos++;
    }
  }

  // ab ek time aisa aayega ke pos kuch index pehle ruk jayega
  // then ab jha pr pos ruka hai wha se or n tak ek loop chlega
  // sare elements pos ke index ke according 0 kr denge
  while (pos < n)
  {
    nums[pos] = 0;
    pos++;
  }

  return nums;
}
int main()
{
  vector<int> nums = {0, 1, 0, 3, 12};

  vector<int> result = moveZeroes(nums);

  cout << "[";
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }
  cout << "]";

  return 0;
}