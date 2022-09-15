class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        set<char> st;
        map<char,int> lastAt;
        int start = 0;
        int ans = 1;
        for(int i = 0; i < s.length(); i++) {
            char x = s[i];
            if(st.size() == 2 and st.count(x) != 1) {
                int mini = 1e9;
                char need = '/';
                for(auto c : st) {
                    if(mini > lastAt[c]) {
                        need = c;
                        mini = lastAt[c];
                    }
                }
                start = mini + 1;
                st.erase(need);
                st.insert(x);
            }
            else {
                st.insert(x);
            }
            ans = max(ans,i-start+1);
            lastAt[x] = i; 
        }
        return ans;
    }
};