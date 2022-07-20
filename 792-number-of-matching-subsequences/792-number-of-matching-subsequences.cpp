class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> indices(26);
        for(int i = 0; i < s.length(); i++) {
            indices[s[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for(int i = 0; i < words.size(); i++) {
            int prev = -1;
            bool pos = true;
            for(int j = 0; j < words[i].length(); j++) {
                if(prev == -1) {
                    if(indices[words[i][j] - 'a'].size() == 0) {
                        pos = false;
                        break;
                    }
                    prev = indices[words[i][j] - 'a'][0];
                }
                else {
                    if(indices[words[i][j] - 'a'].size() == 0) {
                        pos = false;
                        break;
                    }
                    int upper = upper_bound(indices[words[i][j] - 'a'].begin(),indices[words[i][j] - 'a'].end(),prev) - indices[words[i][j] - 'a'].begin();
                    if(upper == indices[words[i][j] - 'a'].size()) {
                        pos = false;
                        break;
                    }
                    prev = indices[words[i][j] - 'a'][upper];
                }
            }
            ans += pos ? 1 : 0;
        }
        return ans;
    }
};