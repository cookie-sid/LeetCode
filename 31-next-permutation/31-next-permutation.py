class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        last = len(nums) - 1
        temp = 0
        
        
        foundSorted = False
        for i in range(last,0,-1):
            if nums[i] > nums[i-1]:
                foundSorted = True
                temp = i
                break
                
        nums[temp:] = sorted(nums[temp:])
        if temp == 0:
            return nums
        
        ind = bisect.bisect_right(nums[temp:], nums[temp-1], lo=0, hi=len(nums[temp:]))
        nums[temp + ind], nums[temp - 1] = nums[temp - 1], nums[temp + ind]