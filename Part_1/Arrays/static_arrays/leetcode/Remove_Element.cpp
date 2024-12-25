#include <vector>
#include <iostream>

int removeElement(std::vector<int> &nums, int val)
{
  for (size_t i = 0; i < nums.size();)
  {
    if (nums[i] == val) {
      nums.erase(nums.begin() + i);
    } else {
      i++;
    }
  }

  return nums.size();
}

int removeElement_V2(std::vector<int> &nums, int val)
{
  int newSize = 0;

  for (size_t i = 0; i < nums.size(); i++)
  {
    if (nums[i] != val) {
      nums[newSize++] = nums[i];
    }
  }

  nums.resize(newSize);

  return newSize;
}

int main()
{
  int k;
  std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};

  std::cout << "Enter an integer: ";
  std::cin >> k;

  int size = removeElement_V2(nums, k);

  for (int num : nums)
  {
    std::cout << num << " ";
  }

  std::cout << std::endl;

  std::cout << "Size " << size << std::endl;

  return 0;
}