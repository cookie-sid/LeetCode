class Solution {
public:
    
    static bool cmp(string &a, string &b) {
        return a.length() > b.length();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        string ans = "";
        unordered_map<string,bool> m;
        for(int i = 0; i < words.size(); i++) {
            if(i == 0) {
                for(int j = 0; j < words[i].length(); j++) {
                    m[words[i].substr(j)] = true;
                }
                ans += words[i] + "#";
            }
            else {
                if(!m[words[i]]) {
                    for(int j = 0; j < words[i].length(); j++) {
                        m[words[i].substr(j)] = true;
                    }
                    ans += words[i] + "#";
                }
            }
        }
        return ans.length();
    }
};