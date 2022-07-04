class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n);
        candies[0] = 1;
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i-1]) {
                while(i < n and ratings[i] > ratings[i-1]) {
                    candies[i] = candies[i-1] + 1;
                    i++;
                }
                i--;
            }
            else {
                candies[i] = 1;
            }
        }
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) {
                while(i >= 0 and ratings[i] > ratings[i+1]) {
                    candies[i] = max(candies[i],candies[i+1] + 1);
                    i--;
                }
                i++;
            }
        }
        int ans = 0;
        for(auto x : candies) {
            ans += x;
        }
        return ans;
    }
};