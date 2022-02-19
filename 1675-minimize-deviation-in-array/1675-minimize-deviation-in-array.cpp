class Solution {
public:
    
    int minimumDeviation(vector<int>& nums) {
        
        priority_queue<int> evens;
        int mini = INT_MAX;
        for(auto x : nums) {
            if(x % 2 == 0) {
                evens.push(x);
                mini = min(mini,x);
            }
            else {
                evens.push(x * 2);
                mini = min(mini,x * 2);
            }
        }
        
        int ans = INT_MAX;
        while(!evens.empty()) {
            int currValue = evens.top();
            evens.pop();
            ans = min(ans,currValue - mini);
            if(currValue % 2 == 0) {
                evens.push(currValue / 2);
                mini = min(mini,currValue/2);
            }
            else
                break;
        }
        return ans;
    }
};