class Solution {
public:
    
    bool hasAllCodes(string s, int k) {
        unordered_map<string,bool> m;
        int counts = 0;
        for(int i = 0; i < (int)s.length() - k + 1 and counts < pow(2,k); i++) {
            if(!m[s.substr(i,k)]) {
                m[s.substr(i,k)] = true;
                counts++;
            }
        }
        return counts == pow(2,k);
    }
};