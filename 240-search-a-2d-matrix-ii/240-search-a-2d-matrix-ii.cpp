class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] > target) {
                break;
            }
            int upper = upper_bound(matrix[i].begin(),matrix[i].end(),target) - matrix[i].begin();
            if(upper == 0) {
                continue;
            }
            if(target ==  matrix[i][upper - 1]) {
                return true;
            }
        }
        return false;
   }
};