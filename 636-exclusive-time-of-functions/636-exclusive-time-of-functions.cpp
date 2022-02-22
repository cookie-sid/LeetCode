class Solution {
public:
    
    vector<string> getTokens(string &s) {
        
        vector<string> ans;
        int start = 0;
        int end = s.find(":");
        while (end != -1) {
            ans.push_back(s.substr(start, end - start));
            start = end + 1;
            end = s.find(":", start);
        }
        ans.push_back(s.substr(start, end - start));
        return ans;
        
    }
    
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        
        stack<pair<int,int>> st;
        map<int,int> m;
        vector<int> ans(n,0);
        
        for(auto x : logs) {
            
            vector<string> tmp = getTokens(x);
            if(tmp[1] == "start") {
                st.push(make_pair(stoi(tmp[0]),stoi(tmp[2])));
            }
            else {
                
                int id = st.top().first, starttime = st.top().second;
                int currenttime = stoi(tmp[2]) - starttime + 1;
                ans[stoi(tmp[0])] += currenttime;
                st.pop();
                
                if(!st.empty()){
                    ans[st.top().first] -= currenttime;
                }
                
            }
        }
        return ans;
    }
};