class Solution:
    def numberOfWeakCharacters(self, prop: List[List[int]]) -> int:
        
        maxD = [0]*100002
        
        for p in prop:
            maxD[p[0]] = max(maxD[p[0]],p[1])
            
            
        for i in range(100000,-1,-1):
            maxD[i] = max(maxD[i],maxD[i+1])
            
        ans = 0
        for p in prop:
            if maxD[p[0]+1] > p[1]:
                ans += 1
                
        return ans
            
                    