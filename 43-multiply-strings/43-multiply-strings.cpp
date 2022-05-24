class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0")
            return "0";
        vector<int> ans(100001);
        int n = num2.length(), start = 100000;
        int last = 1e5;
        for(int j = n - 1; j >= 0; j--) {
            int tempstart = start;
            for(int i = num1.length() - 1; i >= 0; i--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                ans[tempstart] += mul%10;
                ans[tempstart - 1] += mul/10;
                tempstart--;
                last = min(last,tempstart);
            }
            start--;
        }
        for(int i = 100000; i >= 1; i--) {
            ans[i-1] += ans[i]/10;
            ans[i] = ans[i]%10;
        }
        int gotill = -1;
        while(gotill + 1 < 100001 and ans[gotill + 1] == 0) {
            gotill++;
        }
        string s = "";
        for(int i = 100000; i > gotill; i--) {
            s += '0' + ans[i];
        }
        reverse(s.begin(),s.end());
        return s;
    }
};