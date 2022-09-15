class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if((int)changed.size() % 2 != 0) {
            return {};
        }
        vector<int> c(100001,0);
        int maxi = -1;
        for (auto x : changed) {
            c[x]++;
            maxi = max(maxi,x);
        }
        vector<int> ans;
        for (int i = maxi; i > 0; i--) {
            if(c[i] == 0)
                continue;
            if(i%2 != 0)
                return {};
            int mini = min(c[i],c[i/2]);
            for(int j = 0; j < mini; j++) {
                ans.push_back(i/2);
            }
            c[i] -= mini;
            c[i/2] -= mini;
            if(c[i] != 0) {
                return {};
            }
        }
        if(c[0] % 2 != 0) {
            return {};
        }
        for(int i = 0; i < c[0]/2; i++) {
            ans.push_back(0);
        }
        return ans;
    }
};