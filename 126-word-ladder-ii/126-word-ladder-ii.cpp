class Solution {
public:
    
    bool check(string a, string b) {
        int diffs = 0;
        for(int i= 0; i < a.length(); i++) {
            if(a[i] != b[i]) {
                diffs++;
            }
        }
        return diffs == 1;
    }
    
    void gen(unordered_map<string,vector<string>> &p, vector<vector<string>> &ans, vector<string> &c, string curr) {
        if(p[curr][0] == curr) {
            c.push_back(curr);
            ans.push_back(c);
            c.pop_back();
            return;
        }
        c.push_back(curr);
        for(auto x : p[curr]) {
            gen(p,ans,c,x);
        }
        c.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> m;
        bool found = false;
        unordered_map<string,bool> vis;
        vector<vector<string>> ans; 
        unordered_map<string,vector<string>> mp;
        for(int i = 0; i < wordList.size(); i++) {
            if(endWord == wordList[i]) {
                found = true;
            }
            vis[wordList[i]] = false;
            for(int j = i + 1; j < wordList.size(); j++) {
                if(check(wordList[i],wordList[j])) {
                    m[wordList[i]].push_back(wordList[j]);
                    m[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        
        if(!found)
            return ans;
        
        
        queue<string> q;
        q.push(endWord);
        bool gotIt = false;
        mp[endWord].push_back(endWord);
        unordered_map<string,int> dpt;
        dpt[endWord] = 1;
        vector<string> res;
        while(!q.empty() and !gotIt) {
            int cSize = q.size();
            for(int i = 0; i < cSize; i++) {
                string top = q.front();
                if(vis[top]) {
                    q.pop();
                    continue;
                }
                vis[top] = true;
                if(check(top,beginWord)) {
                    gotIt = true;
                    res.push_back(top);
                    q.pop();
                    continue;
                }
                for(auto x : m[top]) {
                    if(!vis[x] and ((dpt[x] == 0) or (dpt[x] > dpt[top]))) {
                        if(dpt[x] == 0) {
                            dpt[x] = dpt[top] + 1;
                        }
                        q.push(x);
                        mp[x].push_back(top);
                    }
                }
                q.pop();
            }
            if(gotIt) {
                break;
            }
        }
        
        for(auto x : res) {
            vector<string> tmp;
            tmp.push_back(beginWord);
            gen(mp,ans,tmp,x);
        }
        cout<<endl;
        return ans;
        
    }
};