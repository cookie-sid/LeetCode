class Solution:
    def minimumDeletions(self, s: str) -> int:
        countB = 0
        ans = 0
        for c in s:
            if c == 'a':
                ans = min(ans + 1,countB)
            else:
                countB += 1
        
        return ans