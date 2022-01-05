class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int start = 0, end = matrix.size() - 1;
        
        while(start < end) {
            
            for(int i = start; i < end; i++) {
                int temp = matrix[start][i];
                int temp2 = matrix[i][end];
                matrix[i][end] = temp;
                temp = temp2;
                temp2 = matrix[end][end - (i - start)];
                matrix[end][end - (i - start)] = temp;
                temp = temp2;
                temp2 = matrix[end - (i - start)][start];
                matrix[end - (i - start)][start] = temp;
                temp = temp2;
                matrix[start][i] = temp;
                
            }
            start++;
            end--;
        }
        
    }
};