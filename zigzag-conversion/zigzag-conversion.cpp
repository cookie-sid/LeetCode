class Solution {
public:
    string convert(string s, int numRows) {
        
        if(numRows == 1)
            return s;
        
        string ans = s;
        int temp = 0;
        for(int i = 0; i < numRows; i++) {
            if(i == 0) {
                for(int j = 0; j < s.length(); j+=numRows + numRows - 2) {
                    ans[temp++] = s[j];
                }
                continue;
            }
            else if(i == numRows - 1) {
                for(int j = numRows - 1; j < s.length(); j+=numRows + numRows - 2) {
                    ans[temp++] = s[j];
                }
                continue;
            }
            bool flipped = false;
            for(int j = i; j < s.length(); j++) {
                if(!flipped) {
                    ans[temp++] = s[j];
                    j += 2*(numRows - 1 - i);
                    j--;
                }
                else {
                    ans[temp++] = s[j];
                    j += 2*i;
                    j--;
                }
                flipped = !flipped;
            }
        }
        return ans;
    }
};