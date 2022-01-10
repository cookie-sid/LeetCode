class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3)
            return {};
        unordered_map<int,int> m;
        vector<int> temp;
        for(auto x : nums) {
            if(m[x] == 0) {
                temp.push_back(x);
            }
            m[x]++;
        }
        sort(temp.begin(),temp.end());
        vector<vector<int>> ans;
        for(int i = 0; i < temp.size() - 2 and temp.size() > 2; i++) {
            for(int j = i + 1; j < temp.size() - 1; j++) {
                if(m[-(temp[i] + temp[j])] != 0 and -(temp[i] + temp[j]) > temp[j])
                    ans.push_back({temp[i],temp[j],-(temp[i] + temp[j])});
            }
        }
        for(auto x : temp)
        {
            if((x==0 and m[x]>2)  or (m[x] > 1 and m[-2*x] > 0 and x != 0))
                ans.push_back({x,x,-2*x});
        }
        return ans;
    }
};