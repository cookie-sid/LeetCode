class Solution {
public:
    
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        for(int i = 0; i < nums.size(); i++) {
            int ct = 0;
            vector<int> v;
            for(int j = i; j < nums.size(); j++) {
                if(nums[j] % p == 0) {
                    ct++;
                }
                v.push_back(nums[j]);
                if(ct <= k) {
                    s.insert(v);
                }
                else {
                    break;
                }
            }
        }
        return s.size();
    }
};