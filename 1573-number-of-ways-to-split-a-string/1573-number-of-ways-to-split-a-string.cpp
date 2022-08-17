class Solution {
public:
    
    int calculate(int n, int mod) {
        long long ans = 1;
        ans = ans * n * (n-1);
        ans /= 2;
        return ans % mod;
    }
    
    int numWays(string s) {
        // 1 is present ->
        //      num of ones is div by 3 ->
        //          get first and last indices where num of ones = (num of ones/3)
        //          check how many zeros b/w them, no of ways = product(p + 1)
        //      num of ones not div by 3 ->
        //          0 ways
        // 1 is not present ->
        //      basically place 2 lines between spaces, ways = n - 1 C 2
        
        int ones = 0, mod = 1e9 + 7;
        for(int i = 0; i < s.length(); i++) {
            ones += s[i] - '0';
        }
        if(ones == 0) {
            return calculate(s.length() - 1,mod);
        }
        if(ones % 3 != 0) {
            return 0;
        }
        ones /= 3;
        int curr = 0, ct = 0, first = -1, second = -1;
        for(int i = 0; i < s.length(); i++) {
            curr += s[i] - '0';
            if(curr == ones and s[i] == '0') {
                ct++;
            }
            if(curr > ones) {
                curr = 1;
                if(first == -1)
                    first = ct;
                else if(second == -1)
                    second = ct;
                ct = 0;
            }
        }
        return ((long long)(first + 1) * (second + 1))%mod;
    }
};