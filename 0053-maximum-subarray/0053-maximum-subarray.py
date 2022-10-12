class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        total = 0
        best = nums[0]
        for num in nums:
            total = max(total + num, num)
            best = max(best,total)
            
        return best
    
        