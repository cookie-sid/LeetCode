class Solution:
    def numberOfWeakCharacters(self, p: List[List[int]]) -> int:
        p.sort()
        pmax = p[len(p) - 1][0]
        maxi = p[len(p) - 1][1]
        n = len(p)
        lp = pmax
        ans = 0
        newMaxi = -1
        for i in range(n-2,-1,-1):
            if p[i][0] == lp:
                if lp == pmax:
                    continue
                else:
                    ans += 1 if p[i][1] < maxi else 0
                    newMaxi = max(newMaxi,p[i][1])
            else:
                maxi = max(maxi,newMaxi)
                ans += 1 if p[i][1] < maxi else 0
                lp = p[i][0]
                newMaxi = p[i][1]
                
        return ans
        