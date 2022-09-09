class Solution:
    def numberOfWeakCharacters(self, prop: List[List[int]]) -> int:
        
        maxiA = -1
        for p in prop:
            maxiA = max(maxiA,p[0])
        
        maxD = [0]*(maxiA+1)
        
        for p in prop:
            maxD[p[0]] = max(maxD[p[0]],p[1])
            
            
        for i in range(maxiA-1,-1,-1):
            maxD[i] = max(maxD[i],maxD[i+1])
            
        ans = 0
        for p in prop:
            if p[0] != maxiA and maxD[p[0]+1] > p[1]:
                ans += 1
                
        return ans
            
                    