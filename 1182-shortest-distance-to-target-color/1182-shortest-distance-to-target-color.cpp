class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> colorIndices(n, vector<int> (4,1e9));
        vector<int> lastSeenAt(4,-1e9);
        for(int i = 0; i < colors.size(); i++) {
            lastSeenAt[colors[i]] = i;
            for(int j = 1; j < colorIndices[i].size(); j++) {
                colorIndices[i][j] = min(i - lastSeenAt[j],colorIndices[i][j]);
            }
        }
        lastSeenAt[1] = 1e9;
        lastSeenAt[2] = 1e9;
        lastSeenAt[3] = 1e9;
        for(int i = n - 1; i >= 0; i--) {
            lastSeenAt[colors[i]] = i;
            for(int j = 1; j < colorIndices[i].size(); j++) {
                colorIndices[i][j] = min(lastSeenAt[j] - i,colorIndices[i][j]);
            }
        }
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            ans.push_back(colorIndices[queries[i][0]][queries[i][1]] > 1e5 ? -1 : colorIndices[queries[i][0]][queries[i][1]]);
            
        }
        return ans;
            
    }
};