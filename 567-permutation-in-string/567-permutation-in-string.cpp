class Solution {
public:
    
    bool check(vector<int> one) {
        for(int i = 0; i < one.size(); i++) {
            if(one[i] != 0)
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        vector<int> pattern(26,0);
        for(auto x : s1) {
            pattern[x - 'a']++;
        }
        for(int i = 0; i < s2.length() - s1.length() + 1; i++) {
            if(i == 0) {
                for(int j = 0; j < s1.length(); j++) {
                    pattern[s2[j] - 'a']--;
                }
                if(check(pattern))
                    return true;
            }
            else {
                pattern[s2[i + s1.length() - 1] - 'a']--;
                pattern[s2[i-1] - 'a']++;
                if(check(pattern))
                    return true;
            }
        }
        
        return false;
    }
};