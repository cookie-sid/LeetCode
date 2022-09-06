class Solution:
    def longestPalindrome(self, s: str) -> int:
        d = {}
        for c in s:
            d[c] = d[c] + 1 if c in d else 1
        
        ans = 0
        odd = False
        for key in d:
            ans += d[key] if d[key] % 2 == 0 else d[key] - 1
            if d[key] % 2 != 0:
                odd = True
        
        if odd:
            ans += 1
        
        return ans