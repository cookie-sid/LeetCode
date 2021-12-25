class Solution {
public:
    string longestPalindrome(string s) {
        
        //begin from largest possible substring
        //check if first and last elements are same for that size substring
        //if they are same move forward, if not break the loop
        
        string ans = "";
        int len = -1;
        for(int i = s.length(); i > 0; i--) {
            int start = 0, end = s.length() - i;
            for(int j = start; j <= end; j++) {
                int beg = j, ends = j + i - 1;
                while(beg < ends and s[beg] == s[ends]) {
                    beg++;
                    ends--;
                }
                if(beg == ends or beg > ends)
                    return s.substr(j,i);
            }
        }
        return to_string(s[0]);
        
    }
};