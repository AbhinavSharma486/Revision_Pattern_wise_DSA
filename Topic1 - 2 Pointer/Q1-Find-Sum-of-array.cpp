// * Question :- Find sum of array (using 2 pointer approach)

#include <iostream>
#include <vector>
using namespace std;

int findSum(vector<int> &arr)
{
  int n = arr.size();

  int i = 0;
  int j = n - 1;
  int sum = 0;

  // 2 pointer approach start
  while (i < j)
  {
    sum = sum + arr[i] + arr[j];
    i++;
    j--;
  }

  if (i == j)
  {
    sum = sum + arr[i];
  }

  return sum;
};
int main()
{
  vector<int> arr = {10, 20, 30, 40, 50};

  int result = findSum(arr);

  cout << "Sum of array is : " << result;

  return 0;
}