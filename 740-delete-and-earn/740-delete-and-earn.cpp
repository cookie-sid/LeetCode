class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int> count(10001);
        for(auto x : nums) {
            count[x]++;
        }
        
        int notUsedLast = 0, usedLast = 0;
        usedLast = count[1];
        for(int i = 2; i < 10001; i++) {
            
            
            if(count[i] == 0) {
                int temp = max(notUsedLast, usedLast);
                usedLast = temp;
                notUsedLast = temp;
                continue;
            }
            
            int currUsed = notUsedLast + count[i]*i;
            int currNotUsed = max(usedLast,notUsedLast);
            
            usedLast = currUsed;
            notUsedLast = currNotUsed;
        }
        
        return max(usedLast, notUsedLast);
        
    }
};