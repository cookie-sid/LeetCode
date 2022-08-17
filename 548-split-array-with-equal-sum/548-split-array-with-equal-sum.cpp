class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        map<int,set<int>> m;
        int t = nums[0];
        m[t].insert(0);
        for(int i = 1; i < n; i++) {
            t += nums[i];
            m[t].insert(i);
        }
        bool found = false;
        int currSum = nums[0];
        for(int i = 1; i < n - 4; i++) {
            int f = currSum;
            int tot = 0;
            for(int j = n - 1; j > 4; j--) {
                tot += nums[j];
                if(tot == currSum) {
                    cout<<currSum<<" "<<i<<" ";
                    auto ind = m[nums[i] + 2 * (f)].upper_bound(i);
                    while(ind != m[nums[i] + 2 * (f)].end()) {
                        if(ind != m[nums[i] + 2 * (f)].end() and (*ind) + 1 < j - 2 and m[nums[i] + nums[*ind + 1] + 3 * f + nums[j-1]].count(j-1) == 1) {
                            return true;
                        }
                        ind++;
                    }
                    cout<<tot<<" "<<j - 1<<endl;
                    
                }
            }
            currSum += nums[i];
        }
        return false;
    }
};