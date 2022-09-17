class Solution {
public:
    
    void letterPiv(string &s, int id, map<pair<int,int>,int> &ans, map<string,int> &ind, int mode, int minLength) {
        int n = s.length(), left = n - 1, right = 0;
        while(left >= right) {
            int piv = left;
            bool poss = true;
            for(int i = 1; piv + i < n; i++) {
                if(s[piv - i] != s[piv + i]) {
                    poss = false;
                    break;
                }
            }
            if(!poss) {
                left -= 1;
                right += 1;
                continue;
            }
            string tmp = s.substr(0,piv-right);
            if(tmp.length() < minLength) 
                break;
            if(mode == 2) {
                if(ind.find(tmp) != ind.end() and id != ind[tmp]) {
                    ans[{ind[tmp],id}] = 1;
                }
            }
            else {
                reverse(tmp.begin(),tmp.end());
                if(ind.find(tmp) != ind.end() and id != ind[tmp]) {
                    ans[{id,ind[tmp]}] = 1;
                }
            }
            left -= 1;
            right += 1;
        }
    }
    
    void spacePiv(string &s, int id, map<pair<int,int>,int> &ans, map<string,int> &ind, int mode, int minLength) {
        int n = s.length(), left = n, right = 0;
        while(left >= right) {
            int piv = left;
            int num = 1;
            bool poss = true;
            for(int i = piv; piv + num - 1 < n; i++) {
                if(s[piv-num] != s[i]) {
                    poss = false;
                    break;
                }
                num += 1;
            }
            if(!poss) {
                left -= 1;
                right += 1;
                continue;
            }
            string tmp = s.substr(0,piv - num + 1);
            if(tmp.length() < minLength) 
                break;
            if(mode == 2) {
                // cout<<ind[tmp]<<" "<<id<<" "<<tmp<<endl;
                if(ind.find(tmp) != ind.end() and id != ind[tmp]) {
                    ans[{ind[tmp],id}] = 1;
                }
            }
            else {
                reverse(tmp.begin(),tmp.end());
                if(ind.find(tmp) != ind.end() and id != ind[tmp]) {
                    ans[{id,ind[tmp]}] = 1;
                }
            }
            left -= 1;
            right += 1;
        }
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        map<string,set<int>> needs;
        map<string,int> ind;
        map<pair<int,int>,int> ans;
        int minLength = 1e9;
        for(int i = 0; i < words.size(); i++) {
            ind[words[i]] = i;
            minLength = min(minLength,(int)words[i].length());
        }
        for(int i = 0; i < words.size(); i++) {
            string x = words[i];
            string revX = words[i];
            reverse(revX.begin(),revX.end());
            letterPiv(x,i,ans,ind,1,minLength);
            spacePiv(x,i,ans,ind,1,minLength);
            letterPiv(revX,i,ans,ind,2,minLength);
            spacePiv(revX,i,ans,ind,2,minLength);
        }
        vector<vector<int>> res;
        for(auto x : ans) {
            res.push_back({x.first.first,x.first.second});
        }
        return res;
    }
};