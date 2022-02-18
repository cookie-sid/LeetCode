class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> indices;
        for(int i = 0; i < nums.size(); i++) {
            indices.push_back(make_pair(nums[i],i));
        }
        sort(indices.begin(),indices.end());
        int mini, ans = 0;
        for(int i = 0; i < indices.size(); i++) {
            if(i == 0)
                mini = indices[i].second;
            else {
                mini = min(mini,indices[i].second);
            }
            ans = max(ans,indices[i].second - mini);
        }
        return ans;
    }
};