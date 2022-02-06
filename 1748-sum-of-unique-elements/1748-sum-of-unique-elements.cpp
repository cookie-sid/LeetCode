class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> count(101);
        int sum = 0;
        for(auto x : nums) {
            count[x]++;
            if(count[x] == 1) {
                sum += x;
            }
            else if (count[x] == 2){
                sum -= x;
            }
        }

        return sum;
    }
};