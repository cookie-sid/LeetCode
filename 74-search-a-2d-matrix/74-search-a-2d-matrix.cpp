class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        vector<int> temp;
        for(int i = 0; i < matrix.size(); i++) {
            temp.push_back(matrix[i][0]);
        }
        int actual = upper_bound(temp.begin(), temp.end(), target) - temp.begin();
        if(actual == 0) {
            return false;
        }
        actual -= 1;
        int found = lower_bound(matrix[actual].begin(),matrix[actual].end(),target) - matrix[actual].begin();
        if(found == matrix[0].size()) {
            return false;
        }
        if(matrix[actual][found] == target) {
            return true;
        }
        return false;
        
    }
};