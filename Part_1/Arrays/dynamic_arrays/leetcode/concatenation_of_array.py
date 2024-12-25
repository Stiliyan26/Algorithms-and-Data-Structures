from typing import List

def getConcatenation_V2(nums: List[int]) -> List[int]:
  ans = []
  
  for _ in range(2):
    for n in nums:
      ans.append(n)
    
  return ans


def getConcatenation(nums: List[int]) -> List[int]:
  ans = [0] * (2 * len(nums))
  
  for n in range(len(nums)):
    ans[n] = nums[n]
    ans[len(nums) + n] = nums[n]
    
  return ans


nums = [1, 2, 1]
result = getConcatenation_V2(nums)

print(result)