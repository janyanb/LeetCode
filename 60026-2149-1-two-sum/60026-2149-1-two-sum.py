class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        index = []
        for i,num1 in enumerate(nums):
            for j,num2 in enumerate(nums):
                if num1 + num2 == target and i != j:
                    index.append(i)
                    index.append(j)
                    return index

                 