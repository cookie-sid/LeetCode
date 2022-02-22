class Solution {
public:
    long long titleToNumber(string columnTitle) {
        long long ans = 0, mul = 1;
        for(int i = columnTitle.size() - 1; i >= 0; i--) {
            ans += mul * (columnTitle[i] - 'A' + 1);
            mul *= 26;
        }
        return ans;
    }
};