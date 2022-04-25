class Solution {
public:
    
    void recurr(string s, set<string> &v, int i) {
        if(i == s.length()) {
            return;
        }
        string u = s.substr(0,i) + (char)(toupper(s[i])) + s.substr(i + 1);
        string l = s.substr(0,i) + (char)(tolower(s[i])) + s.substr(i + 1);
        v.insert(u);
        v.insert(l);
        recurr(u,v,i+1);
        recurr(l,v,i+1);
    }
    
    vector<string> letterCasePermutation(string s) {
        
        set<string> t;
        recurr(s,t,0);
        vector<string> ans;
        for(auto x : t) {
            ans.push_back(x);
        }
        return ans;
    }
};