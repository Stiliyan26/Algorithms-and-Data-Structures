from typing import List

def removeDuplicates(nums: List[int]) -> int:
  l = 1
  
  for r in range(1, len(nums)):
    if nums[r] != nums[r - 1]:
      nums[l] = nums[r]
      l += 1
      
  return l

nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]

# Call the function and get the new size
new_size = removeDuplicates(nums)
print("The new size of the array is:", new_size)
print("The array after removing duplicates:", nums[:new_size])