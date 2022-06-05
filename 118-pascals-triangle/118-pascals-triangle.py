class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = []
        temp = []
        for i in range(1,numRows + 1):
            temp = []
            if i == 1:
                temp.append(1)
            elif i == 2:
                temp.append(1)
                temp.append(1)
            else:
                temp.append(1)
                for i in range(0,len(ans[-1]) - 1):
                    temp.append(ans[-1][i] + ans[-1][i+1])
                temp.append(1)
            
            ans.append(temp)
            
        return ans 