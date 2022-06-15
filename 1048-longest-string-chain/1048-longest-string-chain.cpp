class Solution {
public:
    
    bool check(string word1, string word2) {
        int start = 0;
        bool first = false;
        for(int i = 0; i < word2.length(); i++) {
            if(first and word2[i] != word1[start]) {
                return false;
            }
            if(word2[i] != word1[start]) {
                i--;
                first = true;
            }
            start++;
        }
        return true;
    }
    
    int getLongest(string word, unordered_map<string, int> &ans, vector<vector<string>> &words) {
        if(ans.find(word) != ans.end()) {
            return ans[word];
        }
        int len = word.length();
        if(len == 1) {
            ans[word] = 1;
            return ans[word];
        }
        ans[word] = 1;
        for(int i = 0; i < words[len - 1].size(); i++) {
            if(ans.find(words[len-1][i]) == ans.end()) {
                getLongest(words[len-1][i], ans, words);
            }
            if(!check(word,words[len-1][i])) {
                continue;
            }
            ans[word] = max(ans[word], 1 + ans[words[len-1][i]]);
        }
        return ans[word];
    }
    
    int longestStrChain(vector<string>& words) {
        vector<vector<string>> v(17);
        for(auto x : words) {
            v[x.length()].push_back(x);
        }
        unordered_map<string, int> ans;
        int res = 1;
        for(auto x : words) {
            res = max(res,getLongest(x,ans,v));
        }
        return res;
    }
};