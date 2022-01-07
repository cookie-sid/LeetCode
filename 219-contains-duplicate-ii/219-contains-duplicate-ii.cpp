class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> last;
        int p = 0;
        for(auto x : nums) {
            p++;
            if(last[x] == 0) {
                last[x] = p;
            }
            else {
                if(p - last[x] <= k) {
                    return true;
                }
                else {
                    last[x] = p;
                }
            }
        }
        return false;
    }
};