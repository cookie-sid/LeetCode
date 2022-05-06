class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char,int>> st;
        for(char x : s) {
            if(st.empty() or st.top().first != x) {
                st.push({x,1});
            }
            else {
                st.top().second += 1;
                if(st.top().second == k) {
                    st.pop();
                }
            }
        }
        s = "";
        while(!st.empty()) {
            auto t = st.top();
            st.pop();
            for(int i = 0; i < t.second; i++) {
                s += t.first;
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
};