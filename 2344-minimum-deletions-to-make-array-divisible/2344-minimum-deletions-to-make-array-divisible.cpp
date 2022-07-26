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
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        
        while(!pq.empty() and hcf % pq.top() != 0) {
            pq.pop();
        }
        
        int del = pq.size();
        return n - del == n ? -1 : n - del; 
    }
};