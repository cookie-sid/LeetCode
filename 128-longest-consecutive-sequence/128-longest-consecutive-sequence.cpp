class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> m;
        for(auto x: nums) {
            m[x] = true;
        }
        
        int ans = 0;
        for(auto x : nums) {
            if(!m[x - 1]) {
                int currNum = x;
                int currLen = 1;
                while(m[currNum + 1]) {
                    currNum += 1;
                    currLen += 1;
                }
                ans = max(currLen, ans);
            }
        }
        return ans;
    }
};