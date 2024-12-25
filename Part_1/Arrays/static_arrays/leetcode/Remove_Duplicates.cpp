#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> &nums)
{
    if (nums.size() == 0) return 0;

    std::size_t index = 0;

    for (size_t i = 1; i < nums.size(); i++)
    {
      if (nums[i] != nums[index]) {
        index++;
        nums[index] = nums[i];
      }
    }
    
    nums.resize(index + 1);

    return nums.size();
}

int main()
{
    std::vector<int> nums = {0, 1, 1, 1, 1, 2, 2, 3, 3, 4};

    int newSize = removeDuplicates(nums);

    std::cout << "The new size of the array is: " << newSize << std::endl;
    std::cout << "The array after removing duplicates: ";

    for (int num : nums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
