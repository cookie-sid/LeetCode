class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = strs[0];
        for(int i = 1; i < strs.size(); i++)
        {
            int same = 0;
            for(int j = 0; j < strs[i].size(); j++) {
                if(strs[i][j] == lcp[j]) {
                    same++;
                }
                else {
                    break;
                }
            }
            lcp = lcp.substr(0,same);
        }
        return lcp;
    }
};