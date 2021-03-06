class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        deque<int> dq;
        for(int i = 0; i < k; i++) {
            while(!dq.empty() and nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        
        for(int i = k; i < nums.size(); i++) {
            if(dq.front() < i - k + 1) {
                dq.pop_front();
            }
            while(!dq.empty() and nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }
        return ans;
        
    }
};