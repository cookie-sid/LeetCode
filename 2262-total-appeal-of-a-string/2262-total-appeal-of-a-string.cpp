class Solution {
public:
    long long appealSum(string s) {
        
        vector<int> v(26,-1);
        v[s[0] - 'a'] = 0;
        long long res = 1, prev = 1;
        for(int i = 1; i < s.length(); i++) {
            if(v[s[i] - 'a'] != -1) {
                res += prev + (i - v[s[i] - 'a']);
                prev += (i - v[s[i] - 'a']);
            }
            else {
                res += prev + i + 1;
                prev += i + 1;
            }
            v[s[i] - 'a'] = i;
        }
        return res;
    }
};


// a b b c a
// 1 3 4 8 12 