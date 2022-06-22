class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        deque<pair<int,int>> dq;
        for(int i = 0; i < k; i++) {
            while(!dq.empty() and dq.back().first < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(make_pair(nums[i],i));
        }
        ans.push_back(dq.front().first);
        
        for(int i = k; i < nums.size(); i++) {
            if(dq.front().second < i - k + 1) {
                dq.pop_front();
            }
            while(!dq.empty() and dq.back().first < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(make_pair(nums[i],i));
            ans.push_back(dq.front().first);
        }
        return ans;
        
    }
};