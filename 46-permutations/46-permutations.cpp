class Solution {
public:
    
    void recur(vector<vector<int>> &permutations, vector<int> &nums, int n, vector<bool> &bl, vector<int> &curr) {
        
        if(n == nums.size()) {
            permutations.push_back(curr);
            return;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(bl[i] == true)
                continue;
            bl[i] = true;
            curr.push_back(nums[i]);
            recur(permutations,nums,n+1,bl,curr);
            curr.pop_back();
            bl[i] = false;
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> curr;
        vector<vector<int>> permutations;
        vector<bool> bl(nums.size());
        for(int i = 0; i < nums.size(); i++) {
            bl[i] = false;
        }
        
        recur(permutations,nums,0,bl,curr);
        return permutations;
    }
};