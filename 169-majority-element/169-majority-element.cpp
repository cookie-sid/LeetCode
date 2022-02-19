class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0, curr;
        for(auto num : nums) {
            if(count == 0)
                curr = num;
            
            count += num == curr ? 1 : -1;
        }
        return curr;
        
    }
};