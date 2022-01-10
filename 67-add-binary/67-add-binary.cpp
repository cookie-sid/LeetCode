class Solution {
public:
    string addBinary(string a, string b) {
        while(a.length() < b.length()) {
            a = "0" + a;
        }
        
        while(b.length() < a.length()) {
            b = "0" + b;
        }
    
        int carry = 0;
        string res = "";
        for(int i = a.length() - 1; i >= 0; i--) {
            int fora = a[i] - '0', forb = b[i] - '0';
            if(fora + forb == 1) {
                if(carry) {
                    res = "0" + res;
                }
                else {
                    res = "1" + res;
                }
            }
            else if(fora + forb ==  0) {
                if(carry) {
                    res = "1" + res;
                    carry = 0;
                }
                else {
                    res = "0" + res;
                }
            }
            else if(fora + forb == 2) {
                if(carry) {
                    res = "1" + res;
                }
                else {
                    res = "0" + res;
                    carry = 1;
                }
            }
        }
        if(carry) {
            res = "1" + res;
        }
        return res;
        
    }
};