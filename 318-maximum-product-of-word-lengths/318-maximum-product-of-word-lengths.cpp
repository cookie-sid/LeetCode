class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<vector<bool>> present(n, vector<bool> (26));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < words[i].length(); j++) {
                present[i][words[i][j] - 'a'] = true;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                bool noCommon = true;
                for(int k = 0; k < 26; k++) {
                    if(present[i][k] and present[j][k]) {
                        noCommon = false;
                        break;
                    }
                }
                if(noCommon)
                    ans = max(ans, (int)words[i].length() * (int)words[j].length());
            }
        }
        return ans;
        
    }
};