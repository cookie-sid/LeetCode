class Solution:
    
    def smallestNumber(self, num: int) -> int:
        
        def getS(num):
            tmp = str(num)
            tmp = sorted(tmp)
            for c in range(len(tmp)):
                if tmp[c] != "0":
                    tmp[c], tmp[0] = tmp[0], tmp[c]
                    break
            tmp = ''.join(tmp)
            return int(tmp)
        
        def getB(num):
            tmp = str(num)
            tmp = ''.join(sorted(tmp, reverse = True))
            return int(tmp)
        
        if num < 0:
            return -getB(-num)
        else:
            return getS(num)