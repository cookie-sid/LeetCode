class Solution {
public:
    
    string removeDuplicateLetters(string s) {
        
        vector<int> lastIndex(26);
        for(int i = 0; i < s.length(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }
        
        stack<char> st;
        vector<bool> pres(26);
        for(int i = 0; i < s.length(); i++) {
            while(st.size() and st.top() > s[i] and lastIndex[st.top() - 'a'] > i and !pres[s[i] - 'a']) {
                pres[st.top() - 'a'] = false;
                st.pop();
            }
            if(!pres[s[i] - 'a']) {
                st.push(s[i]);
                pres[s[i] - 'a'] = true;
            }
        }
        
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
        
    }
};