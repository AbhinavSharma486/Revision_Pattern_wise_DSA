// * Question :- 75. Sort Colors
// & Link :- https://leetcode.com/problems/sort-colors/description/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> sortColors(vector<int> &nums)
{
  int n = nums.size();

  int low = 0;
  int mid = 0;
  int high = n - 1;

  // 2 pointer approach lga rhe hai 
  // mid to high wale part 
  // kyuki yeh part me pta krna hai ke konse elements hai iss me 
  // jonsa bhe uss ko uss ke area me bhej do
  while (mid <= high)
  {
    // agar mid me 0 hai to 
    // uss ko low wale area me bhej do
    if (nums[mid] == 0)
    {
      swap(nums[low], nums[mid]);
      low++;
      mid++;
    }

    // agar mid me 1 hai to yeh best case hai kuch mt kro
    // bss mid++ kro
    else if (nums[mid] == 1)
    {
      mid++;
    }

    // other wise mid me 2 he hoga 
    // usko high wale area me bhej do
    else
    {
      swap(nums[mid], nums[high]);
      high--;
      mid++;
    }
  }

  return nums;
}
int main()
{
  vector<int> nums = {2, 0, 2, 1, 1, 0};

  vector<int> result = sortColors(nums);

  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << " ";
  }

  return 0;
}