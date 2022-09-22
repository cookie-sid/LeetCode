class Solution:
    def removeInterval(self, intervals: List[List[int]], toBeRemoved: List[int]) -> List[List[int]]:
        
        ans = []
        for i in intervals:
            start = i[0]
            end = i[1]
            if start >= toBeRemoved[1] or end <= toBeRemoved[0]:
                ans.append([start,end])
                continue
            if start >= toBeRemoved[0]:
                if end > toBeRemoved[1]:
                    ans.append([toBeRemoved[1],end])
            if start < toBeRemoved[0]:
                if end <= toBeRemoved[1]:
                    ans.append([start,toBeRemoved[0]])
                else:
                    ans.append([start,toBeRemoved[0]])
                    ans.append([toBeRemoved[1],end])
        return ans