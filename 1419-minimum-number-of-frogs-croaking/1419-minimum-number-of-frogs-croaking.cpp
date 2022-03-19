class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        
        unordered_map<char,vector<int>> m;
        for(int i = 0; i < croakOfFrogs.length(); i++) {
            m[croakOfFrogs[i]].push_back(i);
        }
        int req = m['c'].size();
        for(auto x : m) {
            if((int)x.second.size() != req)
                return -1;
        }
        
        for(int i = 0; i < req; i++) {
            if(m['c'][i] > m['r'][i] or m['r'][i] > m['o'][i] or m['o'][i] > m['a'][i] or m['a'][i] > m['k'][i])
                return -1;
        }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = -1;
        for(int i = 0; i < req; i++) {
            if(pq.empty()) {
                pq.push(m['k'][i]);
            }
            else {
                if(pq.top() > m['c'][i]) {
                    pq.push(m['k'][i]);
                }
                else {
                    pq.pop();
                    pq.push(m['k'][i]);
                }
            }
            ans = max(ans,(int)pq.size());
        }
        return ans;
    }
};