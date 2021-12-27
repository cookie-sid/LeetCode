class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        unordered_map<int,set<pair<int,int>>> m;
        unordered_map<int,int> count;
        for(auto x : nums) {
            count[x]++;
        }
        set<vector<int>> s;
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                m[nums[i] + nums[j]].insert(make_pair(nums[i],nums[j]));
                for(auto x : m[target-nums[i]-nums[j]]) {
                    vector<int> v = {nums[i],nums[j],x.first,x.second};
                    sort(v.begin(),v.end());
                    unordered_map<int,int> temp_count;
                    for(auto x : v) {
                        temp_count[x]++;
                    }
                    bool poss = true;
                    for(auto x : temp_count) {
                        if(count[x.first] < x.second) {
                            poss = false;
                            break;
                        }
                    }
                    if(poss) {
                        s.insert(v);
                    }
                }
            }
        }
        vector<vector<int>> ans;
        
        for(auto x : s) {
            ans.push_back(x);
        }
        
        return ans;
    }
};