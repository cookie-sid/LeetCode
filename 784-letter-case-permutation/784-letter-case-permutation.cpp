class Solution {
public:
    
    void recurr(string s, map<string,bool> &m, int i) {
        if(i == s.length()) {
            return;
        }
        string u = s.substr(0,i) + (char)(toupper(s[i])) + s.substr(i + 1);
        string l = s.substr(0,i) + (char)(tolower(s[i])) + s.substr(i + 1);
        m[u] = true;
        m[l] = true;
        recurr(u,m,i+1);
        recurr(l,m,i+1);
    }
    
    vector<string> letterCasePermutation(string s) {
        
        map<string,bool> t;
        recurr(s,t,0);
        vector<string> ans;
        for(auto x : t) {
            ans.push_back(x.first);
        }
        return ans;
    }
};