#define ll long long
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<ll> sumUpTo(k+1,1);
        ll mod = 1e9 + 7;
        for(int i = 2; i <= n; i++) {
            vector<ll> temp(i*k + 1,0);
            for(int j = 1; j < (int)sumUpTo.size(); j++) {
                for(int l = 1; l <= k; l++) {
                    temp[l+j] += sumUpTo[j];
                    temp[l+j] %= mod;
                }
            }
            sumUpTo = temp;
            // for(auto x : sumUpTo) {
            //     cout<<x<<" ";
            // }
            // cout<<endl;
        }
        if(target > sumUpTo.size() - 1) {
            return 0;
        }
        return sumUpTo[target];
    }
};