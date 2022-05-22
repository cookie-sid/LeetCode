class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length(), ans = 0;
        for(int i = 0; i < n; i++) {
            ans++;
            int left = i - 1, right = i + 1;
            while(left >= 0 and right < n) {
                if(s[left] == s[right]) {
                    left--;
                    right++;
                    ans++;
                }
                else {
                    break;
                }
            }
            left = i - 1;
            right = i;
            while(left >= 0 and right < n) {
                if(s[left] == s[right]) {
                    left--;
                    right++;
                    ans++;
                }
                else {
                    break;
                }
            }
        }
        return ans;
    }
};