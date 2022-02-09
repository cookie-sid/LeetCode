class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> m;
        int count = 0;
        for(auto x : nums) {
            if(k == 0) {
                if(m[x] == 1) {
                    count++;
                }
            }
            else {
                if(m[x] == 0){
                    if(m[x - k] != 0) 
                        count++;
                    if(m[x + k] != 0)
                        count++;
                }
            }
            m[x]++;
        }
        return count;
    }
};