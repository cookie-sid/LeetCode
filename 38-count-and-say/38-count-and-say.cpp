class Solution {
public:
    
    string funct(int curr, int n, string s) {
        if(curr == n) {
            return s;
        }
        string res = "";
        for(int i = 0; i < s.length(); i++) {
            
            int temp = i;
            int count = 1;
            while(temp + 1 < s.length() and s[temp + 1] == s[temp]) {
                count++;
                temp++;
            }
            res += to_string(count) + s[i];
            i = temp;
        }
        return funct(curr+1,n,res);
    }
    
    string countAndSay(int n) {
        return funct(1,n,"1");
    }
};