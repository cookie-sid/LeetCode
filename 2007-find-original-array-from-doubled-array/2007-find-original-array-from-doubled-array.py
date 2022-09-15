class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        if(len(changed) % 2 == 1):
            return []
        
        changed.sort()

        n = len(changed)
        
        taken = [False]*n
        double = n - 1
        single = n - 2
        res = []
        while double > -1:
            if taken[double]:
               double -= 1
            else:
                found = False
                while single >= double:
                    single -= 1
                while single > -1 and changed[single] * 2 != changed[double]:
                    single -= 1
                if single == -1:
                    return []
                else:
                    found = True
                taken[double] = True
                taken[single] = True
                res.append(changed[single])
                single -= 1
                double -= 1
        
        # 1 2 3 4 6 8
        return res
            
                
            
        