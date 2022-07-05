class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        while(total >= 0) {
            ans += 1;
            ans += total/cost2;
            total -= cost1;
        }
        return ans;
    }
};