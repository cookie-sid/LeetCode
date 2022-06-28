class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        long long sum = 0;
        int maxi = -1;
        for(auto x : damage) {
            sum += x;
            maxi = max(maxi,x);
        }
        return sum - min(maxi,armor) + 1;
    }
};