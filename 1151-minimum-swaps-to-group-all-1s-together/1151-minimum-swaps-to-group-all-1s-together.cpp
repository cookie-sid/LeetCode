class Solution {
public:
    int minSwaps(vector<int>& data) {
        int n = data.size();
        int totalones = 0;
        for(int i = 0; i < n; i++) {
            if(data[i] == 1)
                totalones++;
        }
        
        int ans = 1e9, countzeros = 0;
        for(int i = 0; i < totalones; i++) {
            if(data[i] == 0)
                countzeros++;
        }
        ans = min(ans,countzeros);
        for(int i = 1; i <= n - totalones; i++) {
            if(data[i + totalones - 1] == 0)
                countzeros++;
            if(data[i - 1] == 0)
                countzeros--;
            
            ans = min(ans,countzeros);
        }
        return ans;
    }
};