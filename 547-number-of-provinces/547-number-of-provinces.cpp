class Solution {
public:
    void dfs(int i, vector<vector<int>> &g, vector<bool> &vis) {
        vis[i] = true;
        for(auto x : g[i]) {
            if(!vis[x]) {
                dfs(x, g, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> g(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j)
                    continue;
                if(isConnected[i][j] == 1) {
                    g[i].push_back(j);
                }
            }
        }
        vector<bool> vis(n);
        int count = 0;
        while(true) {
            bool trav = false;
            for(int i = 0; i < n; i++) {
                if(!vis[i]) {
                    dfs(i,g,vis);
                    trav = true;
                    break;
                }
            }
            if(trav)
                count++;
            else 
                break;
        }
        return count;
        
    }
    
    
};