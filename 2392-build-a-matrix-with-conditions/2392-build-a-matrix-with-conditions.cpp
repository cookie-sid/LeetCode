class Solution {
public:
    
    int getPlaceAbove(int num, int k, vector<vector<int>> &above, map<int,int> &placed, unordered_set<int> &st, vector<bool> &taken) {
        if(placed.find(num) != placed.end()) {
            return placed[num];
        }
        int h = 0;
        while(h < k and taken[h]) {
            h += 1;
        }
        st.insert(num);
        for(auto x : above[num]) {
            if(st.count(x)) {
                placed[num] = -1;
                return placed[num];
            }
            if(placed.find(x) == placed.end()) {
                st.insert(x);
                getPlaceAbove(x,k,above,placed,st,taken);
                st.erase(x);
            }
            int p = placed[x] + 1;
            while(p < k and taken[p]) {
                p += 1;
            }
            if(p == k) {
                placed[num] = -1;
                return placed[num]; 
            }
            h = max(h,p);
        }
        st.erase(num);
        taken[h] = true;
        placed[num] = h;
        return placed[num];
    }
    int getPlaceLeft(int num, int k, vector<vector<int>> &left, map<int,int> &placed, unordered_set<int> &st, vector<bool> &taken) {
        if(placed.find(num) != placed.end()) {
            return placed[num];
        }
        int h = 0;
        while(h < k and taken[h]) {
            h += 1;
        }
        st.insert(num);
        for(auto x : left[num]) {
            if(st.count(x)) {
                placed[num] = k;
                return placed[num];
            }
            if(placed.find(x) == placed.end()) {
                st.insert(x);
                getPlaceAbove(x,k,left,placed,st,taken);
                st.erase(x);
            }
            int p = placed[x] + 1;
            while(p < k and taken[p]) {
                p += 1;
            }
            if(p == k) {
                placed[num] = -1;
                return placed[num]; 
            }
            h = max(h,p);
        }
        st.erase(num);
        placed[num] = h;
        return placed[num];
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> aboveThis(k+1);
        vector<vector<int>> leftThis(k+1);
        for(auto x : rowConditions) {
            aboveThis[x[1]].push_back(x[0]);
        }
        for(auto x : colConditions) {
            leftThis[x[1]].push_back(x[0]);
        }
        unordered_set<int> st;
        map<int,int> dp;
        map<int,pair<int,int>> m;
        vector<vector<int>> grid(k, vector<int>(k));
        vector<bool> taken(k);
        for(int i = 1; i <= k; i++) {
            int p = getPlaceAbove(i,k,aboveThis,dp,st,taken);
            m[i].second = p;
            cout<<p<<endl;
        }
        cout<<endl;
        st.clear();
        dp.clear();
        for(int i = 0; i < k; i++) {
            taken[i] = false;
        }
        for(int i = 1; i <= k; i++) {
            int p = getPlaceLeft(i,k,leftThis,dp,st,taken);
            m[i].first = p;
            cout<<p<<endl;
        }
        for(auto x : m) {
            int r = x.second.first;
            int c = x.second.second;
            if(r < 0 or c < 0 or r >= k or c >= k) {
                return {};
            }
            grid[c][r] = x.first;
        }
        return grid;
    }
};