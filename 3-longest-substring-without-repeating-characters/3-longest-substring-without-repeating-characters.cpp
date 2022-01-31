class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        multiset<char> st;
        int ans = 0, start = 0;
        for(int i = 0; i < s.length(); i++) {
            if(i == 0) {
                st.insert(s[i]);
                ans = max(ans,(int)st.size());
                continue;
            }
            if(st.count(s[i]) == 0) {
                st.insert(s[i]);
                ans = max(ans,(int)st.size());
            }
            else {
                while(start < i and st.count(s[i]) != 0) {
                    st.erase(s[start]);
                    start++;
                }
                st.insert(s[i]);
                ans = max(ans,(int)st.size());
            }
        }
        return ans;
    }
};