import heapq

class Solution:
    def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
        mod = 1000000007
        speeds = []
        heapify(speeds)
        f = []
        for i in range(n):
            f.append([efficiency[i],speed[i]])
        f.sort(key = lambda x : [-x[0],-x[1]])
        ans = 0
        total = 0
        eff = 100000000000000
        for ele in f:
            if(len(speeds) + 1 <= k):
                heappush(speeds,[ele[1],ele[0]])
                total += ele[1]
                eff = min(eff,ele[0])
                ans = max(total * eff,ans)
            else:
                tmpEle = speeds[0]
                heappop(speeds)
                total -= tmpEle[0]
                total += ele[1]
                eff = ele[0]
                ans = max(total*eff,ans)
                heappush(speeds,[ele[1],ele[0]])
        
        ans %= mod
        
        return ans