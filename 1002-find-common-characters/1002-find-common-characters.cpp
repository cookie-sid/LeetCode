class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> count(26);
        vector<string> ans;
        int n = words.size();
        bool first = true;
        for(auto x : words) {
            vector<int> temp(26);
            for(auto c : x) {
                temp[c - 'a']++;
            }
            for(int i = 0; i < 26; i++) {
                count[i] = first ? temp[i] : min(count[i],temp[i]);
            }
            first = false;
        }
        for(int i = 0; i < 26; i++) {
            if(count[i] == 0)
                continue;
            for(int j = 0; j < count[i]; j++) {
                string s = "";
                s += ('a' + i);
                ans.push_back(s);
            }
        }
        return ans;
    }
};