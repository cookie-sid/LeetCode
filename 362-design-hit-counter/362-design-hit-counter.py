class HitCounter:
    
    def __init__(self):
        self.d = {}
        pass
        

    def hit(self, timestamp: int) -> None:
        self.d[timestamp] = self.d[timestamp] + 1 if timestamp in self.d else 1

    def getHits(self, timestamp: int) -> int:
        ans = 0
        for ts in range(timestamp,timestamp-300,-1):
            if ts in self.d:
                ans += self.d[ts]
        return ans


# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)