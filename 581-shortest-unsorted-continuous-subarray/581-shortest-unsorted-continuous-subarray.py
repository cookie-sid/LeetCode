class Solution:
    
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        index = None
        first = None
        for i in range(n - 1, -1, -1):
            
            if index != None:
                if nums[i] > mini:
                    first = i
                    maxi = max(maxi, nums[i])
                    continue
                else:
                    mini = min(mini, nums[i])
                    maxi = max(maxi, nums[i])
            
            if i > 0 and nums[i] < nums[i-1]:
                if index == None:
                    index = i
                    first = i - 1
                    maxi = nums[i-1]
                    mini = nums[i]
        
        if(index == None):
            return 0
        
#         print(str(first) + " " + str(index))
        last = index
        for i in range(index + 1, n):
            if(nums[i] < maxi) :
                last += 1
                
        return last - first + 1
                
        
        