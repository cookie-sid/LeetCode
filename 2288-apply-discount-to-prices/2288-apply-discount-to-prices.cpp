class Solution {
public:
    
    double applyD(long long v, long long d) {
        double ans = (double)(100 - d) * (v);
        ans /= 100;
        return ans;
    }
    
    bool checkValid(string s) {
        if(s[0] != '$')
            return false;
        
        if(s.length() == 1)
            return false;
        for(int i = 1; i < s.length(); i++) {
            if(s[i] - '0' < 0 or s[i] - '0' > 9) 
                return false;
        }
        return true;
    }
    
    double round(double var)
    {
        double value = (var * 100 + .5);
        return (double)value / 100;
    }
    
    string discountPrices(string s, int d) {
        string res = "";
        for(int i = 0; i < s.length(); i++) {
            int start = i;
            string curr = "";
            while(start < s.length() and s[start] != ' ') {
                curr += s[start];
                start++;
            }
            string add = curr;
            if(checkValid(curr)) {
                long long val = stoll(curr.substr(1));
                double tmp = round(applyD(val,d));
                string nS = "";
                nS += '$';
                nS += to_string(tmp);
                for(int j = 0; j < nS.length(); j++) {
                    if(nS[j] == '.') {
                        add = nS.substr(0,j + 3);
                        break;
                    }
                }
            }
            i = start;
            
            res += add;
            if(i != s.length())
                res += ' ';
        }
        return res;
    }
};