class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int end = piles.size() - 1, ans = 0;
        for(int i = 1; i < piles.size() and i < end; i += 2) {
            ans += piles[i];
            end--;
        }
        return ans;
    }
};