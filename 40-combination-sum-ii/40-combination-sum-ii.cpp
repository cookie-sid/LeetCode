class Solution {
public:
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int,set<vector<int>>> m;
        map<int,int> freq;
        for(auto x : candidates) {
            freq[x]++;
        }
        vector<vector<int>> ans;
        for(int i = 1; i <= target; i++) {
            if(freq[i] > 0) {
                m[i].insert({i});
            }
            if(i == 1) {
                if(freq[i] >= 1) {
                    m[i].insert({1});
                }
            }
            else {
                
                for(int j = 1; j <= i/2; j++){
                    set<vector<int>> curr = m[j];
                    if(m[i-j].size() != 0) {
                        for(auto x : curr) {
                            vector<int> inter = x;
                            for(auto y : m[i-j]) {
                                for(auto z : y) {
                                    inter.push_back(z);
                                }
                                bool pos = true;
                                map<int,int> temp;
                                for(auto z : inter) {
                                    temp[z]++;
                                    if(temp[z] > freq[z]) {
                                        pos = false;
                                        break;
                                    }
                                }
                                if(pos) {
                                    sort(inter.begin(),inter.end());
                                    m[i].insert(inter);
                                }
                                inter = x;
                            }
                        }
                    }
                }
            }
        }
        vector<vector<int>> bruh;
        for(auto x : m[target]) {
            bruh.push_back(x);
        }
        return bruh;
    }
};