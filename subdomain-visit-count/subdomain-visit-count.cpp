class Solution {
public:
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> m;
        for(auto x : cpdomains) {
            string temp = "";
            int freq;
            for(auto c : x) {
                if(c == ' ')
                {
                    freq = stoi(temp);
                    temp = "";
                }
                else {
                    temp += c;
                }
            }
            
            string curr = "";
            for(int i = temp.length() - 1; i >= 0; i--) {
                if(temp[i] == '.') {
                    m[curr] += freq;
                    curr = temp[i] + curr;
                }
                else {
                    curr = temp[i] + curr;
                }
            }
            m[curr] += freq;
        }
        
        vector<string> ans;
        for(auto x : m)
            ans.push_back(to_string(x.second) + " " + x.first);
        
        return ans;
    }
};