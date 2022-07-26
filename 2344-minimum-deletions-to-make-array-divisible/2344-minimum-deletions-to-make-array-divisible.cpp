class Solution {
public:
    
    int gcd(int a, int b) {
        if(a % b == 0) {
            return b;
        }
        return gcd(b,a%b);
    }
    
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        
        int hcf = numsDivide[0], n = nums.size();
        for(int i = 1; i < numsDivide.size(); i++) {
           hcf = gcd(hcf,numsDivide[i]); 
        }
        
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++) {
            if(hcf % nums[i] == 0) {
                return i;
            }
        }
        
        return -1;
    }
};