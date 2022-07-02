class Solution {
public:
    int numWays(int n, int k) {
        int twoSame = 0, oneSame = 0;
        if(n == 1) {
            return k;
        }
        if(n == 2) {
            return k * k;
        }
        twoSame = k;
        oneSame = k*k - k;
        for(int i = 3; i <= n; i++) {
            int prevTwoSame = twoSame, prevOneSame = oneSame;
            twoSame = prevOneSame;
            oneSame = (prevTwoSame * (k - 1)) + (prevOneSame * k) - twoSame; 
        }
        return oneSame + twoSame;
    }
};