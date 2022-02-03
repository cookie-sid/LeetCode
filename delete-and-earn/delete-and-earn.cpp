class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int> freq(10001);
        for(auto x : nums) {
            freq[x]++;
        }
        
        int avoid = 0, use = 0, prev = -1;
        for(int i = 1; i < 10001; i++) {
            if(freq[i] != 0) {
                int m = max(avoid,use);
                if(i - 1 != prev) {
                    use = i * freq[i] + m;
                    avoid = m;
                }
                else {
                    use = i * freq[i] + avoid;
                    avoid = m;
                }
                prev = i;
            }
        }
        return max(avoid,use);
        
    }
};