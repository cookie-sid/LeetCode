class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        vector<vector<int>> indices(k+1);
        int maxiSize = 1e9;
        map<int,int> m;
        for(int i = 1; i <= k; i++) {
            m[i] = 0;
        }
        vector<int> maxPoss(k+1);
        map<int,int> ct;
        int p = 0;
        for(int i = 0; i < rolls.size(); i++) {
            if(m[rolls[i]] == 0) {
                maxPoss[rolls[i]] = 1;
                m[rolls[i]]++;
                ct[1]++;
                if(ct[1] == k) {
                    p = 1;
                }
            }
            else {
                if(p + 1 > maxPoss[rolls[i]]) {
                    ct[p+1]++;
                } 
                maxPoss[rolls[i]] = p + 1;
                m[rolls[i]]++;
                if(ct[p+1] == k) {
                    p = p + 1;
                }
            }
        }
        
        int mini = 1e9;
        for(int i = 1; i <= k; i++) {
            mini = min(mini,maxPoss[i]);
        }
        return mini + 1;
    }
};