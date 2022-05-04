class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        # This dictionary stores the position where we find a character
        lastOccuredAt = dict()
        
        # Stores the index from where the current substring starts from
        currSubstringStartsAt = 0
        
        # Stores the final answer
        ans = 0
        
        # Looping through the string once
        for i in range(len(s)):
            
            currChar = s[i]
            
            # Checks if current character has previously occured 
            # if it hasn't just take in current substring
            # if it has check if the index at which it occured is before the start index for curr substring
            if (currChar not in lastOccuredAt or lastOccuredAt[currChar] < currSubstringStartsAt) :
                lastOccuredAt[currChar] = i
                ans = max(ans, i - currSubstringStartsAt + 1)
                
            else:
                currSubstringStartsAt = lastOccuredAt[currChar] + 1
                lastOccuredAt[currChar] = i
                ans = max(ans, i - currSubstringStartsAt + 1)
        
        return ans
        # Time Complexity: O(n)  Space Complexity: O(k) where k is number of distinct chars in a string