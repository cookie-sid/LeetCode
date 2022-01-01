class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int starti = matrix.size(), startj = matrix[0].size();
        int beg = 0;
        vector<int> ans;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = i; j < startj; j++) {
                ans.push_back(matrix[i][j]);
                if((int)ans.size() == (int)matrix.size()*(int)matrix[0].size())
                    return ans;
            }
            for(int j = i + 1; j < starti; j++) {
                ans.push_back(matrix[j][startj - 1]);
                if((int)ans.size() == (int)matrix.size()*(int)matrix[0].size())
                    return ans;
            }
            for(int j = startj - 2; j >= i; j--) {
                ans.push_back(matrix[starti-1][j]);
                if((int)ans.size() == (int)matrix.size()*(int)matrix[0].size())
                    return ans;
            }
            for(int j = starti-2; j > i; j--) {
                ans.push_back(matrix[j][i]);
                if((int)ans.size() == (int)matrix.size()*(int)matrix[0].size())
                    return ans;
            }
            starti--;
            startj--;
        }
        
        return ans;
    }
};