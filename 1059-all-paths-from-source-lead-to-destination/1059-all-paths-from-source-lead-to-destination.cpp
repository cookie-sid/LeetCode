class Solution {
public:
    
    bool canReach(vector<vector<int>> &graph, vector<bool> &vis, int source, int dest) {
        if(source == dest) {
            return true;
        }
        
        bool ans = false;
        vis[source] = true;
        for(int i = 0; i < graph[source].size(); i++) {
            if(vis[graph[source][i]]) {
                return false;
            }
            if(i == 0) {
                ans = canReach(graph,vis,graph[source][i],dest);
            }
            else {
                if(!ans) {
                    return ans;
                }
                else {
                    ans = ans and canReach(graph,vis,graph[source][i],dest);
                }
            }
            vis[graph[source][i]] = false;
        }
        vis[source] = false;
        
        return ans;
    }
    
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n+1);
        vector<bool> vis(n+1);
        for(int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        if(graph[destination].size() != 0) {
            return false;
        }
        return canReach(graph,vis,source,destination);
    }
};