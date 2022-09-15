class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        if(len(changed) % 2 == 1):
            return []
        maxN = 100001
        count = [0] * maxN
        
        maxi = -1
        for num in changed:
            count[num] += 1
            maxi = max(maxi,num)
            
            
        res = []
        for num in range(maxi,0,-1):
            mini = min(count[num],count[num//2])
            if(count[num] == 0):
                continue
            if(num % 2 != 0 and count[num] != 0):
                return []
            temp = [num//2]*mini
            count[num] -= mini
            count[num//2] -= mini
            res.extend(temp)
            if(count[num] != 0):
                return []
        
        if(count[0] % 2 != 0):
            return []
        
        temp = [0] * (count[0]//2)
        res.extend(temp)
            
        
        return res
            
                
            
        