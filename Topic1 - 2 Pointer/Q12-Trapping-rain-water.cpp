// * Question :- 42. Trapping Rain Water
// & Link :- https://leetcode.com/problems/trapping-rain-water/description/

// ^ Method 1 :- 2 pointer approach

#include <iostream>
#include <vector>
using namespace std;
int trap(vector<int> &height)
{
  int n = height.size();

  int left = 0;
  int right = n - 1;

  // starting me leftMax or rightMax 0 se initialize kr diye hai
  int leftMax = 0;
  int rightMax = 0;

  // starting me total trapper water bhe 0 hai
  int totalTrapedWater = 0;

  // 2 pointer approach start ho gye hai yha se
  while (left < right)
  {
    // yha 2 case banenge
    // case 1: height[left] < height[right]
    if (height[left] < height[right])
    {
      // yha kya ho skta hai
      // yha ho skta hai ke height[left] >= leftMax ke
      // agar aisa hai to leftMax ko update kro
      if (height[left] >= leftMax)
      {
        leftMax = height[left];
      }

      // agar leftMax update nhi kya
      // iss ka matlab hai ke height[left] < leftMax hai
      // then total trapped water calculate kro
      // total trapped water = leftMax - height[left]
      else
      {
        totalTrapedWater += (leftMax - height[left]);
      }

      // ab last me left ko ++ kr do
      left++;
    }

    // case 2: height[right] < height[left]
    else
    {
      // yha kya ho skta hai
      // yha ho skta hai ke height[right] >= rightMax hai
      // agar aisa hai to rightMax ko update kro
      if (height[right] >= rightMax)
      {
        rightMax = height[right];
      }

      // agar rightMax update nhi kya
      // iss ka matlab hai ke height[right] < rightMax hai
      // then total trapped water calculate kro
      // total trapped water = rightMax - height[right]
      else
      {
        totalTrapedWater += (rightMax - height[right]);
      }

      // then last me right ko -- kr do
      right--;
    }
  }

  return totalTrapedWater;
};
int main()
{
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

  int result = trap(height);

  cout << "The trapped water is : " << result;

  return 0;
}

// ^ Method 2 : Using Prefix or Suffix sum approach

#include <iostream>
#include <vector>
using namespace std;
int trap(vector<int> &height) {

};
int main()
{
  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

  int result = trap(height);

  cout << "The trapped water is : " << result;

  return 0;
}