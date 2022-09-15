class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        if(len(changed) % 2 == 1):
            return []
        
        d = {}
        
        for num in changed:
            d[num] = d[num] + 1 if num in d else 1
            
        res = []
        
        keys = list(d.keys())
        keys.sort(reverse = True)
        for k in keys:
            if k == 0:
                for i in range(d[k]//2):
                    res.append(k)
                d[k] %= 2
            else:
                if 2*k in d:
                    mini = min(d[k],d[2*k])
                    for i in range(mini):
                        res.append(k)
                    d[k] -= mini
                    d[2 *k] -= mini
        
        for k in d:
            if d[k] != 0:
                return []
            
        return res
        
                
            
        