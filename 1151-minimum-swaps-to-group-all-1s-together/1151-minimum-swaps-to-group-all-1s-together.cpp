class Solution {
public:
    int minSwaps(vector<int>& data) {
        int totalOnes = 0;
        for(auto x : data) {
            if(x == 0)
                continue;
            totalOnes += 1;
        }
        
        int ans = 1e9;
        int zerosInThisWindow = 0;
        for(int i = 0; i < totalOnes; i++) {
            if(data[i] == 0) {
                zerosInThisWindow += 1;
            }
        }
        
        ans = min(ans,zerosInThisWindow);
        for(int i = 1; i < data.size() - totalOnes + 1; i++) {
            if(data[i-1] == 0) {
                zerosInThisWindow -= 1;
            }
            if(data[i-1+totalOnes] == 0) {
                zerosInThisWindow += 1;
            }
            ans = min(ans,zerosInThisWindow);
        }
        return ans;
        
    }
};