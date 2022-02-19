class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int> m;
        int rank = 1;
        for(auto x : temp) {
            if(m[x] == 0)
                m[x] = rank++;
        }
        vector<int> ans(arr.size());
        for(int i = 0; i < ans.size(); i++) {
            ans[i] = m[arr[i]];
        }
        return ans;
    }
};