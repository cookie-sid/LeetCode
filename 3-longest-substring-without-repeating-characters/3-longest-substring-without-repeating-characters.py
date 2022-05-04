class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        lastOccuredAt = dict()
        
        currSubstringStartsAt = 0
        ans = 0
        
        for i in range(len(s)):
            currChar = s[i]
            if (currChar not in lastOccuredAt or lastOccuredAt[currChar] < currSubstringStartsAt) :
                lastOccuredAt[currChar] = i
                ans = max(ans, i - currSubstringStartsAt + 1)
            else:
                currSubstringStartsAt = lastOccuredAt[currChar] + 1
                lastOccuredAt[currChar] = i
                ans = max(ans, i - currSubstringStartsAt + 1)
        
        return ans