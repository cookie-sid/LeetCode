class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        sort(nums3.begin(),nums3.end());
        sort(nums4.begin(),nums4.end());
        map<int,int> count3,count4;
        for(auto x : nums4) {
            count4[x]++;
        }
        for(auto x : nums3) {
            count3[x]++;
        }
        map<int,int> comb;
        for(auto x : count3) {
            for(auto y : count4) {
                comb[x.first + y.first] += x.second * y.second;
            }
        }
        
        int n = nums1.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            int first = nums1[i];
            int count_f = 1;
            while(i < n - 1 and nums1[i + 1] == first) {
                count_f++;
                i++;
            }
            for(int j = 0; j < n; j++) {
                int second = nums2[j];
                int count_s = 1;
                while(j < n - 1 and nums2[j + 1] == second) {
                    count_s++;
                    j++;
                }
                ans += comb[0 - first - second] * count_f * count_s;
                
            }
        }
        return ans;
        
    }
};