class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x : nums) {
            m[x]++;
        }
        int ans = 0;
        for(auto x : nums) {
            if(m.find(x+1) != m.end()) {
                continue;
            }
            else {
                int len = 0;
                while(m.find(x)!= m.end()) {
                    x--;
                    len++;
                }
                ans = max(ans,len);
            }
        }
        return ans;
    }
};