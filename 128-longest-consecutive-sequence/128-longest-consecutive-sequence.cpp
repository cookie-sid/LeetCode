class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;
        for(auto x: nums) {
            m.insert(x);
        }
        
        int ans = 0;
        for(auto x : nums) {
            if(!m.count(x - 1)) {
                int currNum = x;
                int currLen = 1;
                while(m.count(currNum + 1)) {
                    currNum += 1;
                    currLen += 1;
                }
                ans = max(currLen, ans);
            }
        }
        return ans;
    }
};