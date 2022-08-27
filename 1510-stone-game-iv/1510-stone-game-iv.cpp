class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> ans(n+1);
        ans[0] = 2;
        ans[1] = 1;
        for(int i = 2; i <= n; i++) {
            int p = 1;
            while(p*p <= i) {
                if(ans[i - p*p] == 2) {
                    ans[i] = 1;
                    break;
                }
                p += 1;
            }
            if(ans[i] == 0) {
                ans[i] = 2;
            }
        }
        return ans[n] == 1;
    }
};