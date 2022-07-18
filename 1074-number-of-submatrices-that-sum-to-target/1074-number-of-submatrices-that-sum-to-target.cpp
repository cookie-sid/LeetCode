class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(); 
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        
        
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < i; j++) {
                map<int,int> mp;
                mp[0] = 1;
                int sum = 0;
                for(int k = 0; k < n; k++) {
                    sum += matrix[k][i] - matrix[k][j];
                    if(mp[sum - target]) {
                        ans += mp[sum - target];
                    }
                    mp[sum] += 1;
                }
            }
            map<int,int> mp;
            mp[0] = 1;
            int sum = 0;
            for(int k = 0; k < n; k++) {
                sum += matrix[k][i];
                if(mp[sum - target]) {
                    ans += mp[sum - target];
                }
                mp[sum] += 1;
            }
            
        }
        
        return ans;
        
    }
};