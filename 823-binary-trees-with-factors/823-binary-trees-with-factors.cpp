class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long long mod = 1e9 + 7;
        map<long long,long long> m;
        m[arr[0]] = 1;
        for(int i = 1; i < arr.size(); i++) {
            set<long long> s;
            long long ans = 1;
            ans %= mod;
            for(int j = 0; j < i; j++) {
                if(arr[i] % arr[j] == 0) {
                    s.insert(arr[j]);
                }
            }
            for(auto x : s) {
                if(arr[i]/x == x) {
                    ans += (m[x]%mod * m[x]%mod)%mod;
                    ans %= mod;
                }
                else {
                    if(s.count(arr[i]/x) == 1) {
                        ans += (m[x]%mod * m[arr[i]/x]%mod)%mod;
                    }
                }
                ans %= mod;
            }
            m[arr[i]] = ans;
        }
        long long res = 0;
        for(auto x : m) {
            res += x.second;
            res %= mod;
        }
        return res;
    }
};