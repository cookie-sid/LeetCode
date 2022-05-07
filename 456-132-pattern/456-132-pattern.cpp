class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) {
            return false;
        }
        stack<int> s;
        vector<int> minTillNow(n);
        minTillNow[0] = nums[0];
        for(int i = 1; i < n; i++) {
            minTillNow[i] = min(minTillNow[i-1],nums[i]);
        }
        for(int i = n - 1; i > 0; i--) {
            
            if(nums[i] == minTillNow[i]) {
                continue;
            }
            
            while(!s.empty() and minTillNow[i] >= s.top()) {
                s.pop();
            }
            
            if(!s.empty() and s.top() < nums[i] and minTillNow[i] < s.top()) {
                return true;
            }
            
            s.push(nums[i]);
        }
        
        return false;
    }
};