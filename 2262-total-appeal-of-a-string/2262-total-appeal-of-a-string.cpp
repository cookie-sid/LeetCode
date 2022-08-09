class Solution {
public:
    long long appealSum(string s) {
        vector<long long> ans(s.length());
        vector<int> v(26,-1);
        ans[0] = 1;
        v[s[0] - 'a'] = 0;
        long long res = 1;
        for(int i = 1; i < s.length(); i++) {
            if(v[s[i] - 'a'] != -1) {
                ans[i] = ans[i - 1] + (i - v[s[i] - 'a']);
            }
            else {
                ans[i] = ans[i - 1] + i + 1;
            }
            v[s[i] - 'a'] = i;
            res += ans[i];
        }
        return res;
    }
};


// a b b c a
// 1 3 4 8 12 