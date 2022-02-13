class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(' or s[i] == ')') {
                if(s[i] == ')') {
                    if(st.empty()) {
                        st.push(i);
                    }
                    else {
                        if(s[st.top()] == '(')
                            st.pop();
                        else
                            st.push(i);
                    }
                }
                else {
                    st.push(i);
                }
            }
        }
        
        
        while(!st.empty()) {
            s[st.top()] = 'A';
            st.pop();
        }
        
        string res = "";
        for(auto x : s) {
            if(x != 'A')
                res += x;
        }
        
        return res;
        
    }
};