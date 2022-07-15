class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        vector<vector<int>> colorIndices(4);
        for(int i = 0; i < colors.size(); i++) {
            colorIndices[colors[i]].push_back(i);
        }
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            int index = queries[i][0];
            int reqColor = queries[i][1];
            int upper = upper_bound(colorIndices[reqColor].begin(),colorIndices[reqColor].end(),index) - colorIndices[reqColor].begin();
            int currAns = 1e9;
            if(colorIndices[reqColor].size() == 0) {
                ans.push_back(-1);
                continue;
            }
            if(colors[index] == reqColor) {
                ans.push_back(0);
                continue;
            }
            if(upper != 0) {
                currAns = min(index - colorIndices[reqColor][upper-1],currAns);
            }
            if(upper != (int)colorIndices[reqColor].size()) {
                currAns = min(colorIndices[reqColor][upper] - index,currAns);
            }
            ans.push_back(currAns);
        }
        return ans;
    }
};