class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        num = nums[0]
        for i in nums:
            if abs(i) < abs(num):
                num = i
        if abs(num) in nums:
            return abs(num)
        return num