class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> count(101);
        int sum = 0;
        for(auto x : nums) {
            count[x]++;
        }
        for(int i = 1; i < 101; i++) {
            sum += count[i] == 1 ? i : 0;
        }
        return sum;
    }
};