class Solution {
public:
    
    void dfs(vector<vector<int>>& graph, int curr, int n, vector<bool>& vis) {
        if(vis[curr]) {
            return;
        }
        vis[curr] = true;
        for(int i = 0; i < graph[curr].size(); i++) {
            if(vis[graph[curr][i]])
                continue;
            dfs(graph,graph[curr][i],n,vis);
            vis[graph[curr][i]] = true;
        }
    }
    
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sort(logs.begin(),logs.end());
        vector<vector<int>> graph(n + 1);
        for(int i = 0; i < logs.size(); i++) {
            graph[logs[i][1]].push_back(logs[i][2]);
            graph[logs[i][2]].push_back(logs[i][1]);
            vector<bool> vis(n);
            dfs(graph,0,n,vis);
            bool allvis = true;
            for(int j = 0; j < n; j++) {
                if(!vis[j]) {
                    allvis = false;
                    break;
                }
            }
            if(allvis)
                return logs[i][0];
        }
        
        return -1;
    }
};