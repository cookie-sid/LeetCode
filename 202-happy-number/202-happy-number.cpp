class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        st.insert(n);
        while(n != 1) {
            string s = to_string(n);
            int ans = 0;
            for(auto x : s) { 
                ans += (x - '0') * (x - '0');
            }
            if(st.count(ans) == 1 and ans != 1) {
                return false;
            }
            st.insert(ans);
            n = ans;
        }
        return true;
    }
};