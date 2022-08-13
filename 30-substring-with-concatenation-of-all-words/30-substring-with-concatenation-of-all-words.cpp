class Solution {
public:
    
    bool poss(string &s, int start, int end, unordered_map<string,int> &used, int &maxlen) {
        if(start > end) {
            return true;
        }
        bool ans = false;
        string curr = "";
        for(int i = start; i <= end; i++) {
            curr += s[i];
            if(used[curr] > 0) {
                used[curr] -= 1;
                ans = ans or poss(s,i + 1,end,used,maxlen);
                used[curr] += 1;
            }
            if(curr.length() == maxlen)
                break;
        }
        return ans;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> m;
        vector<int> total(26), pres(26);
        int t = 0, maxlen = -1;
        for(auto x : words) {
            m[x] += 1;
            t += x.length();
            maxlen = max(maxlen,(int)x.length());
            for(auto c : x) {
                total[c - 'a']++;
            }
        }
        vector<int> ans;
        for(int i = 0; i < s.length(); i++) {
            pres[s[i] - 'a']++;
            if(i >= t - 1) {
                bool allsame = true;
                for(int j = 0; j < 26 and allsame; j++) {
                    if(pres[j] != total[j]) {
                        allsame = false;
                    }
                }
                if(allsame) {
                    if(poss(s,i-t+1,i,m,maxlen)) {
                        ans.push_back(i-t+1);
                    }
                }
                pres[s[i-t+1] - 'a']--;
            }
        } 
        return ans;
    }
};