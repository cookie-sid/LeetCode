class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> v(100);
        
        v[1] = 1;
        v[0] = 1;
        
        for(int i = 2; i <= n; i++) {
            v[i] = v[i-1] + v[i-2];
        }
        return v[n];
        
    }
};