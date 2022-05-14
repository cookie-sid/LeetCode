class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>> pq;
        vector<bool> vis(n + 1);
        vector<vector<pair<int,int>>> graph(n+1);
        map<pair<int,int>,int> m;
        for(auto x : times) {
            graph[x[0]].push_back(make_pair(x[1],x[2]));
        }
        
        pq.push(make_pair(0,k));
        vector<int> ans(n + 1, 1e9);
        ans[k] = 0;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            if(vis[top.second])
                continue;
            vis[top.second] = true;
            for(auto x : graph[top.second]) {
                int node = x.first, time = x.second;
                if(ans[node] > ans[top.second] + time) {
                    ans[node] = ans[top.second] + time;
                    pq.push(make_pair(-ans[node],node));
                }
            }
        }
        
        int maxi = -1;
        for(int i = 1; i <= n; i++) {
            maxi = max(maxi,ans[i]);
        }
        if(maxi == 1e9) {
            return -1;
        }
        return maxi;
        
    }
};