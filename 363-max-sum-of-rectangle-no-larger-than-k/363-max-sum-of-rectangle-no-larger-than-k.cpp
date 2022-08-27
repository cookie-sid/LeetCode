class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int maxi = -1e9;
        for(int i = 0; i < n; i++) {
            for(int j = -1; j < i; j++) {
                int currSum = 0;
                set<int> s;
                
                int maxiSum = -1e9;
                for(int l = 0; l < m; l++) {
                    int sub = 0;
                    if(j != -1) {
                        sub = matrix[l][j];
                    }
                    currSum = max(currSum + matrix[l][i] - sub, matrix[l][i] - sub);
                    maxiSum = max(maxiSum,currSum);
                }
                if(maxiSum <= k) {
                    maxi = max(maxiSum,maxi);
                    continue;
                }
                else {
                    s.clear();
                    currSum = 0;
                }
                
                for(int l = 0; l < m; l++) {
                    int sub = 0;
                    if(j != -1) {
                        sub = matrix[l][j];
                    }
                    currSum += (matrix[l][i] - sub);
                    if(currSum <= k)
                        maxi = max(currSum,maxi);
                    if(s.size() == 0) {
                        s.insert(currSum);
                    }
                    else {
                        int exact = currSum - k;
                        auto itr = s.lower_bound(exact);
                        if(itr != s.end()) {
                            maxi = max(maxi,currSum - *itr);
                        }
                        s.insert(currSum);
                    }
                }
                
            }
        }
        return maxi;
    } 
};