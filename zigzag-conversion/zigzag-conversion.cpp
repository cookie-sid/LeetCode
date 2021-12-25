class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> ans(numRows);
        int temp = 0;
        if(numRows == 1)
            return s;
        bool flipped = false;
        for(int i = 0; i < s.length(); i++) {
            if(temp == numRows)
            {
                temp = numRows - 2;
                flipped = true;
            }
            if(temp == -1)
            {
                temp += 2;
                flipped = false;
            }
            ans[temp].push_back(s[i]);
            if(flipped)
                temp--;
            else
                temp++;
        }
        string res = "";
        for(auto x : ans) {
            for(auto y : x)
                res += y;
        }
        return res;
    }
};