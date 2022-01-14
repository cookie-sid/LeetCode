class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int target) {
        map<int,int> m1, m2;
        
        for(int i = 0; i < nums.size(); i++) {
            
            if(i == 0) {
                m1[nums[i]]++;
                m1[-nums[i]]++;
            }
            else {
                for(auto x : m1) {
                    m2[x.first + nums[i]] += m1[x.first];
                    m2[x.first - nums[i]] += m1[x.first];
                }
                m1 = m2;
                // for(auto x : m1) {
                //     cout<<x.first<<" "<<x.second<<endl;
                // }
                // cout<<endl;
                m2.clear();
            }
            
        }
        return m1[target];
        
    }
};