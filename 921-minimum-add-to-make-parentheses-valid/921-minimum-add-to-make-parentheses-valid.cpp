class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        for(auto x : s) {
            if(x == ')') {
                if(st.empty())
                    st.push(x);
                else {
                    if(st.top() == '(')
                        st.pop();
                    else
                        st.push(')');
                }
            }
            else {
                st.push('(');
            }
        }
        return st.size();
    }
};