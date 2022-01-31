class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> q;
        int start = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                q.push(i+1);
            }
            else {
                ans = max(i - start + 1,ans);
            }
            
            if(q.size() > k ) {
                start = q.front();
                q.pop();
            }
            
            ans = max(i - start + 1,ans);
            
        }
        return ans;
    }
};