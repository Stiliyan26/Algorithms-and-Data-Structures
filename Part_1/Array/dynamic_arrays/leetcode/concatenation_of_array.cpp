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

void getConcatenationBest(const std::vector<int> &nums, std::vector<int>& ans)
{
  ans.resize(2 * nums.size(), 0);

  for (size_t i = 0; i < nums.size(); i++)
  {
    ans[i] = nums[i];
    ans[i + nums.size()] = nums[i];
  }
}


std::vector<int>& getConcatenationRefrence(std::vector<int> &nums)
{
  std::vector<int> *ans = new std::vector<int>(nums.size() * 2);

  for (size_t i = 0; i < nums.size(); i++)
  {
    (*ans)[i] = nums[i];
    (*ans)[i + nums.size()] = nums[i];
  }

  return *ans;
}

std::vector<int>& getConcatenationNTimesRefrence(std::vector<int> &nums, int n)
{
  std::vector<int> *ans = new std::vector<int>;
  ans->reserve(nums.size() * n);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < nums.size(); j++)
    {
      ans->push_back(nums[j]);
    }
  }

  return *ans;
}

void testVersionWithOneConcatentation()
{
  std::vector<int> nums = {1, 2, 1};

  // Receive a reference to the heap-allocated vector
  std::vector<int> &result = getConcatenationRefrence(nums);

  // Print the concatenated vector
  for (int val : result)
  {
    std::cout << val << " ";
  }

  delete &result;
}

void testVersionWithNConcatentation()
{

  int n;
  std::cout << "Enter n concatenations: " << std::endl;
  std::cin >> n;

  std::vector<int> nums = {1, 2, 1};

  std::vector<int>& result = getConcatenationNTimesRefrence(nums, n);

  // Print the concatenated vector
  for (int val : result)
  {
    std::cout << val << " ";
  }

  delete &result;
}

int main()
{
  testVersionWithNConcatentation();
  
  return 0;
}