class Solution {
public:
    
    int diff(string s, string t) {
        int ans = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != t[i])
                ans += 1;
        }
        return ans;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        map<string,int> m;
        map<string,bool> taken;
        for(auto x : bank) {
            m[x] = 1e9;
            taken[x] = false;
        }
        if(m.find(end) == m.end()) {
            return -1;
        }
        queue<string> q;
        q.push(start);
        int steps = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                string top = q.front();
                if(top == end) {
                    return steps;
                }
                for(auto x: bank) {
                    if(!taken[x] and diff(x,top) == 1) {
                        q.push(x);
                    }
                }
                q.pop();
            }
            steps += 1;
        }
        return -1;
    }
};