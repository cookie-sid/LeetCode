class Solution:
    
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        sortedNums = sorted(nums)
        n = len(nums)
        first = None
        last = None
        for i in range(0,n):
            if nums[i] != sortedNums[i]:
                if first == None:
                    first = i
                last = i
        
        if first == None:
            return 0
        
        return last - first + 1