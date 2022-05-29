class Solution {
public:
    
    int recurr(int a, vector<vector<int>> &preForThis, 
               vector<bool> &recStack, map<int,int> &m) {
        if(m[a] != 0)
            return m[a];
        if(preForThis[a].size() == 0) {
            m[a] = 1;
            return 1;
        }
        if(recStack[a]) {
            m[a] = -1e9;
            return m[a];
        }
        int ans = -1;
        recStack[a] = true;
        for(auto x : preForThis[a]) {
            ans = max(ans, 1 + recurr(x,preForThis,recStack,m));
        }
        m[a] = ans;
        return ans;
    }
    
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> preForThis(n+1);
        for(auto x : relations) {
            preForThis[x[1]].push_back(x[0]);
        }
        map<int,int> m;
        vector<bool> taken(n + 1), recStack(n + 1);
        for(int i = 1; i <= n; i++) {
            recurr(i,preForThis,recStack,m);
            
        }
        int ans = -1;
        for(auto x : m) {
            if(x.second < 0)
                return -1;
            ans = max(ans,x.second);
        }
        
        return ans;
    }
};