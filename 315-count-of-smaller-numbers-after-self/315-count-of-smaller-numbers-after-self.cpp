class Solution {
public:
    
    
    void merger(vector<pair<int,int>> &nums, int start, int end, vector<int> &ans) {
        if(start == end) {
            return;
        }
        int mid = (start + end)/2;
        merger(nums,start,mid,ans);
        merger(nums,mid + 1,end,ans);
        merge(nums,start,mid,end,ans);
    }
    
    void merge(vector<pair<int,int>> &nums, int start, int mid, int end, vector<int> &ans) {
        int len = end - start + 1;
        vector<pair<int,int>> tmp(len);
        int s = 0;
        int lstart = start, rstart = mid + 1;
        while(lstart < mid + 1 and rstart < end + 1) {
            if(nums[lstart].first > nums[rstart].first) {
                tmp[s++] = nums[lstart];
                ans[nums[lstart++].second] += end - rstart + 1;
            }
            else {
                tmp[s++] = nums[rstart++];
            }
        }
        while(lstart < mid + 1) {
            tmp[s++] = nums[lstart++];
        }
        while(rstart < end + 1) {
            tmp[s++] = nums[rstart++];
        }
        s = 0;
        for(int i = start; i < end + 1; i++) {
            nums[i] = tmp[s++];
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size());
        vector<pair<int,int>> tmp;
        for(int i = 0; i < nums.size(); i++) {
            tmp.push_back(make_pair(nums[i],i));
        }
        int n = nums.size();
        merger(tmp,0,n-1,ans);
        return ans;
    }
};