// * Question :- 11. Container With Most Water
// & Link :- https://leetcode.com/problems/container-with-most-water/description/

#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int> &height)
{
  int n = height.size();

  int left = 0;
  int right = n - 1;

  int maxArea = 0;

  // 2 pointer approach start
  while (left < right)
  {

    // widht = right - left kr ke widht nikal le
    int width = right - left;

    // minimum of height[left] or height[right] se minimum hight nikal le
    // kyuki minimum hight se maximum water nikal skte hai
    // agar hight jyada hai to maximum water nhi nikal skte hai
    int hight = min(height[left], height[right]);

    // current area nikal liya hai width * hight kr ke
    int currArea = width * hight;

    // agar current area bda hai to
    // max area update kro current area se
    if (currArea > maxArea)
    {
      maxArea = currArea;
    }

    // agar height[left] < height[right] se to left ko ++ kro
    // height of left ka chota hone ka matlab hai ke height of right bda hai
    if (height[left] < height[right])
    {
      left++;
    }

    // otherwise right ko -- kro
    else
    {
      right--;
    }
  }

  return maxArea;
}
int main()
{
  vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

  int maxAreaResult = maxArea(height);

  cout << "The max area is : " << maxAreaResult;

  return 0;
}