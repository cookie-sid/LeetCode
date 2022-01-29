class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string,vector<string>> m;
        for(auto s : strings) {
            if(s.size() == 1) {
                m["once"].push_back(s);
            }
            else {
                string tmp = "";
                for(int i = 1; i < s.length(); i++) {
                    tmp += to_string(((s[i] - '0') - (s[i-1] - '0') + 26)%26);
                    tmp += '-';
                }
                m[tmp].push_back(s);
            }
        }
        vector<vector<string>> ans;
        for(auto x : m) {
            ans.push_back(x.second);
        }
        return ans;
    }
};