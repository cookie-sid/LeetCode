class Solution {
    
public:
    
    int recur(vector<int> &stones, int total, int curr, int n, map<pair<int,int>,int> &m) {
        if(m.find(make_pair(total,curr)) != m.end())
            return m[make_pair(total,curr)];
        if(curr == n) {
            m[make_pair(total,curr)] = total < 0 ? 1e9 : total;
            return total < 0 ? 1e9 : total;
        }
        int ans = 1e9;
        ans = min(recur(stones,total + stones[curr],curr + 1,n,m),ans);
        ans = min(recur(stones,total - stones[curr],curr + 1,n,m),ans);
        m[make_pair(total,curr)] = ans;
        return ans;
    }
    
    int lastStoneWeightII(vector<int>& stones) {
        int total = 0, n = stones.size();
        map<pair<int,int>,int> m;
        return recur(stones,total,0,n,m);
    }
};