class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> sum(1002);
        
        for(auto x: trips) {
            sum[x[1]] += x[0];
            sum[x[2]] -= x[0];
        }
        
        if(sum[0] > capacity)
            return false;
        
        for(int i = 1; i < 1001; i++) {
            sum[i] += sum[i-1];
            if(sum[i] > capacity)
                return false;
        }
        
        return true;
        
    }
};