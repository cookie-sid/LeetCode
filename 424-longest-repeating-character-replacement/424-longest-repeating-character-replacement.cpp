class Solution {
public:
    
    bool check(map<char,int> &m, int k, int total) {
        for(auto x : m) {
            if(total - x.second <= k) {
                return true;
            }
        }
        return false;
    }
    
    int characterReplacement(string s, int k) {
        
        map<char,int> m;
        int start = 0, ans = 0, total = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i == 0) {
                m[s[i]]++;
                ans = max(ans,i - start + 1);
                total++;
                continue;
            }
            m[s[i]]++;
            total++;
            while(start < i and !check(m,k,total)) {
                m[s[start]]--;
                start++;
                total--;
            }
            ans = max(ans,i - start + 1);
        }
        return ans;
    }
    
};