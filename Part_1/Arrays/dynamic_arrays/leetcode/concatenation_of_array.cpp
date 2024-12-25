#include <iostream>
#include <vector>

std::vector<int> getConcatenation(std::vector<int> &nums)
{
  std::vector<int> ans(nums.size() * 2);

  for (size_t i = 0; i < nums.size(); i++)
  {
    ans[i] = nums[i]; 
    ans[i + nums.size()] = nums[i];
  }

  return ans;
}

std::vector<int>& getConcatenationRefrence(std::vector<int> &nums)
{
  std::vector<int>* ans = new std::vector<int>(nums.size() * 2);

  for (size_t i = 0; i < nums.size(); i++)
  {
    (*ans)[i] = nums[i]; 
    (*ans)[i + nums.size()] = nums[i];
  }

  return *ans;
}

int main()
{
  std::vector<int> nums = {1, 2, 1};

  // Receive a reference to the heap-allocated vector
  std::vector<int>& result = getConcatenationRefrence(nums);

  // Print the concatenated vector
  for (int val : result)
  {
    std::cout << val << " ";
  }

  delete &result;

  return 0;
}