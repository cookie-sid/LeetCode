class Solution:
    def numberOfWeakCharacters(self, p: List[List[int]]) -> int:
        p.sort()
        n = len(p)
        # print(p)
        
        maxi = None
        ans = 0
        i = n - 1
        while i >= 0:
            # print(i)
            # print(ans)
            if i == n - 1:
                maxi = p[i][1]
                while i - 1 >= 0 and p[i-1][0] == p[i][0]:
                    i -= 1
                
            else:
                maxiThis = p[i][1]
                ans = (ans + 1) if p[i][1] < maxi else ans
                while i - 1 >= 0 and p[i-1][0] == p[i][0]:
                    i -= 1
                    ans = (ans + 1) if p[i][1] < maxi else ans
                    maxiThis = max(maxiThis,p[i][1])
                maxi = max(maxi,maxiThis)
            
            i -= 1
            
                
        return ans
        