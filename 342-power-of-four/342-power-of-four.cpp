class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 and ((n) & (n - 1)) == 0 and (n % 3 == 1);
    }
};