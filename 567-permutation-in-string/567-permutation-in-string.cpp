class Solution {
public:
    
    bool cmp(vector<int> &temp1, vector<int> &temp2) {
        for(int i = 0; i < temp1.size(); i++) {
            if(temp1[i] != temp2[i]) {
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> freqOne(26,0), freqCalc(26,0);
        for(auto x : s1) {
            freqOne[x - 'a']++;
        }
        for(int i = 0; i < s1.length(); i++) {
            freqCalc[s2[i] - 'a']++;
        }
        if(cmp(freqOne,freqCalc)) {
            return true;
        }
        for(int i = s1.length(); i < s2.length(); i++) {
            freqCalc[s2[i] - 'a']++;
            freqCalc[s2[i-s1.length()] - 'a']--;
            if(cmp(freqOne,freqCalc)) {
                return true;
            }
        }
        return false;
    }
};