class Solution {
public:
    
    bool checkUnique(vector<int> &chars) {
        for(auto x : chars) {
            if(x > 1)
                return false;
        }
        return true;
    }
    
    int numKLenSubstrNoRepeats(string s, int k) {
        
        vector<int> chars(26);
        int ans = 0;
        for(int i = 0; i < s.length() - k + 1; i++) {
            if(i == 0) {
                for(int j = 0; j < k; j++) {
                    chars[s[j] - 'a']++;
                }
                if(checkUnique(chars)) {
                    ans++;
                }
            }
            else {
                chars[s[i - 1] - 'a']--;
                chars[s[i + k - 1] - 'a']++;
                if(checkUnique(chars)) {
                    ans++;
                }
            }
        }
        return ans;
        
    }
};