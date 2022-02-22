class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        for(int i=columnTitle.size()-1,x=0;i>=0;i--,x++)
        {
            ans+=((columnTitle[i]-'A' + 1)*pow(26,x));
        }
        return ans;
        
    }
};