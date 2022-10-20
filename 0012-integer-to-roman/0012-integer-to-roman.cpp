class Solution {
public:
    string intToRoman(int num) {
        map<int,string> m;
        m[1] = "I";
        m[5] = "V";
        m[10] = "X";
        m[50] = "L";
        m[100] = "C";
        m[500] = "D";
        m[1000] = "M";
        string ans = "";
        int val = 1;
        while(num > 0) {
            int p = num % 10;
            num /= 10;
            int toForm = p * val;
            if(p < 4) {
                for(int i= 0; i < p; i++) {
                    ans = m[val] + ans;
                }
            }
            else {
                if(p == 4) {
                    ans = m[val] + m[5*val] + ans;
                }
                else if(p == 5) {
                    ans = m[5*val] + ans;
                }
                else if(p == 9) {
                    ans = m[val] + m[10*val] + ans;
                }
                else {
                    string tmp = m[5*val];
                    for(int i = 0; i < p-5; i++) {
                        tmp += m[val];
                    }
                    ans = tmp + ans;
                }
            }
            val *= 10;
        }
        return ans;
        
    }
};