class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> temp;
        int maxi = -1;
        for(auto x : nums) {
            temp[x]++;
            maxi = max(maxi,temp[x]);
        }
        vector<vector<int>> bruh(maxi + 1);
        for(auto x : temp) {
            if(x.second != 0) {
                bruh[x.second].push_back(x.first);
            }
        }
        vector<int> ans;
        for(int i = maxi; i >= 0; i--) {
            if(bruh[i].size() != 0) {
                int start = 0;
                while(ans.size() != k and start < bruh[i].size()) {
                    ans.push_back(bruh[i][start]);
                    start++;
                }
            }
        }
        return ans;
    }
};