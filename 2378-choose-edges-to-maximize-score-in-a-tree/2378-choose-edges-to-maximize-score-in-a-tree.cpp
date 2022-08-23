class Solution {
public:
    
    pair<long long, long long> dfs(int i, vector<vector<pair<int, int>>> &al) {
        long long  best_i = 0, without_i = 0;
        for (auto [j, w] : al[i]) {
            auto [with_j, without_j] = dfs(j, al);
            best_i = max(best_i, max(0, w) + without_j - with_j);
            without_i += max(with_j, without_j);
        }
        return {best_i + without_i, without_i};
    }
    
    long long maxScore(vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> al(edges.size());
        for (int i = 1; i < edges.size(); ++i)
            al[edges[i][0]].push_back({i, edges[i][1]});
        auto [with_0, without_0] = dfs(0, al);
        return max(with_0, without_0);
    }
    
};