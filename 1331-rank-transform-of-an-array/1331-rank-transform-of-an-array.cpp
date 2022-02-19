class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> s;
        for(auto x : arr) {
            s.insert(x);
        }
        map<int,int> ranks;
        int rank = 1;
        for(auto x : s) {
            ranks[x] = rank++;
        }
        vector<int> ans(arr.size());
        for(int i = 0; i < arr.size(); i++) {
            ans[i] = ranks[arr[i]];
        }
        return ans;
    }
};