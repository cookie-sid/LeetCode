class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        //O(n) time and O(1) space, given that the arrays are already sorted
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        
        vector<int> ans;
        
        int start_1 = 0, start_2 = 0;
        
        while(start_1 < nums1.size() and start_2 < nums2.size()) {
            while(start_1 < nums1.size() and nums1[start_1] < nums2[start_2]) {
                start_1++;
            }
            if(start_1 == nums1.size()) {
                break;
            }
            if(nums1[start_1] == nums2[start_2]) {
                ans.push_back(nums1[start_1]);
                while(start_1 < nums1.size() and start_2 < nums2.size() and nums1[start_1] == nums2[start_2]) {
                    if(ans.back() != nums1[start_1]) {
                        ans.push_back(nums1[start_1]);
                    }
                    start_1++;
                    start_2++;
                }
            }
            else {
                while(start_2 < nums2.size() and nums2[start_2] < nums1[start_1]) {
                    start_2++;
                }
                if(start_2 == nums2.size()) {
                    break;
                }
                if(nums1[start_1] == nums2[start_2]) {
                    ans.push_back(nums1[start_1]);
                    while(start_1 < nums1.size() and start_2 < nums2.size() and nums1[start_1] == nums2[start_2]) {
                        if(ans.back() != nums1[start_1]) {
                            ans.push_back(nums1[start_1]);
                        }
                        start_1++;
                        start_2++;
                    }
                }
            }
        }
        
        return ans;
        
    }
};