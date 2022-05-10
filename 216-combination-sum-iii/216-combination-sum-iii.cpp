class Solution {
public:
    
    void recurr(int currSum, vector<int> &curr_arr, set<vector<int>> &ans, int &k, int&n, int ctr) {
        if(curr_arr.size() == k and currSum == n) {
            // set<int> checker; 
            // for(auto x : curr_arr) {
            //     if(checker.count(x) == 1) {
            //         return;
            //     }
            //     checker.insert(x);
            // }
            vector<int> temp = curr_arr;
            ans.insert(curr_arr);
            return;
        }
        if(curr_arr.size() == k and currSum != n) {
            return;
        }
        for(int i = ctr; i <= 9; i++) {
            curr_arr.push_back(i);
            recurr(currSum + i, curr_arr, ans, k, n, i+1);
            curr_arr.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        set<vector<int>> ans;
        vector<int> curr;
        recurr(0,curr,ans,k,n,1);
        vector<vector<int>> ans_fin;
        for(auto x : ans) {
            ans_fin.push_back(x);
        }
        return ans_fin;
    }
};