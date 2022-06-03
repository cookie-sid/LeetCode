class NumMatrix {
public:
    
    vector<vector<int>> m;
    
    int getSum(int r, int c) {
        if(r < 0 or c < 0 or r >= m.size() or c >= m[0].size())
            return 0;
        return m[r][c];
    }
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        m = matrix;
        int r = matrix.size(), c = matrix[0].size();
        
        for(int i = 0; i < r; i++) {
            for(int j = 1; j < c; j++) {
                m[i][j] += m[i][j-1];
            }
        }
        
        for(int j = 0; j < c; j++) {
            for(int i = 1; i < r; i++) {
                m[i][j] += m[i-1][j];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2,col2) - getSum(row1-1,col2) - getSum(row2,col1 - 1) + getSum(row1-1,col1-1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */