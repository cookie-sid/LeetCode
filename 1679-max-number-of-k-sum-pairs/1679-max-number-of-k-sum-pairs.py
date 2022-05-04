class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        m = dict()
        for p in nums:
            if p in m:
                m[p] += 1
            else:
                m[p] = 1
                
        ans = 0
        for x in m.keys():
            if k - x >= x and (k - x) in m:
                if x == k - x:
                    ans += m[x]//2
                else:
                    ans += min(m[x], m[k - x])
        
        return ans