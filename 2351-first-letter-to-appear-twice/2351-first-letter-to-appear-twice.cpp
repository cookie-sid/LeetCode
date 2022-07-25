class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> ct(26);
        for(auto x : s) {
            if(ct[x - 'a'] == 1) {
                return x;
            }
            ct[x - 'a']++;
        }
        return 'a';
    }
};