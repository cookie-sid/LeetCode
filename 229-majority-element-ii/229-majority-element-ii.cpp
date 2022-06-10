class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;

        int mod = 1e9 + 7;
        int candidate1 = mod;
        int candidate2 = mod;

        for (int n: nums) {
            if (candidate1 != mod && candidate1 == n) {
                count1++;
            } else if (candidate2 != mod && candidate2 == n) {
                count2++;
            } else if (count1 == 0) {
                candidate1 = n;
                count1++;
            } else if (count2 == 0) {
                candidate2 = n;
                count2++;
            } else {
                count1--;
                count2--;
            }
        }

        vector<int> v;

        count1 = 0;
        count2 = 0;

        for (int n: nums) {
            if (candidate1 != mod && n == candidate1) count1++;
            if (candidate2 != mod && n == candidate2) count2++;
        }

        int n = nums.size();
        if (count1 > n/3) v.push_back(candidate1);
        if (count2 > n/3) v.push_back(candidate2);

        return v;
    }
};