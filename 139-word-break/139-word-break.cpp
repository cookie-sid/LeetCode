class Solution {
public:
    
    bool poss(string s, int ind, int n, map<string,bool> &wordDict, int maxWordLength, vector<int> &dp) {
        if(ind == n) {
            dp[ind] = 1;
            return true;
        }
        if(dp[ind] >= 0) {
            return dp[ind] == 1;
        }
        bool ans = false;
        string curr = "";
        for(int i = ind; i < n and !ans; i++) {
            curr += s[i];
            if(curr.length() > maxWordLength) {
                break;
            }
            if(wordDict[curr]) {
                ans = ans or poss(s,i + 1,n,wordDict,maxWordLength,dp); 
            }
        }
        dp[ind] = ans ? 1 : 0;
        return ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,bool> m;
        int maxi = -1, n = s.length();
        vector<int> dp(n + 1,-1);
        for(auto x : wordDict) {
            m[x] = true;
            maxi = max(maxi,(int)x.length());
        }
        return poss(s,0,n,m,maxi,dp);
    }
};