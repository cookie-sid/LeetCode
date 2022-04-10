class Solution:
    def threeSumMulti(self, arr: List[int], target: int) -> int:
        m = dict()
        for x in arr:
            if x in m:
                m[x] += 1
            else:
                m[x] = 1
        
        p = []
        for x in m.keys():
            p.append(x)
        p.sort()
        start,end = 0,len(p) - 1
        ans = 0
        pairs = {}
        mod = 1e9 + 7
        for start in range(len(p)):
            for end in range(len(p)):
                req = target - p[start] - p[end]
                if(req not in m):
                    continue
                else:
                    ls = [req,p[start],p[end]]
                    ls.sort()
                    if(tuple(ls) in pairs):
                        continue
                    else:
                        pairs[tuple(ls)] = 1
                    if(req == p[start] and req == p[end]):
                        ans += (m[req] * (m[req] - 1) * (m[req] - 2))/6
                        ans %= mod
                        continue
                    if(req == p[start]):
                        ans += (m[req]*(m[req] - 1)*m[p[end]])/2
                        ans %= mod
                        continue
                    if(req == p[end]):
                        ans += (m[req]*(m[req] - 1)*m[p[start]])/2
                        ans %= mod
                        continue
                    if(p[start] == p[end]):
                        ans += (m[p[start]]*(m[p[start]] - 1)*m[req])/2
                        ans %= mod
                        continue
                    ans += (m[req] * m[p[start]] * m[p[end]])
                    ans %= mod
            
        return int(ans)
            
        