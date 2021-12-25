class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        int max_pos = 2147483647;
        int max_neg = -2147483648;
        
        int new_int = 0;
        bool neg = false;
        if(s[0] == '-')
            neg = true;
        for(int i = s.length() - 1; neg ? i > 1 : i > 0; i--) {
            if(neg) {
                new_int = new_int * 10;
                new_int -= s[i] - '0';
            }
            else {
                new_int = new_int * 10;
                new_int += s[i] - '0';
            }
        }
        
        if(neg) {
            if(new_int > max_neg/10)
                return new_int * 10 - (s[1] - '0');
            else if(new_int == max_neg/10 and s[1] - '0' <= 8)
                return new_int * 10 - (s[1] - '0');
        }
        else {
            if(new_int < max_pos/10)
                return new_int * 10 + (s[0] - '0');
            else if(new_int == max_pos/10 and s[0] - '0' <= 7)
                return new_int * 10 + (s[0] - '0');
        }
        
        return 0;
    }
};