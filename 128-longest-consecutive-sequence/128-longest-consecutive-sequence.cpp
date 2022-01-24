class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        for (auto &n: nums) {
            us.insert(n);
        }
        
        int result = 0;
        for (auto it=us.begin(); it != us.end(); it++) {
            int k = *it;
            int r = 1;
            while (us.find(++k) != us.end()) {
                r++;
                us.erase(k);
            }
            k = *it;
            while (us.find(--k) != us.end()) {
                r++;
                us.erase(k);
            }
            
            result = max(result, r);
        }
        
        return result;
    }
};