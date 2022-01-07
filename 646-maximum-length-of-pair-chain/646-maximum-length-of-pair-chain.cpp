class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(),pairs.end());
        vector<int> count(pairs.size());
        
        count[pairs.size() - 1] = 1;
        int maxi = 1;
        for(int i = pairs.size() - 2; i >= 0; i--) {
            cout<<pairs[i][0]<<" "<<pairs[i][1]<<endl;
            int start = i;
            while(start < pairs.size()) {
                if(pairs[start][0] > pairs[i][1]) {
                    count[i] = max(count[i],count[start] + 1);
                    maxi = max(maxi,count[i]);
                }
                start++;
            }
            if(count[i] == 0) {
                count[i] = 1;
            }
        }
        return maxi;
        
    }
};