class Solution {
public:
    
    void fill(string &s, priority_queue<pair<int,char>> &pq) {
        int empty = 0;
        while(!pq.empty()) {
            char c = pq.top().second;
            int times = pq.top().first;
            int newEmpty = -1;
            for(int i = empty; i < s.length() + 2 and times > 0; i+=2) {
                if(i >= s.length())
                    i = 1;
                s[i] = c;
                times--;
                newEmpty = i;
            }
            pq.pop();
            empty = newEmpty + 2;
            if(empty >= s.length())
                empty = 1;
        }
    }
    
    string reorganizeString(string s) {
        vector<int> ct(26);
        int greatest = -1, n = s.length();
        string ans = "";
        priority_queue<pair<int,char>> pq;
        for(int i = 0; i < s.length(); i++) {
            ct[s[i] - 'a']++;
            if(ct[s[i] - 'a'] > ceil((double)n/2)) {
                return "";
            }
            ans += " ";
        }
        
        for(int i = 0; i < 26; i++) {
            if(ct[i] == 0) {
                continue;
            }
            pq.push(make_pair(ct[i],'a' + i));
        }
        
        fill(ans,pq);
        return ans;
    }
};