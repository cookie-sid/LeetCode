class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        
        long long ans = 0;
        for(auto &x : nums) {
            if(x > 0)
                ans += x;
            else 
                x = abs(x);
        }
        sort(nums.begin(),nums.end());
        priority_queue<pair<long long, int>> pq;
        vector<long long> res;
        res.push_back(ans);
        pq.push({ans - nums[0],0});

        while(res.size() < k) {
            auto top = pq.top();
            pq.pop();
            if(top.second + 1 < nums.size()) {
                pq.push({top.first + nums[top.second] - nums[top.second + 1], top.second + 1});
                pq.push({top.first - nums[top.second + 1], top.second + 1});
            }
            res.push_back(top.first);
        }
        
        return res.back();
        
        
    }
};