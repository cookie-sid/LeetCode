class Trie {
    public:
        Trie *ch[26] = {};
        int count = 0;
};

class Solution {
public:
    
    void insert(string &s, Trie* t) {
        for(int i = 0; i < s.length(); i++) {
            if(!t -> ch[s[i] - 'a']) {
                t -> ch[s[i] - 'a'] = new Trie();
            }
            t = t -> ch[s[i] - 'a'];
            t -> count += 1;
            // cout<<s[i]<<" "<<t->count<<endl;
        }
    }
    
    int getRes(string &s, Trie* t, int ind) {
        int ans = 0;
        for(int i = ind; i < s.length(); i++) {
            ans += t -> ch[s[i] - 'a'] -> count;
            t = t -> ch[s[i] - 'a'];
        }
        return ans;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *t = new Trie();
        for(int i = 0; i < words.size(); i++) {
            insert(words[i],t);
        }
        vector<int> ans;
        for(int i = 0; i < words.size(); i++) {
            ans.push_back(getRes(words[i],t,0));
        }
        return ans;
    }
};