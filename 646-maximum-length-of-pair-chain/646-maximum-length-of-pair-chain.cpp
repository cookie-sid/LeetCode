class Solution {
public:
    
    int findLongestChain(vector<vector<int>>& pairs) {
        for(int i = 0; i < pairs.size(); i++)
        {
            int temp = pairs[i][0];
            pairs[i][0] = pairs[i][1];
            pairs[i][1] = temp;
        }
        
        sort(pairs.begin(),pairs.end());
        int count = 0;
        for(int i = 0; i < pairs.size(); i++)
        {
            count++;
            int start = i + 1;
            while(start < pairs.size() and pairs[start][1] <= pairs[i][0] )
            {
                start++;
            }
            i = start - 1;
        }
        return count;
    }
};