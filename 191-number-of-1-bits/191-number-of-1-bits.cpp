class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0) {
            return 0;
        }
        int count = hammingWeight(n/2) + n%2;
        return count;
    }
};