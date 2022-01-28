class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int mini = 1e9, maxi = -1;
        for(auto x : nums) {
            mini = min(x,mini);
            maxi = max(x,maxi);
        }
        vector<int> count(maxi - mini + 1);
        for(auto x : nums) {
            count[x - mini]++;
        }
        int ans = 0, temp = 0; 
        for(int i = 0; i < maxi - mini + 1; i++) {
            if(count[i] == 0) {
                continue;
            }
            temp = max(temp,i);
            int diff = temp - i;
            int summation = (count[i] - 1) * (count[i])/2;
            summation += diff * (count[i]);
            ans += summation;
            temp += count[i];
        }
        return ans;
    }
};