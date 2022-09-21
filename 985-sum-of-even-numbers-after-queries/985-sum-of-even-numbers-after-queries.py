class Solution:
    def sumEvenAfterQueries(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        total = 0
        for num in nums:
            if num%2 == 0:
                total += num
        
        ans = []
        for q in queries:
            prev = nums[q[1]]
            new = nums[q[1]] + q[0]
            if prev % 2 == 0:
                if new % 2 == 0:
                    total += q[0]
                else:
                    total -= nums[q[1]]
            else:
                if new%2 == 0:
                    total += new
            
            ans.append(total)
            nums[q[1]] += q[0]
            
        return ans
                
            
        