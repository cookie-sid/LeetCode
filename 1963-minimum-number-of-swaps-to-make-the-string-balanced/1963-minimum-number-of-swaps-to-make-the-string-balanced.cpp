class Solution {
public:
    int minSwaps(string s) {
        
        int start = 0 , end = s.length() - 1;
        int swaps = 0;
        stack<char> st;
        while(start < end) {
            if(st.empty()) {
                if(s[start] == '[') {
                    st.push(s[start]);
                    start++;
                }
                else {
                    while(end > start and s[end] == ']') {
                        end--;
                    }
                    swaps++;
                    char c = s[start];
                    s[start] = s[end];
                    s[end] = s[start];
                    st.push(s[start]);
                    start++;
                }
            }
            else {
                s[start] == '[' ? st.push('[') : st.pop();
                start++;
            }
        }
        return swaps;
    }
};