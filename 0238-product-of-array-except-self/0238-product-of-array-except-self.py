class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        leftProd = 1
        rightProd = 1
        ans = [1]*n
        for i in range(0,n):
            ans[i] *= leftProd
            ans[n - 1 - i] *= rightProd
            rightProd *= nums[n - 1 - i]
            leftProd *= nums[i]
            # print(ans)
        
        return ans
                
        