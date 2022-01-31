class Solution {
public:
    
    int characterReplacement(string s, int k) {
        
        vector<int> count(26,0);
        int start = 0, ans = 0, total = 0, maxCountInWindow = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i == 0) {
                count[s[i] - 'A']++;
                maxCountInWindow = max(maxCountInWindow, count[s[i] - 'A']);
                total++;
                ans = max(ans,i - start + 1);
                continue;
            }
            count[s[i] - 'A']++;
            maxCountInWindow = max(maxCountInWindow, count[s[i] - 'A']);
            total++;
            if(total - maxCountInWindow > k) {
                count[s[start] - 'A']--;
                start++;
                total--;
            }
            ans = max(ans,i - start + 1);
        }
        return ans;
    }
    
};