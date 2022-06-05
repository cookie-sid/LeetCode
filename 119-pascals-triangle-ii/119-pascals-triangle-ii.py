class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [0]*(rowIndex + 1)
        last = 0
        for i in range(0,rowIndex + 1):
            if i == 0:
                ans[0] = 1
                last = 0
            elif i == 1:
                ans[0] = 1
                ans[1] = 1
                last = 1
            else:
                x = last
                ans[x + 1] = 1
                while(x > 0):
                    ans[x] = ans[x - 1] + ans[x]
                    x -= 1
                
                last += 1
                    
        
        return ans
        