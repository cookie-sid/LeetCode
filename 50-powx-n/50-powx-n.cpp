class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        long long g = n;
        n < 0 ? g = -g: g = g;
        while(g) {
            if(g & 1) {
                res *= x;
            }
            x *= x;
            g /= 2;
        }
        
        return n < 0 ? (double)1/res : res;
    }
};