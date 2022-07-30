class Solution:
    def maximumsSplicedArray(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        sumOfNums1 = sum(nums1)
        sumOfNums2 = sum(nums2)
        
        ans = max(sumOfNums1,sumOfNums2)
        
        tmp = [0]*n
        for i in range(0,n):
            tmp[i] = nums1[i] - nums2[i]
            
        worst = 0
        total = 0
        for i in range(0,n):
            if total + tmp[i] > 0:
                total = 0
            else:
                total += tmp[i]
                
            worst = min(worst,total)
        
        ans = max(ans,sumOfNums1  - worst)
        
        for i in range(0,n):
            tmp[i] = -tmp[i]
            
        worst = 0
        total = 0
        for i in range(0,n):
            if total + tmp[i] > 0:
                total = 0
            else:
                total += tmp[i]
                
            worst = min(worst,total)
        
        ans = max(ans,sumOfNums2  - worst)
        
        return ans