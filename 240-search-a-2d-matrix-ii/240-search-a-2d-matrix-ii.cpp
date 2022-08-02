class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while(x >= 0 and y >= 0 and x < m and y < n) {
            if(matrix[x][y] > target) {
                y--;
            }
            else if(matrix[x][y] < target) {
                x++;
            }
            else {
                return true;
            }
        }
        return false;
    }
};