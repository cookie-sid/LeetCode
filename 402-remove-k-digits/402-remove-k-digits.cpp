class Solution {
public:
    
    string removeNonZero(string s, int k) {
        if(k == s.length())
            return "";
        
        stack<char> st;
        st.push(s[0]);
        for(int i = 1; i < s.length(); i++) {
            if(st.top() > s[i] and k > 0) {
                while(!st.empty() and st.top() > s[i] and k > 0) {
                    st.pop();
                    k--;
                }
                st.push(s[i]);
            }
            else {
                st.push(s[i]);
            }
        }
        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        if(k != 0)
            return res.substr(0,res.length() - k);
        return res;
    }
    
    string removeKdigits(string num, int k) {
        
        int totalzeros = 0;
        for(auto x : num) {
            if(x == '0') {
                totalzeros++;
            }
        }
        if(num.length() - totalzeros <= k)
            return "0";
        
        
        if(totalzeros != 0) {
            int currnonzero = 0;
            for(int i = 0; i < num.length(); i++) {
                if(num[i] != '0') {
                    currnonzero++;
                }
                else {
                    if(k > currnonzero) {
                        k -= currnonzero;
                        currnonzero = 0;
                    }
                    else {
                        string curr = removeNonZero(num.substr(i - currnonzero,currnonzero), k);
                        if(curr != "") {
                            curr += num.substr(i);
                        }
                        else {
                            int f = i;
                            while(f < num.length() and num[f] == '0')
                                f++;
                            curr += num.substr(f);
                        }
                        return curr;
                    }
                }
            }
            string curr = removeNonZero(num.substr(num.length() - currnonzero,currnonzero),k);
            return curr;
        }
        return removeNonZero(num,k);
        
        
    }
};