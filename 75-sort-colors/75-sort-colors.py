class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        first = 0
        last = len(nums) - 1
        i = 0
        while(i <= last):
            if nums[i] == 0:
                nums[first] = 0
                first += 1
            elif nums[i] == 2:
                while(last > i and nums[last] == 2) :
                    last -= 1
                if(nums[last] == 0):
                    nums[first] = 0
                    first += 1
                nums[last] = 2
                last -= 1
            
            i += 1
        
        while(first <= last):
            nums[first] = 1
            first += 1
                
            