class Solution {
public:
    
    string getnew(string s) {
        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] > s[i+1]) {
                string temp1 = s.substr(0,i), temp2 = s.substr(i+1);
                return temp1 + temp2;
            }
        }
        string temp = s.substr(0,s.length() - 1);
        return temp;
    }
    
    string removeKdigits(string num, int k) {
        int nonzeros = 0;
        for(auto x : num) {
            if(x - '0' > 0)
                nonzeros++;
        }
        if(nonzeros <= k)
            return "0";
        
        if(nonzeros == num.length()) {
            for(int i = 0; i < k; i++) {
                num = getnew(num);
            }
            return num;
        }
        
        int countconsec = 0;
        string pres = num;
        for(int i = 0; i < num.length() && k != 0; i++) {
            if(num[i] != '0')
                countconsec++;
            else {
                if(countconsec == 0)
                    continue;
                if(countconsec < k) {
                    pres = num.substr(i);
                    k -= countconsec;
                    countconsec = 0;
                }
                else if(countconsec > k) {
                    string temp = num.substr(i - countconsec,countconsec);
                    for(int i = 0; i < k; i++)
                    {
                        temp = getnew(temp);
                    }
                    pres = num.substr(i);
                    pres = temp + pres;
                    k = 0;
                }
                else {
                    pres = num.substr(i);
                    k = 0;
                }
            }
            
            if(i == num.length() - 1 and k != 0) {
                if(countconsec == 0)
                    continue;
                if(countconsec < k) {
                    pres = num.substr(i);
                    k -= countconsec;
                    countconsec = 0;
                }
                else if(countconsec > k) {
                    string temp = num.substr(i - countconsec,countconsec);
                    for(int i = 0; i < k; i++)
                    {
                        temp = getnew(temp);
                    }
                    pres = num.substr(i);
                    pres = temp + pres;
                    k = 0;
                }
                else {
                    pres = num.substr(i);
                    k = 0;
                }
            }
            
        }
        
        int start = 0;
        while(start < pres.length() and pres[start] == '0') {
            start++;
        }
        
        pres = pres.substr(start);
        return pres;
    }
};