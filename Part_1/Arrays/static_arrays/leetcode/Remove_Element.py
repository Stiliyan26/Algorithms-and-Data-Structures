from typing import List


def removeElemnt(nums: List[int], val: int) -> int:
  k = 0;
  
  for i in range(len(nums)):
    if nums[i] != val:
      nums[k] = nums[i]
      k += 1
      
  return k
      
nums = [0, 1, 2, 2, 3, 0, 4, 2]
k = removeElemnt(nums, 2)

print(nums[:k]) 
print(k)