class Solution {
public:
    
    int getSetBits(int n) {
        int ans = 0;
        while(n > 0) {
            if(n & 1) {
                ans++;
            }
            n/=2;
        }
        return ans;
    }
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        long long ans = 0;
        vector<int> ct(31);
        set<int> nms;
        for(auto x : nums) {
            nms.insert(x);
        }
        for(auto x : nms) {
            int currBits = getSetBits(x);
            ct[currBits]++;
        }
        
        for(int i = 0; i < 31; i++) {
            for(int j = i; j < 31; j++) {
                if(ct[i] == 0  or ct[j] == 0)
                    continue;
                if(i == j) {
                    if(2 * i >= k) {
                        ans += (long long)ct[i]*ct[i];
                    }
                    continue;
                }
                if(i + j >= k) {
                    ans += (long long)(ct[i]) * ct[j] * 2;
                }
            }
        }
        return ans;
        
    }
};