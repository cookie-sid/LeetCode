class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        stack = []
        for i in range(len(s)):
            if len(stack) == 0:
                stack.append([s[i],1])
            else:
                if(stack[-1][0] == s[i]):
                    stack.append([s[i],stack[-1][1] + 1])
                else:
                    stack.append([s[i],1])
                    
                if(stack[-1][1] == k):
                    stack = stack[:len(stack) - k]
                    countCurr = 0
        
        ans = ""
        for x in stack:
            ans += x[0]
        
        return ans
        