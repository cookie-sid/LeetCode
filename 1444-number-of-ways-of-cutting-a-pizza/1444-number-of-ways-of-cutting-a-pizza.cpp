class Solution {
public:
    
    int getSum(vector<vector<int>> &p, int a, int b, int x, int y) {
        if(a > 0 and b > 0) {
            return p[x][y] + p[a-1][b-1] - p[x][b-1] - p[a-1][y];
        }
        else {
            if(a == 0) {
                if(b == 0) {
                    return p[x][y];
                }
                else {
                    return p[x][y] - p[x][b-1];
                }
            }
            else {
                if(b == 0) {
                    return p[x][y] - p[a-1][y];
                }
            }
        }
        return 0;
    }
    
    bool cutAt(vector<vector<int>> &p, map<pair<pair<int,int>,int>,int> &m, int starti, int startj, int maxi, int maxj, int k) {
        int ans = 0;
        int mod = 1e9 + 7;
        auto paired = make_pair(make_pair(starti,startj),k);
        // cout<<starti<<" "<<startj<<" "<<k<<endl;
        if(m.find(paired) != m.end()) {
            return m[paired];
        }
        int currSec = getSum(p,starti,startj,maxi-1,maxj-1);
        if(k == 1) {
            if(currSec > 0) {
                m[paired] = 1;
                return true;
            }
            m[paired] = 0;
            return false;
        }
        for(int i = starti; i < maxi - 1; i++) {
            int val = getSum(p,starti,startj,i,maxj-1);
            if(currSec - getSum(p,starti,startj,i,maxj-1) > 0 and val > 0) {
                if(cutAt(p,m,i+1,startj,maxi,maxj,k-1)) {
                    ans += m[make_pair(make_pair(i+1,startj),k-1)];
                    ans %= mod;
                }
            }
        }
        
        for(int i = startj; i < maxj - 1; i++) {
            int val = getSum(p,starti,startj,maxi-1,i);
            if(currSec - getSum(p,starti,startj,maxi-1,i) > 0 and val > 0) {
                if(cutAt(p,m,starti,i+1,maxi,maxj,k-1)) {
                    ans += m[make_pair(make_pair(starti,i+1),k-1)];
                    ans %= mod;
                }
            }
        }
        m[paired] = ans;
        return m[paired] != 0;
    }
    
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size(), m = pizza[0].size();
        vector<vector<int>> p(n, vector<int> (m,0)); 
        for(int i = 0; i < n; i++) { 
            for(int j = 0; j < m; j++) {
                p[i][j] = (pizza[i][j] == 'A');
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                p[i][j] += p[i][j-1];
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                p[j][i] += p[j-1][i];
            }
        }
        map<pair<pair<int,int>,int>,int> mp;
        cutAt(p,mp,0,0,n,m,k);
        return mp[{{0,0},k}];
    }
};