class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> count(26);
        for(int i = 0; i < t.length(); i++) {
            if(i == t.length() - 1) {
                count[t[i] - 'a']++;
            }
            else {
                count[t[i] - 'a']++;
                count[s[i] - 'a']--;
            }
        }
        for(int i = 0; i < 26; i++) {
            if(count[i] == 1) {
                return 'a' + i;
            }
        }
        return 'a';
    }
};