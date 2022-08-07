class Solution {
public:
    int countVowelPermutation(int n) {
        vector<int> v(5,1);
        int prev = 0, mod = 1e9 + 7;
        for(int i = 2; i <= n; i++) {
            vector<int> tmp(5,0);
            tmp[0] += ((v[2]%mod + v[1]%mod)%mod + v[4]%mod)%mod;
            tmp[0] %= mod;
            tmp[1] += (v[2]%mod + v[0]%mod)%mod;
            tmp[1] %= mod;
            tmp[2] += (v[1]%mod + v[3]%mod)%mod;
            tmp[2] %= mod;
            tmp[3] += v[2]%mod;
            tmp[3] %=mod;
            tmp[4] += (v[3]%mod + v[2]%mod)%mod;
            tmp[4] %= mod;
            v = tmp;
        }
        int ans = 0;
        for(auto x : v) {
            ans += x%mod;
            ans %= mod;
        }
        return ans;
    }
};