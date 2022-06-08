class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        string res = "";
        int ctr = 0, start = 0;
        vector<pair<int,pair<string,string>>> v;
        for(int i = 0; i < indices.size(); i++) {
            v.push_back(make_pair(indices[i],make_pair(sources[i],targets[i])));
        }
        sort(v.begin(),v.end());
        int k = 0;
        for(auto x : v) {
            indices[k] = x.first;
            sources[k] = x.second.first;
            targets[k] = x.second.second;
            k++;
        }
        while(start < s.length() and ctr < indices.size()) {
            if(indices[ctr] > start) {
                res += s[start++];
            }
            else if(indices[ctr] == start) {
                if(s.substr(indices[ctr],sources[ctr].length()) == sources[ctr]) {
                    res += targets[ctr];
                    start += sources[ctr].length();
                }
                else {
                    res += s[start++];
                }
                ctr++;
            }
            else {
                ctr++;
            }
        }
        while(start < s.length()) {
            res += s[start++];
        }
        return res;
    }
};