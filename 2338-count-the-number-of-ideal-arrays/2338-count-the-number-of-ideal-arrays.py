class Solution:
    def idealArrays(self, n: int, maxValue: int) -> int:
        
        @lru_cache(None)
        def gen(k):
            return math.comb(n-1,k-1);
        
        @lru_cache(None)
        def dp(val,length):
            res = gen(length)
            tmp = 2*val
            if(length == n or tmp > maxValue):
                return res
            while(tmp <= maxValue):
                res += dp(tmp,length+1)
                tmp += val
            
            return res
        
        return sum([dp(i,1) for i in range(1,maxValue+1)]) % (10**9 + 7)
                