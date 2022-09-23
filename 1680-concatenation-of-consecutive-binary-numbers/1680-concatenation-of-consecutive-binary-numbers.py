class Solution:
    
    def concatenatedBinary(self, n: int) -> int:
        
        numOfBits = 1
        
        val = 1
        d = {}
        while val * 2 <= 100000:
            val *= 2
            d[val] = 1
            
        ans = 1
        for i in range(2,n+1):
            if i in d:
                numOfBits += 1
            ans *= 2**numOfBits
            ans += i
            ans %= (1000000007)
            
        return ans