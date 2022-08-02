class Solution {
public:
    
    int getNums(vector<vector<int>> &matrix, int target) {
        int n = matrix.size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            int upper = upper_bound(matrix[i].begin(),matrix[i].end(),target) - matrix[i].begin();
            if(upper == 0) {
                break;
            }
            count += upper;
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), target = k;
        int low = matrix[0][0], high = matrix[n-1][n-1];
        while(low <= high) {
            int mid = (low + high)/2;
            int numsLessThanOrEqualToMid = getNums(matrix,mid);
            if(numsLessThanOrEqualToMid < target) {
                low = mid + 1;
            }
            else {
                if(getNums(matrix,mid-1) < target) {
                    return mid;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};