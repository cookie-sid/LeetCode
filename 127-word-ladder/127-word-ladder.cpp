class Solution {
public:
    
    int checkdiff(string &a, string &b) {
        int diff = 0;
        for(int i = 0; i < a.length(); i++) {
            if(a[i] != b[i])
                diff++;
        }
        return diff;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string> q;
        
        map<string,bool> checked;
        bool poss = false;
        for(int i = 0; i < wordList.size(); i++) {
            if(wordList[i] == endWord)
                poss = true;
            if(checkdiff(beginWord, wordList[i]) == 1) {
                if(wordList[i] == endWord)
                    return 2;
                q.push(wordList[i]);
                checked[wordList[i]] = true;
            }
        }
        if(!poss)
            return 0;
        checked[beginWord] = true;
        
        int itr = 1;
        while(!q.empty()) {
            itr++;
            int currSize = q.size();
            while(currSize > 0) {
                string curr = q.front();
                cout<<curr<<" ";
                
                checked[curr] = true;
                q.pop();
                for(auto x : wordList) {
                    if(checkdiff(x,curr) == 1 and !checked[x]) {
                        q.push(x);
                        checked[x] = true;
                        if(x == endWord)
                            return itr + 1;
                    }
                }
                currSize--;
            }
            cout<<endl;
        }
        
        return 0;
        
    }
};