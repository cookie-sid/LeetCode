class Solution:
    def idealArrays(self, n: int, mx: int) -> int:
        
        @lru_cache(None)
        def gen(k):            
            return math.comb(n-1, k-1)

        @lru_cache(None)
        def dp(cur, l):
            res = gen(l)
            nxt = cur * 2
            if l == n or nxt > mx:
                return res
            while nxt <= mx:
                res += dp(nxt, l+1)
                nxt += cur
            return res
                
        return sum([dp(i, 1) for i in range(1, mx+1)]) % (10**9 + 7)