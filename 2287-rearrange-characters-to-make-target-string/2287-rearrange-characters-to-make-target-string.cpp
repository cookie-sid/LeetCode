class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> ct(26);
        for(auto x : s)
            ct[x - 'a']++;
        
        vector<int> r(26);
        for(auto x : target)
            r[x - 'a']++;
        
        int mini = 1e9;
        for(int i= 0; i < 26; i++) {
            if(r[i] != 0)
                mini = min(mini,ct[i]/r[i]);
        }
        return mini;
    }
};